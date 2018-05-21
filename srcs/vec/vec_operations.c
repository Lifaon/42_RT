/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:03:55 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/24 13:51:10 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	vec_add(t_vec u, t_vec v)
{
	u.x += v.x;
	u.y += v.y;
	u.z += v.z;
	return (u);
}

t_vec	vec_substract(t_vec u, t_vec v)
{
	u.x -= v.x;
	u.y -= v.y;
	u.z -= v.z;
	return (u);
}

t_vec	vec_multiply(t_vec u, double t)
{
	u.x *= t;
	u.y *= t;
	u.z *= t;
	return (u);
}

double	vec_cos(t_vec u, t_vec v)
{
	double a;
	double b;
	double c;
	double cos;

	a = dot_product(u, v);
	b = dot_product(u, u);
	c = dot_product(v, v);
	cos = a / (b * c);
	return (cos);
}

t_vec	vec_mult(t_vec u, t_vec v)
{
	t_vec res;

	res.x = u.y * v.z - u.z * v.y;
	res.y = u.z * v.x - u.x * v.z;
	res.z = u.x * v.y - u.y * v.x;
	return (res);
}