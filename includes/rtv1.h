/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:44:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/26 22:59:30 by fchevrey         ###   ########.fr       */
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
# include "mygtk.h"

# include "structs.h"
# include "defines.h"

t_data			*g_data;

/*
**	Drawing functions.
*/
void			draw_image(t_data *data);

/*
**	Intersection functions.
*/
int				intersect_sphere(t_obj sphere, t_vec ray, t_inter *inter);
int				intersect_plane(t_obj plane, t_vec ray, t_inter *inter);
int				intersect_cylinder(t_obj sphere, t_vec ray, t_inter *inter);
int				intersect_cone(t_obj plane, t_vec ray, t_inter *inter);
int				shadow_ray(t_data *data, t_inter inter, int index);

/*
**	Functions to get the normal of the objects at the intersection point.
*/
t_vec			get_sphere_normal(t_obj sphere, t_inter inter);
t_vec			get_plane_normal(t_obj plane, t_inter inter);
t_vec 			get_cylinder_normal(t_obj cyl, t_inter inter);
t_vec	 		get_cone_normal(t_obj cone, t_inter inter);


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

/*
**	Function used to parse the given file.
*/
void			parse(t_data *data, char *file_name);

/*
**	Functions used to initialize the different structures.
*/
t_data			*data_init(int ac, char **av);
void			choose_cam(t_data *data, int index);

/*
** Functions use to handle event
*/
void			ft_event(t_data *data);
t_funar_keyb	*fill_funar_key_event(int *size);
int				ft_mouse_wheel(int y, t_data *data);
int				ft_mouse(int x, int y, t_data *data);
int				ft_keyboard(int key, t_data *data);

/*
**	Functions used for color management.
*/
t_color	col_multiply(t_color color, double nb);
t_color col_divide(t_color color, double nb);

/*
**	Frees everything that has to be freed.
*/
void			exit_all(t_data *data);

/*
**	Functions for create User Interface and event associated
*/
int				create_ui(void);
int				create_toolbar(GtkWidget *v_box);
void			set_wid_data(t_wid_data *wid_d, t_point pos, t_point size,
				int (*f)(GtkWidget*, gpointer));
int				create_light_ui(GtkWidget *main_tab);
int				create_object_ui(GtkWidget *main_tab);
int				create_camera_ui(GtkWidget *main_tab);
GtkWidget		*tgb_new(t_wid_data *wid_d, gpointer param, const char *txt);
GtkWidget		*scale_new(t_wid_data *wid_d, gpointer param, t_ptdb min_max,
				gdouble step);
GtkWidget		*entry_new(t_wid_data *wid_d, gpointer param,  const char *txt);
GtkWidget		*l_new(t_wid_data *wid_d, const char *txt);
void			switch_parallel_light(GtkWidget *widget, gpointer param);
void			change_light_direction(GtkWidget *widget, gpointer param);
void			change_light_distance(GtkWidget *widget, gpointer param);
void			entry_change_scale(GtkWidget *widget, gpointer param);
void			click_open(GtkWidget *widget, gpointer param);
void			click_save(GtkWidget *widget, gpointer param);
void			click_export(GtkWidget *widget, gpointer param);
char			*join_int(char const *s1, int n);
#endif
