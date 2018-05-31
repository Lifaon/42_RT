/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 05:22:06 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/31 16:04:19 by mlantonn         ###   ########.fr       */
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

t_color	diffuse_shading(t_data *data, double dot, int index)
{
	return (col_multiply(data->objs[index].color, dot));
}

t_color	ambient_shading(t_data *data, int light_i, int index)
{
	return (col_multiply(data->objs[index].color, data->lights[light_i].ambi));
}

t_color	specular_shading(t_data *data, int index, t_inter inter, t_vec light)
{
	double	dot;
	t_vec	r;
	t_vec	v;

	r = vec_normalize(vec_substract(\
			vec_multiply(inter.normal, dot_product(inter.normal, light) * 2.0),\
			light));
	v = vec_normalize(vec_substract(data->cams[data->i].pos, inter.ip));
	dot = dot_product(v, r);
	if (dot > 0)
		return (col_multiply((t_color)(uint32_t)0xFFFFFF, \
			data->objs[index].spec * pow(dot, data->objs[index].alpha)));
	return ((t_color)(uint32_t)0);
}

t_color	shade(t_data *data, t_inter inter, int light_i, int index)
{
	t_color	ret;
	t_vec	light;
	double	len;
	double	dot;

	ret = ambient_shading(data, light_i, index);
	light = vec_substract(data->lights[light_i].pos, inter.ip);
	len = get_length(light);
	light = vec_normalize(light);
	if (light_is_path_blocked(data, inter.ip, light, len))
		return (ret);
	dot = dot_product(light, inter.normal);
	if (dot <= 0)
		return (ret);
	ret = add_colors(ret, diffuse_shading(data, dot, index));
	ret = add_colors(ret, \
		specular_shading(data, index, inter, light));
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
	while (++i < data->nb_lights)
	{
		ret = shade(data, inter, i, index);
		added.x += ret.argb.r;
		added.y += ret.argb.g;
		added.z += ret.argb.b;
	}
	ret.argb.r = added.x / data->nb_lights;
	ret.argb.g = added.y / data->nb_lights;
	ret.argb.b = added.z / data->nb_lights;
	return (ret.c);
}
