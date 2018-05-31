/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:44:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/31 19:56:06 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	RTv1 is a school project designed to learn the basics of raytracing.
*/

#ifndef RTV1_H
# define RTV1_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>

# include "libft.h"
# include "libpt.h"
# include "libmysdl.h"

# include "structs.h"
# include "defines.h"

/*
**	Drawing functions.
*/
void			draw_image(t_data *data);
int				get_px_color(t_data *data, t_inter inter, int index);

/*
**	Intersection functions.
*/
int				intersect_sphere(t_obj sphere, t_vec ray, t_inter *inter);
int				intersect_plane(t_obj plane, t_vec ray, t_inter *inter);
int				intersect_cylinder(t_obj sphere, t_vec ray, t_inter *inter);
int				intersect_cone(t_obj plane, t_vec ray, t_inter *inter);

/*
**	Functions to get the normal of the objects at the intersection point.
*/
t_vec			get_normal(t_vec ray, t_obj obj, t_inter inter);
t_vec			get_sphere_normal(t_obj sphere, t_inter inter);
t_vec			get_plane_normal(t_obj plane, t_inter inter);
t_vec			get_cylinder_normal(t_obj cyl, t_inter inter);
t_vec			get_cone_normal(t_obj cone, t_inter inter);

/*
**	Vector operations.
*/
t_vec			vec_add(t_vec u, t_vec v);
t_vec			vec_substract(t_vec u, t_vec v);
t_vec			vec_multiply(t_vec u, double t);
double			vec_cos(t_vec u, t_vec v);
t_vec			vec_mult(t_vec u, t_vec v);
/*
**	Vector operations 2.
*/
t_vec			vec_normalize(t_vec u);
double			get_length(t_vec u);
double			dot_product(t_vec u, t_vec v);
void			rotation_3d(t_vec *vec, double rot_x, double rot_y, double rot_z); // avec rot_x, rot_y et rot_z en degre

/*
**	Function used to parse the given file.
*/
void			parse(t_data *data, char *file_name);

/*
**	Functions used to initialize the different structures.
*/
void			data_init(t_data *data, int ac, char **av);

/*
** Functions use to handle event
*/
void			ft_event(t_data *data);
t_funar_keyb	*fill_funar_key_event(int *size);
int				ft_mouse_wheel(int y, t_data *data);
int				ft_mouse(int x, int y, t_data *data);
int				ft_keyboard(int key, t_data *data);

/*
**	Phong shading.
*/
t_color			diffuse_shading(t_data *data, double dot, int index);
t_color			ambient_shading(t_data *data, int light_i, int index);
t_color			specular_shading(t_data *data, int index, t_inter inter, \
																t_vec light);

/*
**	Functions used for color management.
*/
t_color			add_colors(t_color col1, t_color col2);
t_color			blend_colors(t_color col1, t_color col2);
t_color			col_multiply(t_color color, double nb);
t_color			col_divide(t_color color, double nb);

/*
**	Frees everything that has to be freed.
*/
void			exit_all(t_data *data);

#endif
