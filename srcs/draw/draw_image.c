/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:16:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/28 18:22:05 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "rtv1.h"
#include "draw.h"

t_color	draw_reflec(t_data *data, t_inter inter, t_vec ray, int rec, t_color ret)
{
	t_vec		r;
	t_vec		normal;
	t_vec		ip;
	double		t;
	int			i;
	int			obj_i_tmp;


	obj_i_tmp = inter.obj_i;
	i = 0;
	t = INFINITY;
	ip = inter.ip;
	inter.normal = data->objs[inter.obj_i].get_normal(data->objs[inter.obj_i], inter);
	normal = inter.normal;
	r = vec_normalize(vec_add(\
			vec_multiply(inter.normal, dot_product(inter.normal, ray) * -2.0),\
			ray));
	ip = vec_add(ip, vec_multiply(r, 0.3));
	while (i < data->nb_objects)
	{
		inter.oc = vec_substract(ip, data->objs[i].pos);
		if (data->objs[i].intersect(data->objs[i], r, &inter) && inter.t < t)
		{
			t = inter.t;
			inter.obj_i = i;
		}
		i++;
	}
	if (t < INFINITY)
	{
		inter.t = t;
		inter.ip = vec_add(ip, vec_multiply(r, inter.t));
		inter.normal = get_normal(r, data->objs[inter.obj_i], inter);
		ret = blend_colors(ret, col_multiply(get_px_color(data, inter), data->objs[obj_i_tmp].shin_pourcentage));
		if (data->objs[inter.obj_i].shiny && rec < 3)
			ret = draw_reflec(data, inter, r, ++rec, ret);
	}
	else
		ret = blend_colors(ret, (t_color){.c = 0xFF000000});
	return (ret);
}

static t_color	draw_pixel(t_data *data, t_vec vp, int rec)
{
	t_inter		inter;
	t_vec		ray;
	t_vec		r;
	t_color		ret;
	int			i;

	i = -1;
	if (data->aa <= 1)
	{
		ret.c = 0xFF000000;
		if (rec == 0)
			ray = compute_ray(vp);
		inter.min_dist = 0.01;
		if (hit(data, ray, &inter))
		{
			ret = get_px_color(data, inter);
			if (data->objs[inter.obj_i].shiny == 1)
				ret = draw_reflec(data, inter, ray, 0, ret);
		}
		return (ret);
	}
	else
		return (anti_aliasing(data, vp));
}

static void	*draw_thread(void *thr)
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
			pt_to_pixelbuf(crd, g_data->img, draw_pixel(g_data, vp, 0).c);
		}
	}
	pthread_exit(NULL);
}

void		draw_image(void)
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
