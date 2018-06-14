/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:44:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/14 19:47:21 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	RTv1 is a school project designed to learn the basics of raytracing.
*/

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "libpt.h"
# include "mygtk.h"

# include "structs.h"
# include "defines.h"

t_data			*g_data;


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
**	Drawing function.
*/
void			draw_image(t_data *data);

/*
**	Function used to handle events.
*/
void			ft_event(t_data *data);

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
void			switch_parallel_light(GtkWidget *widget, gboolean state,
		gpointer param);
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
gboolean	change_page_light(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data);
void			click_redraw(GtkWidget *widget, gpointer param);
int				make_entry_and_scale(t_wid_data *wid_d, const char *txt,
			GtkSizeGroup *group, gdouble value);
int				fill_widget_vec(t_widget_vec *dst, GtkSizeGroup *group,
		t_vec *vec);
void			change_vec_from_scale(GtkSizeGroup *group, t_vec *vec);
void			change_light_pos(GtkWidget *widget, gpointer param);
void			change_light_dir(GtkWidget *widget, gpointer param);
t_widget_vec	*wid_vec_new(GtkSizeGroup *group, t_vec *vec);
void			free_to_free(void *content);
GtkSizeGroup	*add_vector_choose(t_wid_data *wid_d, char *label, t_vec vec);
int				add_one_light_tab(GtkWidget *tab_light, int index);
void			add_one_light(GtkWidget *widget, gpointer param);
void			switch_light(GtkWidget *widget, gboolean state, gpointer param);
GtkWidget	*switch_new(t_wid_data *wid_d, gpointer param, gboolean state,
		void (*f)(GtkWidget*, gboolean, gpointer));
#endif
