/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:55:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/09 14:10:41 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>
# include "defines.h"
# include "libmysdl.h"

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;
/*
**	Storing 3D coordinates or 3D vectors.
*/

typedef union		u_color
{
    uint32_t		c;
    struct			s_argb
    {
		uint8_t		b;
        uint8_t		g;
		uint8_t		r;
		uint8_t		a;
    }				argb;
}					t_color;
/*
**	Usage of an union for easy color management.
*/

typedef struct		s_inter
{
	double			t1;
	double			t2;
	double			t;
	double			min_dist;
	double			delta;
	t_vec			ip;
	t_vec			normal;
}					t_inter;
/*
**	Intersection structure -> t1, t2 and delta are used for equations of degree
**	two, and t is the smallest positive number between t1 and t2 ; min_dist =
**	minimum distance before we consider there is an intersection ; ip =
**	intersection point ; normal = the normal of the object at 'ip'.
*/

typedef struct		s_camera
{
	t_vec			pos;
	t_vec			dir;
	t_vec			vp_up_left;
	double			vp_dist;
	double			fov;
}					t_camera;
/*
**	Cam struct -> pos = position ; dir = direction ; vp_up_left = the point at
**	the top left of the view_place ; vp_dist = distance between the camera and
**	the view plane ; fov = field of view.
*/

typedef struct		s_light
{
	int				is_para;
	double			r;
	t_vec			pos;
	t_vec			dir;
	t_color			color;
}					t_light;
/*
**	Cam struct -> is_para = 0 or 1 wether the light source is parallel or not ;
**	r = radius of the light source ; pos = position ; dir = direction.
*/

typedef struct		s_obj
{
	double			r;
	double			ambi;
	double			diff;
	double			spec;
	t_color			color;
	t_vec			pos;
	t_vec			dir;
	t_vec			oc;
	t_vec			normal;
	int				(*intersect)(struct s_obj, t_vec, t_inter *);
	t_vec			(*get_normal)(struct s_obj, t_inter);
}					t_obj;
/*
**	Object structure -> r = radius ; ambi, diff and spec = coeffs for Phong
**	lightning ; pos = position which defines the object ; dir = direction in
**	case it has one ; oc = vector between the current camera and 'pos' ;
**	normal = surface normal in case it's constant (e.g. plane)
*/

typedef struct		s_data
{
	int				nb_objects;
	t_obj			*objs;
	int				nb_lights;
	t_light			*lights;
	int				i;
	t_camera		cams[4];
	t_win			*win;
	t_texture		*tex;
}					t_data;
/*
**	Struct used to store objects, light sources, and the 4 possible cameras, in
**	addition with the mlx struct;
*/

typedef struct		s_funar_keyb
{
	int				key;
	void			(*f)(t_data*);
}					t_funar_keyb;
/*
** This structure is used to handle the keyboard event
** fill f with the function you want to use when the key is push
*/

#endif
