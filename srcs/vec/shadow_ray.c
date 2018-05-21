/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 05:22:06 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/21 17:50:29 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		light_path_is_blocked(t_data *data, t_vec ip, double t, int index)
{
	t_inter	inter;
	t_vec	light;
	int		i;

	light = vec_substract(data->lights[0].pos, ip);
	inter.min_dist = 1;
	i = -1;
	while(++i < data->nb_objects)
	{
		inter.oc = vec_substract(ip, data->objs[i].pos);
		if (i == index)
			continue ;
		// ici on doit tester s'il y a une quelconque intersection entre
		// l'objet et la lumiere. j'y suis pas encore arrivé.
		if (data->objs[i].intersect(data->objs[i], vec_normalize(light), \
			&inter) && inter.t < t)
			return (1);
	}
	return (0);
}

int		shadow_ray(t_data *data, t_inter inter, int index)
{
	t_vec	light;
	double	dot;

	if (!data->nb_lights)
		return (col_divide(data->objs[index].color, 5).c);
	light = vec_substract(data->lights[0].pos, inter.ip);
	// data->light[0] parce qu'on a pas encore implémenté le multi-spot.
	inter.normal = data->objs[index].get_normal(data->objs[index], inter);
	dot = dot_product(vec_normalize(light), inter.normal);
	if (dot >= 0 && light_path_is_blocked(data, inter.ip, inter.t, index))
		return (col_multiply(data->objs[index].color, 0.2).c);
	if (dot >= 0.3)
		return (col_multiply(data->objs[index].color, dot).c);
	return (col_multiply(data->objs[index].color, 0.3).c);
}
