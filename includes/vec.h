/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:01:18 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/04 16:19:55 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <math.h>
# include "structs.h"

/*
**	Intersection functions.
*/
int		intersect_sphere(t_obj sphere, t_vec ray, t_inter *inter);
int		intersect_plane(t_obj plane, t_vec ray, t_inter *inter);
int		intersect_cylinder(t_obj sphere, t_vec ray, t_inter *inter);
int		intersect_cone(t_obj plane, t_vec ray, t_inter *inter);

/*
**	Functions to get the normal of the objects at the intersection point.
*/
t_vec	get_normal(t_vec ray, t_obj obj, t_inter inter);
t_vec	get_sphere_normal(t_obj sphere, t_inter inter);
t_vec	get_plane_normal(t_obj plane, t_inter inter);
t_vec	get_cylinder_normal(t_obj cyl, t_inter inter);
t_vec	get_cone_normal(t_obj cone, t_inter inter);

/*
**	Vector operations.
*/
t_vec	vec_add(t_vec u, t_vec v);
t_vec	vec_substract(t_vec u, t_vec v);
t_vec	vec_multiply(t_vec u, double t);
double	vec_cos(t_vec u, t_vec v);
t_vec	vec_mult(t_vec u, t_vec v);

/*
**	Vector operations 2.
*/
t_vec	vec_normalize(t_vec u);
double	get_length(t_vec u);
double	dot_product(t_vec u, t_vec v);
void	rotation_3d(t_vec *vec, double rot_x, double rot_y, double rot_z);

#endif
