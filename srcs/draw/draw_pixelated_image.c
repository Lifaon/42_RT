/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixelated_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:42:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/27 00:52:23 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	draw_pixels(t_data *data, t_vec vp, t_point crd)
{
	t_inter	inter;
	t_vec	ray;
	t_point px;
	int		color;

	ray = compute_ray(vp);
	if (hit(data, ray, &inter))
		color = get_px_color(data, inter);
	else
		color = 0xFF000000;
	px.y = -1;
	while (++px.y < PX)
	{
		px.x = -1;
		while (++px.x < PX)
			pt_to_pixelbuf(\
				(t_point){crd.x + px.x, crd.y + px.y}, data->img, color);
	}
}

static void	*draw_pixelated_thread(void *thr)
{
	t_point		crd;
	t_vec		vp;
	int			i;
	int			ymax;

	i = *((int *) thr);
	vp = g_data->cam.vp_up_left;
	crd.y = (i * WIN_H / NB_THR) - 1;
	ymax = (i + 1) * WIN_H / NB_THR;
	while (crd.y < ymax)
	{
		crd.x = 0;
		vp.y = g_data->cam.vp_up_left.y - ((PX * 0.5) + (double)crd.y);
		while (crd.x < WIN_W)
		{
			vp.x = g_data->cam.vp_up_left.x + ((PX * 0.5) + (double)crd.x);
			draw_pixels(g_data, vp, crd);
			crd.x += PX;
		}
		crd.y += PX;
	}
	pthread_exit(NULL);
}

void		draw_pixelated_image(t_data *data)
{
	pthread_t	thread[NB_THR];
	int			arr[NB_THR];
	int			i;
	int			j;

	if (g_data->draw == 0)
		return ;
	i = -1;
	while (++i < NB_THR)
	{
		arr[i] = i;
		if (pthread_create(&thread[i], NULL, &draw_pixelated_thread, &arr[i]))
		{
			j = -1;
			while (++j < i)
				pthread_cancel(thread[j]);
			exit_all(g_data);
		}
	}
	i = -1;
	while (++i < NB_THR)
		pthread_join(thread[i], NULL);
}
