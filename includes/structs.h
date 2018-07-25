/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:55:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/25 12:38:53 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>
# include "defines.h"
# include "mygtk.h"

/*
**	Storing 3D coordinates or 3D vectors.
*/
typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

/*
**	Photon strucure. Used for photon mapping and caustics
*/
typedef struct		s_photon
{
	t_vec			pos;
	t_color			color;
	int				obj_i;
}					t_photon;

/*
**	Perlin structure
*/
typedef struct		s_perlin
{
	int				bx0;
	int				bx1;
	int				by0;
	int				by1;
	int				bz0;
	int				bz1;
	int				b00;
	int				b01;
	int				b11;
	int				b10;
	float			rx0;
	float			rx1;
	float			ry0;
	float			ry1;
	float			rz0;
	float			rz1;
	float			*q;
	float			sy;
	float			sz;
	float			a;
	float			b;
	float			c;
	float			d;
	float			t;
	float			u;
	float			v;
}					t_perlin;

/*
**	Intersection structure. Called in stack for every ray management
*/
typedef struct		s_inter
{
	int				obj_i;		// index of the intersected object
	int				depth;		// depth flag for bouncing rays
	int				in_object;		// flag to know if in object (refraction)
	double			min_dist;	// minimum distance between origin and ip
	double			t1;		// first quadratic equation solution
	double			t2;		// second quadratic equation solution
	double			t;		// smallest result > min_dist between t1 & t2
	double			delta;		// discriminant of quadratic equation
	t_vec			origin;		// origin of current ray
	t_vec			oc;		// inter.origin to obj.pos vector
	t_vec			ip;		// intersection point
	t_vec			normal;		// normal at ip
	t_color			color;		// color at ip
	t_color			shadow;		// shadow color at ip
	t_color			spec;		// specular color at ip
	double			trans_at_ip;	// transparency at ip
	t_point			uv;		// UV mapping vector lengths
}					t_inter;

/*
**	Camera structure. Used as an array in the data structure
*/
typedef struct		s_camera
{
	double			fov;	// field of fiew, changes vp_up_left, 1 to 180
	t_vec			pos;	// position
	t_vec			angle;		// angle of the direction, in degrees
	t_vec			vp_up_left;		// view plane, call get_vp_up_left(cam)
}					t_camera;

/*
**	Object structure. Used as an array in the data structure
*/
typedef struct		s_light
{
	int				is_para;	// defines if the light is parallel or not
	int				disabled;	// defines if the light is on or not
	double			ambi;		// ambient coefficient, 0 to 1
	double			r;		// radius of the light source. Not (yet) implemented
	t_vec			pos;	// position
	t_vec			dir;	// direction
	t_vec			angle;		// angle of the direction, in degrees
	t_color			color;		// color of the light
	t_color			color_neg;		// 0xFFFFFF - light.color
}					t_light;

/*
**	Object structure. Used as an array in the data structure
*/
typedef struct		s_obj
{
	int				obj_type;	// sphere, plane, cone, cylinder : defines.h
	int				limited;	// type of limit : defines.h
	int				enabled;	// defines if the object exists or not
	double			r;		// radius
	double			spec;		// specular coefficient, 0 to 1
	double			alpha;		// alpha for specular calcul, 1 to inf
	double			shiny;		// reflexion coeffient, 0 to 1
	double			trans;		// transparency coeffient, 0 to 1
	double			ior;	// refractive index, 1 in the air
	t_color			color;		// main color component
	t_color			color2;		// second color component, for checkerboards
	int				color_type;		// type of basic color : defines.h
	int				color_scale;	// scaling for checkerboards and others
	int				perl_scale;		// scaling for perlin noise
	int				perl_type;		// on/off, types of perlin, : defines.h
	double			perl_opacity;	// opacity coeff for perlin, 0 to 1
	int				bump_flag;		// switches on and off bump mapping
	double			bump_intensity;		// bump intensity coefficient, 0 to 1
	int				bump_scale;		// scaling for bump mapping
	t_vec			pos;	// position
	t_vec			dir;	// directional axe
	t_vec			angle;		// angle of the direction, in degrees
	t_vec			y_dir;		// call get_dir() if you change obj.angle
	t_vec			z_dir;		// call get_dir() if you change obj.angle
	t_vec			min;	// minimum values for limited objects
	t_vec			max;	// maximum values for limited objects
	t_vec			oc;		// obj.pos to cam.pos vector, call get_oc();
	t_pixelbuf		*tex;		// texture structure : lib/libmygtk/includes
	t_point			tex_pos;	// texture position, centered by default
	int				tex_scale;		// scaling for textures
	int				tex_repeat;		// the texture repeats itself
	int				tex_limit;		// the texture defines the limits
	int				tex_trans;		// the texture defines the transparency
	char			*tex_filename;		// path to the texture
	int				(*intersect)(struct s_obj, t_vec, t_inter *); 	// fct ptr
	int				(*limit)(struct s_obj, t_vec, t_inter *); 	// fct ptr
	t_vec			(*get_normal)(struct s_obj, t_inter); 	// fct ptr
}					t_obj;

/*
**	UI strucure. Used as a global : g_ui
*/
typedef struct		s_ui
{
	GtkWidget		*tab;
	GtkWidget		*tab_light;
	GtkWidget		*tab_cams;
	GtkWidget		*tab_objs;
	GtkWidget		*ev_box;
	GtkWidget		*sc_fov;
	GtkSizeGroup	*gp_cam_pos;
	GtkSizeGroup	*gp_cam_angle;
	GtkSizeGroup	*gp_dof_focus;
	int				is_active;
	int				page_light;
	int				page_cam;
	int				page_obj;
}					t_ui;
t_ui				*g_ui;

/*
**	Data strucure. Used as a global : g_data
*/
typedef struct		s_data
{
	t_obj			*objs;		// object array
	int				nb_objects;		// number of objects in data.objs
	t_light			*lights;	// light array
	int				nb_lights;		// number of lights data.lights
	int				nb_lights_on;	// number of lights that are switched on
	t_camera		cams[CAM_NB];	// camera array. CAM_NB : defines.h
	int				i;		// index of the current camera
	t_camera		cam;	// data.cam = data.objs[data.i]
	int				aa;		// anti-aliasing variable. SSAA*aa
	int				px;		// pixelation variable
	int				depth_of_field;		// index of the object to focus
	double			dof_coeff;		// depth of field coefficient, 0.1 to 3~
	int				cel_shading;	// defines if cel_shading is on
	int				filter;		// defines if a filter is on : defines.h
	int				depth_max;		// defines the maximum value of inter.depth
	t_photon		*photon_map;	// to store photons, if == NULL no caustics
	int				photon_total;	// total of photons emitted
	int				photon_hit;		// total of photons that bounced once or +
	int				photon_ppx;		// number of photons max per pixel
	double			photon_size;	// size of the photon area
	int				stereo_scale;	// scaling for stereoscopy, 1 to 100
	void			*win;		//
	t_pixelbuf		*img;		//
	int				draw;		//
	char			*path;		//
	char			*long_path;		//
	int				(*intersect[4])(struct s_obj, t_vec, t_inter *); //defines.h
	int				(*limit[6])(struct s_obj, t_vec, t_inter *); //	defines.h
	t_vec			(*get_normal[4])(struct s_obj, t_inter);	//	defines.h
}					t_data;
t_data				*g_data;

/*
**	To add colors
*/
typedef struct		s_added
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_added;

/*
**	To handle keyboard events
*/
typedef struct		s_funar_keyb
{
	int				key;	// key index
	void			(*f)(t_data*);	// function to call when key is pushed
}					t_funar_keyb;

/*
**	To make widgets for UI usage
*/
typedef struct		s_wid_data
{
	t_point			pos;
	t_point			size;
	t_ptdb			min_max;
	double			step;
	GtkWidget		*grid;
	gpointer		param;
	void			(*f)(GtkWidget*, gpointer);
	void			(*entry_f)(GtkWidget*, GdkEvent*, gpointer);
}					t_wid_data;

#endif
