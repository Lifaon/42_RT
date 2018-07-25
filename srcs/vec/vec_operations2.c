/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 03:04:14 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/25 15:01:11 by mlantonn         ###   ########.fr       */
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

t_vec	vec_cross_product2(t_vec u, t_vec v)
{
	t_vec res;

	res.x = u.y * v.z + u.z * v.y;
	res.y = u.z * v.x + u.x * v.z;
	res.z = u.x * v.y + u.y * v.x;
	return (res);
}

t_vec	get_random_direction(void)
{
	t_vec		dir;
	t_vec		angle;

	dir = (t_vec){0, -1, 0};
	angle.x = (36000. * rand() / (RAND_MAX + 1.0)) * .01;
	angle.y = (36000. * rand() / (RAND_MAX + 1.0)) * .01;
	angle.z = (36000. * rand() / (RAND_MAX + 1.0)) * .01;
	dir = all_rotations(dir, angle);
	return (dir);
}
