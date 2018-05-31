/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:16:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/31 19:56:16 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	draw_pixel(t_data *data, t_vec ray, t_point crd)
{
	t_inter	inter;
	double	t;
	int		i;
	int		obj_i;

	t = INFINITY;
	i = -1;
	inter.min_dist = 0;
	while (++i < data->nb_objects)
	{
		inter.oc = data->objs[i].oc;
		if (data->objs[i].intersect(data->objs[i], ray, &inter) && inter.t < t)
		{
			t = inter.t;
			obj_i = i;
		}
	}
	if (t < INFINITY)
	{
		inter.t = t;
		inter.ip = vec_add(data->cams[data->i].pos, vec_multiply(ray, inter.t));
		inter.normal = get_normal(ray, data->objs[obj_i], inter);
	}
	pt_to_tex(crd, data->tex, \
		t < INFINITY ? get_px_color(data, inter, obj_i) : 0);
}

void		draw_image(t_data *data)
{
	t_point	crd;
	t_vec	ray;

	crd = (t_point){0, 0};
	ray.z = data->cams[data->i].vp_up_left.z;
	while (crd.x < WIN_W)
	{
		ray.y = data->cams[data->i].vp_up_left.y - (double)crd.y;
		ray.x = data->cams[data->i].vp_up_left.x + (double)crd.x;
		draw_pixel(data, vec_normalize(ray), crd);
		crd = pt_ypluseg(crd, 0, WIN_H);
	}
	put_tex_to_win(data->tex, data->win->ren);
}
