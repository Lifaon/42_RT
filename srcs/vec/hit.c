/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:17:41 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/03 19:48:35 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

static int	get_color_at_ip(t_obj obj, t_vec ray, t_inter *inter)
{
	if (obj.tex)
		return (uv_mapping(obj, ray, inter));
	return (obj.color.c);
}

int		first_hit(t_data *data, t_vec ray, t_inter *inter)
{
	double	t;
	int		i;

	t = INFINITY;
	inter->min_dist = 0.01;
	inter->origin = data->cam.pos;
	i = -1;
	while (++i < data->nb_objects)
	{
		inter->oc = data->objs[i].oc;
		if (data->objs[i].intersect(data->objs[i], ray, inter) && inter->t < t)
		{
			t = inter->t;
			inter->obj_i = i;
		}
	}
	if (t < INFINITY)
	{
		inter->t = t;
		inter->ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
		inter->normal = get_normal(ray, data->objs[inter->obj_i], *inter);
		inter->color.c = get_color_at_ip(data->objs[inter->obj_i], ray, inter);
		return (1);
	}
	return (0);
}

int		other_hit(t_data *data, t_vec ray, t_inter *inter)
{
	double	t;
	int		i;

	t = INFINITY;
	inter->min_dist = 0.01;
	i = -1;
	while (++i < data->nb_objects)
	{
		inter->oc = vec_substract(inter->origin, data->objs[i].pos);
		if (data->objs[i].intersect(data->objs[i], ray, inter) && inter->t < t)
		{
			t = inter->t;
			inter->obj_i = i;
		}
	}
	if (t < INFINITY)
	{
		inter->t = t;
		inter->ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
		inter->normal = get_normal(ray, data->objs[inter->obj_i], *inter);
		inter->color.c = get_color_at_ip(data->objs[inter->obj_i], ray, inter);
		return (1);
	}
	return (0);
}
