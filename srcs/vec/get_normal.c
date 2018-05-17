/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:59:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/14 14:13:18 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	get_sphere_normal(t_obj sphere, t_inter inter)
{
	t_vec 	normal;

	normal = vec_substract(inter.ip, sphere.pos);
	normal.x /= sphere.r;
	normal.y /= sphere.r;
	normal.z /= sphere.r;
	return (normal);
}

/*
**	Plane normal is constant.
*/
t_vec	get_plane_normal(t_obj plane, t_inter inter)
{
	return (plane.normal);
}

t_vec 		get_cylinder_normal(t_obj cyl, t_inter inter)
{
	t_vec scaled;
	t_camera cam;
	t_vec ray;
	t_vec new;
	t_vec b;
	t_vec a;
	t_vec norm;

	scaled = cam.pos;//vec_multiply(cam.dir, inter.t);
	new = cam.pos;//vec_add(cam.dir, scaled);
	b = vec_substract(new, cyl.pos);
	a = vec_multiply(cyl.dir, 1/*dot_product(b, cyl.dir)*/);
	norm = vec_substract(b, a);
	return (norm);
}