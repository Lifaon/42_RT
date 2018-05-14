/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 05:22:06 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/14 20:11:41 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		light_path_is_blocked(t_data *data, t_vec light, int index)
{
	t_inter	inter;
	double	length;
	int		i;

	inter.min_dist = 0;
	inter.oc = vec_multiply(light, -1);
	length = get_length(inter.oc);
	i = -1;
	while(++i < data->nb_objects)
	{
		if (i == index)
			continue ;
		if (data->objs[i].intersect(data->objs[i], vec_normalize(inter.oc), \
			&inter) && inter.t < length)
			return (1);
	}
	return (0);
}

int		shadow_ray(t_data *data, t_inter inter, int index)
{
	t_vec	light;
	double	dot;

	if (!data->nb_lights)
		return (col_divide(data->objs[index].color, 10).c);
	light = vec_substract(data->lights[0].pos, inter.ip);
	// data->light[0] parce qu'on a pas encore implémenté le multi-spot.
	inter.normal = data->objs[index].get_normal(data->objs[index], inter);
	//if (light_path_is_blocked(data, light, index))
	//	return (0xFFFFFF);
	dot = dot_product(vec_normalize(light), vec_normalize(inter.normal));
	if (dot >= 0.3)
		return (col_multiply(data->objs[index].color, dot).c);
	return (col_multiply(data->objs[index].color, 0.3).c);
}
