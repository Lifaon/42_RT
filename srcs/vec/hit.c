/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:17:41 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/24 22:03:13 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

static int	get_color_at_ip(t_obj obj, t_vec ray, t_inter *inter)
{
	t_color ret;

	if (obj.tex)
		ret.c = uv_mapping(obj, ray, inter);
	else if (obj.color_type == COLOR_CHECKERBOARD)
		ret = checkerboard(obj, ray, inter);
	else if (obj.color_type == COLOR_RAINBOW)
		ret = rainbow(obj, ray, inter);
	else
		ret = obj.color;
	if (obj.perl_type != PERLIN_NONE)
		ret = ft_perlin(obj, ret, inter);
	if (obj.tex && obj.tex_trans)
		inter->trans_at_ip = 1 - (ret.argb.a / 255.);
	else
		inter->trans_at_ip = obj.trans;
	return (ret.c);
}

int			first_hit(t_data *data, t_vec ray, t_inter *inter)
{
	double	t;
	int		i;

	t = INFINITY;
	inter->origin = data->cam.pos;
	i = -1;
	while (++i < data->nb_objects)
	{
		inter->oc = data->objs[i].oc;
		if (data->objs[i].enabled && \
			data->objs[i].intersect(data->objs[i], ray, inter) && inter->t < t)
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

int			other_hit(t_data *data, t_vec ray, t_inter *inter)
{
	double	t;
	int		i;

	t = INFINITY;
	i = -1;
	while (++i < data->nb_objects)
	{
		inter->oc = vec_substract(inter->origin, data->objs[i].pos);
		if (data->objs[i].enabled && \
			data->objs[i].intersect(data->objs[i], ray, inter) && inter->t < t)
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
