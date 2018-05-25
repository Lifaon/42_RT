/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 05:22:06 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/25 16:04:01 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		is_light_path_blocked(t_data *data, t_vec ip, t_vec light, double len)
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
	if (dot > 0)
		return (col_multiply(data->objs[index].color, dot));
	return ((t_color)(uint32_t)0);
}

t_color	ambient_shading(t_data *data, int light_i, int index)
{
	return (col_multiply(data->objs[index].color, data->lights[light_i].ambi));
}

t_color	shade(t_data *data, t_inter inter, int light_i, int index)
{
	t_vec	light;
	double	len;
	double	dot;
	int		nb;

	light = vec_substract(data->lights[light_i].pos, inter.ip);
	len = get_length(light);
	light = vec_normalize(light);
	inter.normal = data->objs[index].get_normal(data->objs[index], inter);
	dot = dot_product(light, inter.normal);
	if (dot >= 0 && is_light_path_blocked(data, inter.ip, light, len))
		return (col_divide(ambient_shading(data, dot, index), 2));
	return (blend_colors(\
		diffuse_shading(data, dot, index), \
		ambient_shading(data, light_i, index)));
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
