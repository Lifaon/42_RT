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

/*t_vec	get_cylinder_normal(t_obj cyl, t_inter inter)
{
	t_vec	ray;
	t_camera cam;
	t_vec normal;
	t_vec pi;
	t_vec pos;
	t_vec scaled;
	t_vec new;

	scaled = vec_multiply(ray, inter.t);
	new = vec_add(cam.pos, scaled);
	pi = vec_substract(new, cyl.pos);
	pos = vec_multiply(cyl.oc, dot_product(pi, cyl.pos));
	normal = vec_substract(pi, pos);
	return (normal);
}*/
