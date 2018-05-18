/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:59:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/18 16:59:12 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	get_sphere_normal(t_obj sphere, t_inter inter)
{
	t_vec norm;

	norm = vec_substract(inter.ip, sphere.pos);
	return ((t_vec){norm.x / sphere.r, norm.y / sphere.r, norm.z / sphere.r});
}

/*
**	Plane normal is constant.
*/
t_vec	get_plane_normal(t_obj plane, t_inter inter)
{
	(void)inter;
	return (plane.normal);
}

t_vec 		get_cylinder_normal(t_obj cyl, t_inter inter)
{
	t_vec b;
	t_vec a;
	t_vec norm;

	b = vec_substract(inter.ip, cyl.pos);
	a = vec_multiply(cyl.dir, dot_product(b, cyl.dir));
	norm = vec_substract(b, a);
	return ((t_vec){norm.x / cyl.r, norm.y / cyl.r, norm.z / cyl.r});
}

t_vec 		get_cone_normal(t_obj cone, t_inter inter)
{
	t_vec b;
	t_vec a;
	t_vec norm;

	b = vec_substract(inter.ip, cone.pos);
	a = vec_multiply(cone.dir, dot_product(b, cone.dir));
	norm = vec_substract(b, a);
	return (vec_normalize(norm));
}
