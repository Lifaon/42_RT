/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edge_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:19:37 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/04 19:49:42 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int	draw_edge_pixel(t_vec vp)
{
	t_inter	inter;
	t_vec	ray;
	int		t;

	ray = compute_ray(vp);
	inter.min_dist = 0.01;
	if (!(first_hit(g_data, ray, &inter)))
		return (0xFFFFFFFF);
	t = 0;
	if (g_data->objs[inter.obj_i].obj_type != PLANE)
	{
		inter.normal = g_data->objs[inter.obj_i].get_normal(\
			g_data->objs[inter.obj_i], inter);
		if (dot_product(ray, inter.normal) <= 0)
			t = 1;
	}
	return (inter.obj_i * 2 + t);
}

static void	*draw_edge_thread(void *thr)
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
		vp.y = g_data->cam.vp_up_left.y - (double)crd.y;
		crd.x = -1;
		while (++crd.x < WIN_W)
		{
			vp.x = g_data->cam.vp_up_left.x + (double)crd.x;
			pt_to_pixelbuf(crd, g_data->img, draw_edge_pixel(vp));
		}
	}
	pthread_exit(NULL);
}

static void	fill_edges(float *edges, uint32_t *pxl, t_point size)
{
	t_point	crd;
	int		i;

	i = 0;
	crd.y = -1;
	while (++crd.y < size.y)
	{
		crd.x = -1;
		while (++crd.x < size.x)
		{
			if ((crd.x == 0 || (pxl[i] == pxl[i - 1])) \
				&& (crd.y == 0 || (pxl[i] == pxl[i - size.x])) \
				&& (crd.x == size.x - 1 || (pxl[i] == pxl[i + 1])) \
				&& (crd.y == size.y - 1 || (pxl[i] == pxl[i + size.x])))
				edges[i] = 0.;
			else
				edges[i] = 1.;
			++i;
		}
	}
}

void		draw_edge_image(float *edges, uint32_t *pxl, t_point size)
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
		if (pthread_create(&thread[i], NULL, &draw_edge_thread, &arr[i]))
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
	fill_edges(edges, g_data->img->pxl, size);
}
