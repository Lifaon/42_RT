/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:59:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/21 09:04:53 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	get_sphere_normal(t_obj sphere, t_inter inter)
{
	t_vec norm;

	norm = vec_substract(inter.ip, sphere.pos);
	return ((t_vec){norm.x / sphere.r, norm.y / sphere.r, norm.z / sphere.r});
}

t_vec	get_plane_normal(t_obj plane, t_inter inter)
{
	(void)inter;
	return (plane.dir);
}

t_vec	get_cylinder_normal(t_obj cyl, t_inter inter)
{
	t_vec hyp;
	t_vec adj;
	t_vec norm;

	hyp = vec_substract(inter.ip, cyl.pos);
	adj = vec_multiply(cyl.dir, dot_product(hyp, cyl.dir));
	norm = vec_substract(hyp, adj);
	return ((t_vec){norm.x / cyl.r, norm.y / cyl.r, norm.z / cyl.r});
}

t_vec	get_cone_normal(t_obj cone, t_inter inter)
{
	t_vec b;
	t_vec a;
	t_vec scaled;
	t_vec norm;
	t_vec dir;

	dir = vec_normalize(cone.dir);
	b = vec_normalize(vec_substract(cone.pos, inter.ip));
	a = vec_multiply(dir, vec_cos(b, dir));
	norm = vec_substract(b, a);
	scaled = vec_cross_product(b, norm);
	norm = vec_cross_product(b, scaled);
	return (vec_normalize(norm));
}

t_vec	get_normal(t_vec ray, t_obj obj, t_inter inter)
{
	t_vec	normal;
	double	dot;

	normal = obj.get_normal(obj, inter);
	dot = dot_product(ray, normal);
	normal = dot <= 0 ? normal : vec_multiply(normal, -1);
	normal = bump_mapping(inter, normal);
	return (normal);
}
