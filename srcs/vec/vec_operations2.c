/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 03:04:14 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/04 16:19:40 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	vec_normalize(t_vec u)
{
	double	length;
	t_vec	ret;

	length = sqrt((u.x * u.x) + (u.y * u.y) + (u.z * u.z));
	ret.x = u.x / length;
	ret.y = u.y / length;
	ret.z = u.z / length;
	return (ret);
}

double	get_length(t_vec u)
{
	return (sqrt((u.x * u.x) + (u.y * u.y) + (u.z * u.z)));
}

double	dot_product(t_vec u, t_vec v)
{
	return ((u.x * v.x) + (u.y * v.y) + (u.z * v.z));
}

/*
** avec rot_x, rot_y, rot_z en degre
*/

void	rotation_3d(t_vec *vec, double rot_x, double rot_y, double rot_z)
{
	vec->y = cos(rot_x) * vec->y - sin(rot_x) * vec->z;
	vec->z = sin(rot_x) * vec->y + cos(rot_x) * vec->z;
	vec->x = cos(rot_y) * vec->x + sin(rot_y) * vec->z;
	vec->y = -sin(rot_y) * vec->x + cos(rot_y) * vec->z;
	vec->x = cos(rot_z) * vec->x - sin(rot_z) * vec->y;
	vec->y = sin(rot_z) * vec->x + cos(rot_z) * vec->y;
}
