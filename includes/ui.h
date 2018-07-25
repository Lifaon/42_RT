/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:27:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 19:06:07 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "rtv1.h"
# include "structs.h"
# include "defines.h"

/*
**	Functions for create User Interface and event associated
*/

/*
** Parent functions
*/
int				create_ui(void);
int				create_sub_notebook(t_ui *ui);
int				create_toolbar(GtkWidget *v_box, t_ui *ui);
int				create_light_ui(GtkWidget *main_tab);
int				create_light_caustic_ui(GtkWidget *box);
int				create_object_ui(GtkWidget *main_tab);
int				obj_construct_phase_2(t_wid_data *wid_d, t_obj *obj);
int				create_object_texture_ui(t_wid_data *wid_d, t_obj *obj);
int				create_object_file_tex_ui(t_wid_data *wid_d, t_obj *obj);
int				create_limited_object_ui(t_wid_data *wid_d, t_obj *obj);
int				create_camera_ui(GtkWidget *main_tab);
int				create_options_ui(GtkWidget *main_tab);

/*
** tool used to create widget or group of widget
*/
void			set_wid_data(t_wid_data *wid_d, t_point pos, t_point size,
				void (*f)(GtkWidget*, gpointer));
void			set_wid_data_scale(t_wid_data *wid_d, double step,
		t_ptdb min_max);
int				init_wid_data(t_wid_data *wid_d, double step, t_ptdb min_max);
GtkWidget		*switch_new(t_wid_data *wid_d, gpointer param, gboolean state,
		void (*f)(GtkWidget*, gboolean, gpointer));
GtkWidget		*scale_new(t_wid_data *wid_d, gpointer param, gdouble value);
GtkWidget		*entry_new(t_wid_data *wid_d, gpointer param, const char *txt);
GtkWidget		*b_new(t_wid_data *wid_d, gpointer param, const char *txt,
		GtkWidget *img);
GtkWidget		*l_new(t_wid_data *wid_d, const char *txt);
GtkWidget		*new_cb_type(t_wid_data *wid_d, gpointer param, t_obj *obj);
GtkWidget		*new_check_button(t_wid_data *wid_d, char *txt, gpointer param,
		GtkSizeGroup *group);
GtkWidget		*new_cb_limited(t_wid_data *wid_d, gpointer param, t_obj *obj);
GtkWidget		*make_label_and_cb(t_wid_data *wid_d, char *label,
		int set_value, char **txt);
GtkSizeGroup	*add_vector_choose(t_wid_data *wid_d, char *label, t_vec vec);
GtkSizeGroup	*add_color_choose(t_wid_data *wid_d, t_color color);
GtkSizeGroup	*add_vector_choose_no_scale(t_wid_data *w_d, char *label,
		t_vec vec);
int				create_light_tab(GtkWidget *tab_light, int index);
int				create_object_tab(GtkWidget *tab_light, int index);
int				make_entry_and_scale(t_wid_data *wid_d, const char *txt,
			GtkSizeGroup *group, gdouble value);
GtkWidget		*make_label_and_entry(t_wid_data *wid_d, const char *txt,
			gdouble value, gpointer param);
GtkWidget		*make_label_and_scale(t_wid_data *wid_d, const char *txt,
			gdouble value, gpointer param);
GtkWidget		*make_label_and_switch(t_wid_data *wid_d, const char *txt,
			gboolean value, void (*f)(GtkWidget*, gboolean, gpointer));

/*
** basic tool
*/
int				get_int_obj_type(const char *type);
char			*get_str_obj_type(int type);

/*
** Simple function to handle number and string for json editor
*/
char			*join_int(char const *s1, int n);
size_t			size_int(int n);
size_t			size_double(double n);
size_t			size_pt(t_point pt);
size_t			size_vec(t_vec vec);
size_t			size_color(t_color color);
size_t			size_of_str_json(void);
size_t			size_of_options_json(void);
size_t			size_of_objects_json(void);
size_t			size_of_object_common_json(t_obj *obj);
char			*my_strcopy(char *dest, char const *src);
char			*strcpy_db(char *str, double n);
char			*strcpy_vec(char *str, t_vec vec);
char			*strcpy_int(char *str, int n);
char			*strcpy_pt(char *str, t_point pt);
char			*strcpy_color(char *str, t_color color);
char			*fill_object_common_json(char *str, t_obj *obj);
char			*fill_objects_json(char *str);
char			*fill_str_json(size_t size);
char			*fill_options_json(char *str);

/*
** function for handle user interface event :
** =>toolbar event
*/
void			click_open(GtkWidget *widget, gpointer param);
void			click_save(GtkWidget *widget, gpointer param);
void			click_export(GtkWidget *widget, gpointer param);
void			click_redraw(GtkWidget *widget, gpointer param);

/*
** => light event
*/
void			add_one_light(GtkWidget *widget, gpointer param);
void			check_caustic(GtkWidget *widget, gpointer param);
void			change_total_photon(GtkWidget *widget, gpointer param);
void			change_photon_size(GtkWidget *widget, gpointer param);
void			change_photon_intensity(GtkWidget *widget, gpointer param);
void			change_light_pos(GtkWidget *widget, gpointer param);
void			change_light_angle(GtkWidget *widget, gpointer param);
void			change_light_r(GtkWidget *widget, GdkEvent *event,
		gpointer param);
void			change_light_color(GtkWidget *widget, gpointer param);
void			change_light_ambi(GtkWidget *widget, gpointer param);
void			switch_light(GtkWidget *widget, gboolean state, gpointer param);
void			switch_parallel_light(GtkWidget *widget, gboolean state,
		gpointer param);

/*
** => Object event
*/
void			add_one_obj(GtkWidget *widget, gpointer param);
void			change_obj_pos(GtkWidget *widget, gpointer param);
void			change_obj_angle(GtkWidget *widget, gpointer param);
void			switch_obj(GtkWidget *widget, gboolean state, gpointer param);
void			modify_obj_type(GtkWidget *widget, gpointer param);
void			change_obj_spec(GtkWidget *widget, gpointer param);
void			change_obj_alpha(GtkWidget *widget, gpointer param);
void			change_obj_focus(GtkWidget *widget, gpointer param);
void			change_obj_r(GtkWidget *widget, GdkEvent *event,
		gpointer param);
void			change_obj_trans(GtkWidget *widget, gpointer param);
void			change_obj_ior(GtkWidget *widget, gpointer param);
void			change_obj_reflex(GtkWidget *widget, gpointer param);
void			change_obj_color(GtkWidget *widget, gpointer param);
void			change_obj_color2(GtkWidget *widget, gpointer param);
void			switch_obj_limited(GtkWidget *widget, gboolean state,
		gpointer param);
void			modify_obj_limited_type(GtkWidget *widget, gpointer param);
void			change_obj_min(GtkWidget *widget, GdkEvent *event,
		gpointer param);
void			change_obj_max(GtkWidget *widget, GdkEvent *event,
		gpointer param);
void			check_tex_file(GtkWidget *widget, gpointer param);
void			change_obj_tex_file(GtkWidget *widget, gpointer param);
void			change_obj_tex_scale(GtkWidget*widget, gpointer param);
void			change_obj_tex_pos_x(GtkWidget *widget, GdkEvent *event,
		gpointer param);
void			change_obj_tex_pos_y(GtkWidget *widget, GdkEvent *event,
		gpointer param);
void			switch_obj_tex_repeat(GtkWidget *widget, gboolean state,
		gpointer param);
void			switch_obj_tex_trans(GtkWidget *widget, gboolean state,
		gpointer param);
void			change_color_scale(GtkWidget *widget, gpointer param);
void			check_rainbow(GtkWidget *widget, gpointer param);
void			check_checkboard(GtkWidget *widget, gpointer param);
void			check_perlin(GtkWidget *widget, gpointer param);
void			check_perlin_cosine(GtkWidget *widget, gpointer param);
void			change_perlin_scale(GtkWidget *widget, gpointer param);
void			change_perlin_opacity(GtkWidget *widget, gpointer param);
void			check_bump(GtkWidget *widget, gpointer param);
void			change_bump_scale(GtkWidget *widget, gpointer param);
void			change_bump_noise(GtkWidget *widget, gpointer param);

/*
** => options event
*/
void			get_int_from_scale(GtkWidget *widget, gpointer param);
void			change_aa(GtkWidget *widget, gpointer param);
void			change_px(GtkWidget *widget, gpointer param);
void			switch_cel_shading(GtkWidget *widget, gboolean state,
		gpointer param);
void			change_filter(GtkWidget *widget, gpointer param);
t_vec			pitch(t_vec ray, t_vec angle);
t_vec			yaw(t_vec ray, t_vec angle);
t_vec			roll(t_vec ray, t_vec angle);
void			change_depth_max(GtkWidget *widget, gpointer param);
void			change_dof_coeff(GtkWidget *widget, gpointer param);
void			get_vp_up_left(t_camera *cam);
void			change_stereo_scale(GtkWidget *widget, gpointer param);

/*
** => camera event
*/
void			change_left_cam(GtkWidget *widget, gpointer param);
void			change_right_cam(GtkWidget *widget, gpointer param);
void			change_cam_fov(GtkWidget *widget, gpointer param);
void			change_cam_angle(GtkWidget *widget, gpointer param);
void			change_cam_pos(GtkWidget *widget, gpointer param);

/*
** => Other UI event
*/
void			chose_color(GtkWidget *widget, gpointer param, t_light *light);
gboolean		change_page_light(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data);
gboolean		change_page_cam(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data);
gboolean		change_page_obj(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data);
void			change_vec_from_entry(GtkSizeGroup *group, t_vec *vec,
		int mode_infinity, t_ptdb limits);
void			change_vec_from_scale(GtkSizeGroup *group, t_vec *vec);
void			change_color_from_group(GtkSizeGroup *group, t_color *color);
double			get_double_from_entry(GtkWidget *wid, int infinity_mode,
		double min, double max);
void			set_group_widget_active(GtkSizeGroup *group, gboolean status);
void			set_child_widget_active(GtkContainer *container, \
		gboolean status);
void			set_entry_and_scale_from_vector(GtkSizeGroup *group,
		t_vec vec);
void			entry_change_scale(GtkWidget *widget, GdkEvent *event,
		gpointer param);
void			scale_img(const t_pixelbuf *src, t_pixelbuf *dst,
		t_point new_size, GdkInterpType type);
void			file_error(GtkWidget *select);

#endif
