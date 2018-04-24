/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:34:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/24 18:34:13 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	Dans le cas de la sphère, le a de b^2 - 4ac est toujours égal à 1.
*/
int		intersect_sphere(t_ray ray, t_obj sphere, double *t)
{
	double	b;
	double	c;
	double	det;
	double	t1;
	double	t2;

	b = 2 * dot_product(ray.d, sphere.oc);
	c = dot_product(sphere.oc, sphere.oc) - (sphere.r * sphere.r);
	det = (b * b) - (4 * c);
	if (det < 0)
		return (0);
	t1 = (-b + sqrt(det)) / 2;
	t2 = (-b - sqrt(det)) / 2;
	if (t1 >= 0 && t2 >= 0)
		*t = t1 < t2 ? t1 : t2;
	else
	{
		if (t1 >= 0 || t2 >= 0)
			*t = t1 > t2 ? t1 : t2;
		else
			return (0);
	}
	return (1);
}

int		intersect_plane(t_ray ray, t_obj plane, double *t)
{
	double xv;
	double dv;

	xv = dot_product(plane.oc, plane.norm);
	dv = dot_product(ray.d, plane.norm);
	if (dv == 0)
		return (0);
	*t = -xv / dv;
	if (*t <= 0)
		return (0);
	return (1);
}
