/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:44:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/29 18:37:29 by fchevrey         ###   ########.fr       */
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
t_color			add_colors(t_color col1, t_color col2);
t_color			blend_colors(t_color col1, t_color col2);
t_color			col_multiply(t_color color, double nb);
t_color			col_divide(t_color color, double nb);

/*
**	Frees everything that has to be freed.
*/
void			exit_all(t_data *data);

/*
**	Functions for create User Interface and event associated
*/
int				create_ui(void);
int				create_sub_notebook(t_ui *ui);
int				create_toolbar(GtkWidget *v_box, t_ui *ui);
void			set_wid_data(t_wid_data *wid_d, t_point pos, t_point size,
				void (*f)(GtkWidget*, gpointer));
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
char			*my_strcopy(char *dest, char const *src);
size_t			size_int(int n);
size_t			size_double(double n);
size_t			size_vec(t_vec vec);
size_t			size_color(t_color color);
size_t			size_of_str_json(void);
char			*strcpy_db(char *str, double n);
char			*strcpy_vec(char *str, t_vec vec);
char			*color_toa(char *str, t_color color);
char			*fill_str_json(size_t size);
size_t			size_of_str_json(void);
gboolean		change_page_light(GtkWidget *widget, gint arg1,  gpointer data);
#endif
