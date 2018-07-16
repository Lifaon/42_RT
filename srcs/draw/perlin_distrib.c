/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_distrib.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 00:27:17 by vtudes            #+#    #+#             */
/*   Updated: 2018/07/17 00:28:37 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		apply_perlin(t_data *data, t_inter *inter)
{
	t_obj	obj;
	int		a;

	a = 2;
	inter->normal.z = (inter->normal.z + noise_3D_first(inter->ip.z - a,\
	inter->ip.y, inter->ip.x, data)) - (inter->normal.z +\
	noise_3D_first(inter->ip.z + a, inter->ip.y, inter->ip.z, data));
	inter->normal.y = (inter->normal.y + noise_3D_first(inter->ip.z,\
	inter->ip.y - a, inter->ip.x, data)) - (inter->normal.y +\
	noise_3D_first(inter->ip.z, inter->ip.y + a, inter->ip.x, data));
	inter->normal.x = (inter->normal.x + noise_3D_first(inter->ip.z,\
	inter->ip.y, inter->ip.x - a, data)) - (inter->normal.x +\
	noise_3D_first(inter->ip.z, inter->ip.y, inter->ip.x + a, data));
}

void		call_perlin(t_data data, t_inter *inter, t_obj obj)
{
	if (obj.obj_type == PLANE)
		apply_perlin(&data, inter);
	if (obj.obj_type == SPHERE)
		apply_perlin(&data, inter);
	if (obj.obj_type == CONE)
		apply_perlin(&data, inter);
	if (obj.obj_type == CYLINDER)
		apply_perlin(&data, inter);
}
