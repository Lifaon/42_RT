/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:55:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/24 18:38:35 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
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

typedef struct		s_ray
{
	t_vec			o;
	t_vec			d;
}					t_ray;
/*
**	Ray struct -> o = origin ; d = direction.
*/

typedef struct		s_obj
{
	int				color;
	double			r;
	t_vec			c;
	t_vec			oc;
	t_vec			pi;
	t_vec			norm;
	int				(*intersect)(t_ray, struct s_obj, double *);
	t_vec			(*get_normal)(struct s_obj);
}					t_obj;
/*
**	Object structure -> r = radius ; c = center of the object ; oc = distance
**	between origin of the ray and center of the object ; pi = point of
**	intersection ; norm = normal at the point of intersection.
*/

typedef struct		s_data
{
	double			vpd;
	t_vec			vp00;
	t_ray			ray;
	t_mlx			mlx;
}					t_data;
/*
**	Struct used to store different variables.
*/

#endif
