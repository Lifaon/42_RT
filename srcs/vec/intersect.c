/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:34:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/21 03:25:33 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int		solve_quadratic_equation(t_inter *inter, double a, double b, double c)
{
	inter->delta = (b * b) - 4 * a * c;
	if (inter->delta < 0)
		return (0);
	inter->t1 = (-b + sqrt(inter->delta)) / (2 * a);
	inter->t2 = (-b - sqrt(inter->delta)) / (2 * a);
	if (inter->t1 > inter->min_dist && inter->t2 > inter->min_dist)
		inter->t = inter->t1 < inter->t2 ? inter->t1 : inter->t2;
	else
	{
		if (inter->t1 > inter->min_dist || inter->t2 > inter->min_dist)
			inter->t = inter->t1 > inter->t2 ? inter->t1 : inter->t2;
		else
			return (0);
	}
	return (1);
}

int		intersect_sphere(t_obj sphere, t_vec ray, t_inter *inter)
{
	double	b;
	double	c;
	t_vec	ip;

	b = 2 * dot_product(ray, inter->oc);
	c = dot_product(inter->oc, inter->oc) - (sphere.r * sphere.r);
	return (solve_quadratic_equation(inter, 1, b, c));
/*
	Limits algorithm

	t_vec	ip;
	t_vec	max = {INFINITY, INFINITY, INFINITY};
	t_vec	min = {-INFINITY, -INFINITY, -INFINITY};

	if (!solve_quadratic_equation(inter, a, b, c))
		return (0);
	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, cyl.pos);
	if (ip.x <= max.x && ip.x >= min.x && \
		ip.y <= max.y && ip.y >= min.y && \
		ip.z <= max.z && ip.z >= min.z)
		return (1);
	inter->t = inter->t != inter->t1 ? inter->t1 : inter->t2;
	if (inter->t < inter->min_dist)
		return (0);
	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, cyl.pos);
	if (ip.x <= max.x && ip.x >= min.x && \
		ip.y <= max.y && ip.y >= min.y && \
		ip.z <= max.z && ip.z >= min.z)
		return (1);
	return (0);
*/
}

int		intersect_plane(t_obj plane, t_vec ray, t_inter *inter)
{
	double xv;
	double dv;

	xv = dot_product(inter->oc, plane.normal);
	dv = dot_product(ray, plane.normal);
	if (dv == 0)
		return (0);
	inter->t = -xv / dv;
	if (inter->t <= inter->min_dist)
		return (0);
	return (1);
}

int		intersect_cylinder(t_obj cyl, t_vec ray, t_inter *inter)
{
	double	a;
	double	b;
	double	c;
	t_vec	dir;

	dir = vec_normalize(cyl.dir);
	a = dot_product(ray, ray) - \
		(dot_product(ray, dir) * dot_product(ray, dir));
	b = 2 * (dot_product(ray, inter->oc) - \
		dot_product(ray, dir) * dot_product(inter->oc, dir));
	c = dot_product(inter->oc, inter->oc) - ((dot_product(inter->oc, dir) *\
		dot_product(inter->oc, dir)) + (cyl.r * cyl.r));
	return (solve_quadratic_equation(inter, a, b, c));
}

int		intersect_cone(t_obj cone, t_vec ray, t_inter *inter)
{
	double	a;
	double	b;
	double	c;
	double	radius;
	t_vec	dir;

	radius = 1 + (cone.r * M_PI / 180) * (cone.r * M_PI / 180);
	dir = vec_normalize(cone.dir);
	a = 1 - radius * \
		(dot_product(ray, dir) * dot_product(ray, dir));
	b = 2 * (dot_product(ray, inter->oc) - radius * \
		dot_product(ray, dir) * dot_product(inter->oc, dir));
	c = dot_product(inter->oc, inter->oc) - radius * \
		(dot_product(inter->oc, dir) * dot_product(inter->oc, dir));
	return (solve_quadratic_equation(inter, a, b, c));
}
