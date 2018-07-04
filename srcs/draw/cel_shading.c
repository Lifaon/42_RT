/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cel_shading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 03:38:24 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/04 06:19:15 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int	draw_grey_pixel(t_vec vp)
{
	t_inter	inter;
	t_vec	ray;
	int		i;
	int		t;
	int		ret;

	i = -1;
	ray = compute_ray(vp);
	inter.min_dist = 0.01;
	ret = first_hit(g_data, ray, &inter);
	if (g_data->objs[inter.obj_i].obj_type != PLANE)
		t = inter.t == inter.t1 ? inter.t < inter.t2 : inter.t < inter.t1;
	else
		t = 0;
	if (ret)
		return (inter.obj_i * 2 + t);
	return (0xFFFFFFFF);
}

static void	*draw_grey_thread(void *thr)
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
		crd.x = 0;
		while (++crd.x < WIN_W)
		{
			vp.x = g_data->cam.vp_up_left.x + (double)crd.x;
			vp.y = g_data->cam.vp_up_left.y - (double)crd.y;
			pt_to_pixelbuf(crd, g_data->img, draw_grey_pixel(vp));
		}
	}
	pthread_exit(NULL);
}

static void	draw_grey_image(void)
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
		if (pthread_create(&thread[i], NULL, &draw_grey_thread, &arr[i]))
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

void	fill_edges(float *edges, const uint32_t *pxl, const t_point size)
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
				edges[i] = 0;
			else
				edges[i] = 1;
			++i;
		}
	}
}

void	cel_shading(void)
{
	t_point	size;
	float	*edges;
	int		total_size;
	int		i;

	size.x = g_data->img->size.x;
	size.y = g_data->img->size.y;
	total_size = size.x * size.y;
	if (!(edges = (float *)malloc(sizeof(float) * total_size)))
		return ;
	draw_grey_image();
	fill_edges(edges, g_data->img->pxl, size);
	draw_image();
	i = -1;
	while (++i < total_size)
	{
		if (edges[i])
			g_data->img->pxl[i] = 0xFF000000;
	}
	free(edges);
}
