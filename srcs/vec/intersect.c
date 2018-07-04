/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:34:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/03 18:52:56 by mlantonn         ###   ########.fr       */
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

	b = 2 * dot_product(ray, inter->oc);
	c = dot_product(inter->oc, inter->oc) - (sphere.r * sphere.r);
	if (!solve_quadratic_equation(inter, 1, b, c))
		return (0);
	if (!obj_limit(sphere, ray, inter))
		return (0);
	return (limit_tex(sphere, ray, inter));
}

int		intersect_plane(t_obj plane, t_vec ray, t_inter *inter)
{
	double xv;
	double dv;

	xv = dot_product(inter->oc, plane.dir);
	dv = dot_product(ray, plane.dir);
	if (dv == 0)
		return (0);
	inter->t = -xv / dv;
	if (inter->t <= inter->min_dist)
		return (0);
	if (!obj_limit(plane, ray, inter))
		return (0);
	return (limit_tex(plane, ray, inter));
}

int		intersect_cylinder(t_obj cyl, t_vec ray, t_inter *inter)
{
	double	a;
	double	b;
	double	c;

	a = dot_product(ray, ray) - \
		(dot_product(ray, cyl.dir) * dot_product(ray, cyl.dir));
	b = 2 * (dot_product(ray, inter->oc) - \
		dot_product(ray, cyl.dir) * dot_product(inter->oc, cyl.dir));
	c = dot_product(inter->oc, inter->oc) - ((dot_product(inter->oc, cyl.dir) *\
		dot_product(inter->oc, cyl.dir)) + (cyl.r * cyl.r));
	if (!solve_quadratic_equation(inter, a, b, c))
		return (0);
	if (!obj_limit(cyl, ray, inter))
		return (0);
	return (limit_tex(cyl, ray, inter));
}

int		intersect_cone(t_obj cone, t_vec ray, t_inter *inter)
{
	double	a;
	double	b;
	double	c;
	double	radius;

	radius = 1 + (cone.r * M_PI / 180) * (cone.r * M_PI / 180);
	a = 1 - radius * \
		(dot_product(ray, cone.dir) * dot_product(ray, cone.dir));
	b = 2 * (dot_product(ray, inter->oc) - radius * \
		dot_product(ray, cone.dir) * dot_product(inter->oc, cone.dir));
	c = dot_product(inter->oc, inter->oc) - radius * \
		(dot_product(inter->oc, cone.dir) * dot_product(inter->oc, cone.dir));
	if (!solve_quadratic_equation(inter, a, b, c))
		return (0);
	if (!obj_limit(cone, ray, inter))
		return (0);
	return (limit_tex(cone, ray, inter));
}
