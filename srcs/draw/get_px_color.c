/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_px_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 05:22:06 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/21 00:07:12 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int		light_path_is_blocked(t_data *data, t_inter inter, t_vec *light)
{
	int		i;
	double	len;

	i = -1;
	len = get_length(*light);
	*light = vec_normalize(*light);
	inter.min_dist = 0.01;
	while (++i < data->nb_objects)
	{
		inter.oc = vec_substract(inter.ip, data->objs[i].pos);
		if (data->objs[i].intersect(data->objs[i], *light, &inter) && \
			inter.t < len)
			return (1);
	}
	return (0);
}

static t_color	shade(t_data *data, t_inter *inter, t_light light)
{
	t_color	ret;
	t_vec	light_vec;
	double	dot;

	inter->origin = inter->ip;
	ret = ambient_shading(data->objs[inter->obj_i], light);
	light_vec = vec_substract(light.pos, inter->ip);
	if (light_path_is_blocked(data, *inter, &light_vec))
		return (ret);
	dot = dot_product(light_vec, inter->normal);
	if (dot <= 0)
		return (ret);
	ret = add_colors(ret, diffuse_shading(data->objs[inter->obj_i], dot));
	inter->spec = add_colors(inter->spec, specular_shading(\
		data->objs[inter->obj_i], light_vec, *inter));
	return (ret);
}

int				get_px_color(t_data *data, t_inter inter)
{
	t_color		ret;
	t_added		added;
	int			i;

	if (!data->nb_lights || !data->nb_lights_on)
		return (col_multiply(data->objs[inter.obj_i].color, 0.3).c);
	added = (t_added){0, 0, 0, 0};
	i = -1;
	inter.spec.c = 0;
	while (++i < data->nb_lights)
	{
		if (data->lights[i].disabled)
			continue ;
		ret = shade(data, &inter, data->lights[i]);
		added.r += ret.argb.r;
		added.g += ret.argb.g;
		added.b += ret.argb.b;
		added.a += ret.argb.a;
	}
	ret.argb.r = added.r / data->nb_lights_on;
	ret.argb.g = added.g / data->nb_lights_on;
	ret.argb.b = added.b / data->nb_lights_on;
	ret.argb.a = added.a / data->nb_lights_on;
	return (add_colors(ret, inter.spec).c);
}
