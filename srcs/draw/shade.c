/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 05:22:06 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/31 17:03:45 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		light_is_path_blocked(t_data *data, t_vec ip, t_vec light, double len)
{
	t_inter	it;
	int		i;

	it.min_dist = 0.1;
	i = -1;
	while (++i < data->nb_objects)
	{
		it.oc = vec_substract(ip, data->objs[i].pos);
		if (data->objs[i].intersect(data->objs[i], light, &it) && it.t < len)
			return (1);
	}
	return (0);
}

t_color	shade(t_data *data, t_inter *inter, int light_i, int index)
{
	t_color	ret;
	t_vec	light;
	double	len;
	double	dot;

	ret = ambient_shading(data, light_i, index);
	light = vec_substract(data->lights[light_i].pos, inter->ip);
	len = get_length(light);
	light = vec_normalize(light);
	if (light_is_path_blocked(data, inter->ip, light, len))
		return (ret);
	dot = dot_product(light, inter->normal);
	if (dot <= 0)
		return (ret);
	ret = add_colors(ret, diffuse_shading(data, dot, index));
	inter->spec = add_colors(inter->spec, \
		specular_shading(data, index, *inter, light));
	return (ret);
}

int		get_px_color(t_data *data, t_inter inter, int index)
{
	t_color		ret;
	t_vector	added;
	int			i;

	if (!data->nb_lights)
		return (col_multiply(data->objs[index].color, 0.3).c);
	added = (t_vector){0, 0, 0};
	i = -1;
	inter.spec.c = 0;
	while (++i < data->nb_lights)
	{
		ret = shade(data, &inter, i, index);
		added.x += ret.argb.r;
		added.y += ret.argb.g;
		added.z += ret.argb.b;
	}
	ret.argb.r = added.x / data->nb_lights;
	ret.argb.g = added.y / data->nb_lights;
	ret.argb.b = added.z / data->nb_lights;
	ret = add_colors(ret, inter.spec);
	return (ret.c);
}
