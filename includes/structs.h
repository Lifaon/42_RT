/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:55:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/04 15:55:29 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include <stdint.h>
# include "defines.h"

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*addr;
}					t_mlx;
/*
**	Storing the necessary pointers for the mlx usage.
*/

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;
/*
**	Storing 3D coordinates.
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

typedef struct		s_ray
{
	t_vec			o;
	t_vec			d;
}					t_ray;
/*
**	Ray struct -> o = origin ; d = direction.
*/

typedef struct		s_camera
{
	t_vec			pos;
	t_vec			dir;
	t_vec			vp00;
	double			fov;
}					t_camera;
/*
**	Cam struct -> pos = position ; dir = direction ; fov = field of view.
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
**	Cam struct -> pos = position ; dir = direction ; fov = field of view.
*/

typedef struct		s_obj
{
	double			r;
	double			ambient;
	double			diffuse;
	double			specular;
	t_vec			pos;
	t_vec			rot;
	t_vec			normal;
	t_color			color;
	int				(*intersect)(t_ray, struct s_obj, double *);
	t_vec			(*get_normal)(struct s_obj);
}					t_obj;
/*
**	Object structure -> r = radius ; pos = center of the object ; oc = distance
**	between origin of the ray and center of the object ; pi = point of
**	intersection ; norm = normal at the point of intersection.
*/

typedef struct		s_data
{
	t_camera		cams[4];
	t_light			*lights;
	int				nb_lights;
	t_obj			*objs;
	int				nb_objects;
	t_ray			ray;
	t_mlx			mlx;
}					t_data;
/*
**	Struct used to store different variables.
*/

#endif
