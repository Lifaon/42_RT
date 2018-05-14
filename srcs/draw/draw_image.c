/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:16:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/14 20:19:34 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	draw_pixel(t_data *data, t_vec ray, t_point crd)
{
	t_inter	inter;
	double	tmp;
	int		i;
	int		object_index;

	tmp = INFINITY;
	i = -1;
	while (++i < data->nb_objects)
		if (data->objs[i].intersect(data->objs[i], ray, &inter) && \
			inter.t < tmp)
		{
			tmp = inter.t;
			object_index = i;
		}
	if (tmp < INFINITY)
	{
		inter.t = tmp;
		inter.ip = vec_add(data->cams[data->i].pos, vec_multiply(ray, inter.t));
		pt_to_tex(crd, data->tex, shadow_ray(data, inter, object_index));
	}
	else
		pt_to_tex(crd, data->tex,  0);
}

void		draw_image(t_data *data)
{
	t_point		crd;
	t_vec		ray;

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
