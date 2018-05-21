/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 05:22:06 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/21 19:47:45 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		light_path_is_blocked(t_data *data, t_inter it1, t_vec lgh, int id)
{
	t_inter	it2;
	int		i;

	it2.min_dist = 0.1;
	i = -1;
	while (++i < data->nb_objects)
	{
		if (i == id)
			continue ;
		it2.oc = vec_substract(it1.ip, data->objs[i].pos);
		if (data->objs[i].intersect(data->objs[i], lgh, &it2) && it2.t < it1.t)
			return (1);
	}
	return (0);
}

int		diffuse_shading(t_data *data, double dot, int index)
{
	return (col_multiply(data->objs[index].color, dot).c);
}

int		ambient_shading(t_data *data, int index)
{
	return (col_multiply(data->objs[index].color, data->lights[0].ambi).c);
}

int		shade(t_data *data, t_inter inter, int index)
{
	t_vec	light;
	double	dot;

	if (!data->nb_lights)
		return (col_divide(data->objs[index].color, 5).c);
	light = vec_normalize(vec_substract(data->lights[0].pos, inter.ip));
	// data->light[0] parce qu'on a pas encore implémenté le multi-spot.
	inter.normal = data->objs[index].get_normal(data->objs[index], inter);
	dot = dot_product(vec_normalize(light), inter.normal);
	if (dot >= 0 && light_path_is_blocked(data, inter, light, index))
		return (ambient_shading(data, index));
	if (dot >= data->lights[0].ambi)
		return (diffuse_shading(data, dot, index));
	return (ambient_shading(data, index));
}
