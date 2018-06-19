/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:16:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/19 21:43:42 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "rtv1.h"
#include "draw.h"

static void	draw_pixel(t_data *data, t_camera cam, t_vec vp, t_point crd)
{
	t_inter	inter;
	t_vec	ray;

	if (data->aa <= 1)
	{
		ray = compute_ray(vp, cam);
		inter.min_dist = 0;
		if (hit(data, cam, ray, &inter))
			pt_to_pixelbuf(crd, data->img, get_px_color(data, cam, inter));
		else
			pt_to_pixelbuf(crd, data->img, 0xFF000000);
	}
	else if (data->aa > 1)
		pt_to_pixelbuf(crd, data->img, anti_aliasing(data, vp));
}

static void	*draw_thread(void *thr)
{
	t_camera	cam;
	t_point		crd;
	t_vec		vp;
	int			i;
	int			ymax;

	cam = g_data->cams[g_data->i];
	vp = cam.vp_up_left;
	i = *((int *) thr);
	crd.y = (i * WIN_H / NB_THR) - 1;
	ymax = (i + 1) * WIN_H / NB_THR;
	while (++crd.y < ymax)
	{
		crd.x = 0;
		while (++crd.x < WIN_W)
		{
			vp.x = cam.vp_up_left.x + (double)crd.x;
			vp.y = cam.vp_up_left.y - (double)crd.y;
			draw_pixel(g_data, cam, vp, crd);
		}
	}
	pthread_exit(NULL);
}

void		draw_image(t_data *data)
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
	put_pixelbuf_to_widget(g_data->img, NULL);
	gtk_widget_show_all(g_data->win);
}
