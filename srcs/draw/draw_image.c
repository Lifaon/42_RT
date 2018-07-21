/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:16:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/21 08:55:28 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "rtv1.h"
#include "draw.h"

static t_color	draw_pixel(t_data *data, t_vec vp)
{
	t_inter		inter;
	t_vec		ray;
	t_color		ret;

	inter.in_object = 0;
	if (data->aa <= 1)
	{
		inter.depth = 0;
		ret.c = 0xFF000000;
		ray = compute_ray(vp);
		inter.min_dist = 0.01;
		if (first_hit(data, ray, &inter))
			ret = get_px_color(data, ray, inter);
		return (ret);
	}
	else
		return (anti_aliasing(data, vp));
}

static void		*draw_thread(void *thr)
{
	t_point		crd;
	t_vec		vp;
	int			i;
	int			ymax;

	vp = g_data->cam.vp_up_left;
	i = *((int *) thr);
	crd.y = (i * WIN_H / NB_THR) - 1;
	ymax = (i + 1) * WIN_H / NB_THR;
	while (++crd.y < ymax)
	{
		crd.x = -1;
		vp.y = g_data->cam.vp_up_left.y - (double)crd.y;
		while (++crd.x < WIN_W)
		{
			vp.x = g_data->cam.vp_up_left.x + (double)crd.x;
			pt_to_pixelbuf(crd, g_data->img, draw_pixel(g_data, vp).c);
		}
	}
	pthread_exit(NULL);
}

void			draw_image(void)
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
		if (pthread_create(&thread[i], NULL, &draw_thread, &arr[i]))
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
