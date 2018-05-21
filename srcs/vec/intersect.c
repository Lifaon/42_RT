/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:34:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/21 19:17:49 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		intersect_sphere(t_obj sphere, t_vec ray, t_inter *inter)
{
	double	b;
	double	c;

	b = 2 * dot_product(ray, inter->oc);
	c = dot_product(inter->oc, inter->oc) - (sphere.r * sphere.r);
	inter->delta = (b * b) - (4 * c);
	if (inter->delta < 0)
		return (0);
	inter->t1 = (-b + sqrt(inter->delta)) / 2;
	inter->t2 = (-b - sqrt(inter->delta)) / 2;
	if (inter->t1 >= inter->min_dist && inter->t2 >= inter->min_dist)
		inter->t = inter->t1 < inter->t2 ? inter->t1 : inter->t2;
	else
	{
		if (inter->t1 >= inter->min_dist || inter->t2 >= inter->min_dist)
			inter->t = inter->t1 > inter->t2 ? inter->t1 : inter->t2;
		else
			return (0);
	}
	return (1);
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
	if (inter->t < inter->min_dist || inter->t == INFINITY)
		return (0);
	return (1);
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
	inter->delta = (b * b) - 4 * a * c;
	if (inter->delta < 0)
		return (0);
	inter->t1 = (-b + sqrt(inter->delta)) / (2 * a);
	inter->t2 = (-b - sqrt(inter->delta)) / (2 * a);
	if (inter->t1 >= inter->min_dist && inter->t2 >= inter->min_dist)
		inter->t = inter->t1 < inter->t2 ? inter->t1 : inter->t2;
	else
	{
		if (inter->t1 >= inter->min_dist || inter->t2 >= inter->min_dist)
			inter->t = inter->t1 > inter->t2 ? inter->t1 : inter->t2;
		else
			return (0);
	}
	return (1);
}

int		intersect_cone(t_obj cone, t_vec ray, t_inter *inter)
{
	double	a;
	double	b;
	double	c;

	a = dot_product(ray, ray) - (1 + (tan(cone.r) * tan(cone.r))) * \
		(dot_product(ray, cone.dir) * dot_product(ray, cone.dir));
	b = 2 * (dot_product(ray, inter->oc) - (1 + (tan(cone.r) * tan(cone.r))) * \
		dot_product(ray, cone.dir) * dot_product(inter->oc, cone.dir));
	c = dot_product(inter->oc, inter->oc) - (1 + (tan(cone.r) * tan(cone.r))) *\
		(dot_product(inter->oc, cone.dir) * dot_product(inter->oc, cone.dir));
	inter->delta = (b * b) - 4 * a * c;
	if (inter->delta < 0)
		return (0);
	inter->t1 = (-b + sqrt(inter->delta)) / (2 * a);
	inter->t2 = (-b - sqrt(inter->delta)) / (2 * a);
	if (inter->t1 >= inter->min_dist && inter->t2 >= inter->min_dist)
		inter->t = inter->t1 < inter->t2 ? inter->t1 : inter->t2;
	else
	{
		if (inter->t1 >= inter->min_dist || inter->t2 >= inter->min_dist)
			inter->t = inter->t1 > inter->t2 ? inter->t1 : inter->t2;
		else
			return (0);
	}
	return (1);
}
