/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixelated_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:42:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/25 22:54:33 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void		draw_pixels(t_data *data, t_vec vp, t_point crd)
{
	t_inter		inter;
	t_vec		ray;
	t_point		px;
	t_color		color;
	t_point		crdd;

	ray = compute_ray(vp);
	inter.depth = 0;
	inter.in_object = 0;
	if (first_hit(data, ray, &inter))
		color = get_px_color(data, ray, inter);
	else
		color.c = 0xFF000000;
	px.y = -1;
	while (++px.y < g_data->px)
	{
		px.x = -1;
		while (++px.x < g_data->px)
		{
			if (g_data->clust_i == CLUST_CLIENT)
			{
				if (crd.x + px.x >= 0 && crd.x + px.x < WIN_W && \
						crd.y + px.y >= 0 && crd.y + px.y < WIN_H)
					g_data->cimg[crd.x + px.x + (crd.y + px.y) * WIN_W] = color.c;
			}
			else
				pt_to_pixelbuf(\
			(t_point){crd.x + px.x, crd.y + px.y}, data->img, color.c);
		}
	}
}

static void		*draw_pixelated_thread(void *thr)
{
	t_point		crd;
	t_vec		vp;
	int			i;
	int			ymax;
	int			xmax;

	i = *((int *)thr);
	vp = g_data->cam.vp_up_left;
	crd.y = (i * WIN_H / NB_THR) - 1;
	ymax = (i + 1) * WIN_H / NB_THR;
	xmax = (WIN_W / (g_data->nb_client + 1)) * (g_data->x + 1) + 0.5;
	while (crd.y < ymax)
	{
		crd.x = ((WIN_W / (g_data->nb_client + 1)) * g_data->x);
		vp.y = g_data->cam.vp_up_left.y - ((g_data->px * 0.5) + (double)crd.y);
		while (crd.x < xmax + 1)
		{
			vp.x = g_data->cam.vp_up_left.x +
			((g_data->px * 0.5) + (double)crd.x);
			draw_pixels(g_data, vp, crd);
			crd.x += g_data->px;
		}
		crd.y += g_data->px;
	}
	pthread_exit(NULL);
}

void			draw_pixelated_image(t_data *data)
{
	pthread_t	thread[NB_THR];
	int			arr[NB_THR];
	int			i;
	int			j;

	if (data->draw == 0)
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
			exit_all(data);
		}
	}
	i = -1;
	while (++i < NB_THR)
		pthread_join(thread[i], NULL);
}
