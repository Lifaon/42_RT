/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 03:04:14 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/05 20:23:14 by mlantonn         ###   ########.fr       */
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
