/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:55:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/03 19:36:36 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include "defines.h"
# include "libmysdl.h"

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

typedef struct		s_col
{
	int				r;
	int				g;
	int				b;
}					t_col;

typedef struct		s_ray
{
	t_vec			o;
	t_vec			d;
}					t_ray;
/*
**	Ray struct -> o = origin ; d = direction.
*/

typedef union		u_color
{
	uint32_t		c;
	struct			s_argb
	{
		uint8_t		a;
		uint8_t		r;
		uint8_t		g;
		uint8_t		b;
	}				argb;
}					t_color;

typedef struct		s_obj
{
	double			r;
	double			t1;
	double			t2;
	double			ambient;
	double			diffuse;
	double			specular;
	t_col			color;
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
	t_win			*win;
	t_texture		*tex;
}					t_data;
/*
**	Struct used to store different variables.
*/

typedef struct		s_funar_keyb
{
	int		key;
	void	(*f)(t_data*);
}					t_funar_keyb;

/*
** This structure is used to handle the keyboard event
** fill f with the function you want to use when the key is push
*/
#endif
