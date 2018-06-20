/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:27:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/19 19:10:40 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "libft.h"
# include "libpt.h"
# include "mygtk.h"
# include "structs.h"
# include "defines.h"

/*
**	Functions for create User Interface and event associated
*/
int				create_ui(void);
int				create_sub_notebook(t_ui *ui);
int				create_toolbar(GtkWidget *v_box, t_ui *ui);
int				create_light_ui(GtkWidget *main_tab);
int				create_object_ui(GtkWidget *main_tab);
int				create_camera_ui(GtkWidget *main_tab);

/*
** tool used to create widget or group of widget
*/

void			set_wid_data(t_wid_data *wid_d, t_point pos, t_point size,
t_widget_vec	*wid_vec_new(GtkSizeGroup *group, t_vec *vec);
				void (*f)(GtkWidget*, gpointer));
GtkWidget		*switch_new(t_wid_data *wid_d, gpointer param, gboolean state,
		void (*f)(GtkWidget*, gboolean, gpointer));
GtkWidget		*tgb_new(t_wid_data *wid_d, gpointer param, const char *txt);
GtkWidget		*scale_new(t_wid_data *wid_d, gpointer param, t_ptdb min_max,
				gdouble step);
GtkWidget		*entry_new(t_wid_data *wid_d, gpointer param,  const char *txt);
GtkWidget		*l_new(t_wid_data *wid_d, const char *txt);
void			switch_parallel_light(GtkWidget *widget, gboolean state,
		gpointer param);
GtkSizeGroup	*add_vector_choose(t_wid_data *wid_d, char *label, t_vec vec);
int				add_one_light_tab(GtkWidget *tab_light, int index);
void			add_one_light(GtkWidget *widget, gpointer param);

/*
** Simple function to handle number and string for specific matters 
*/
char			*join_int(char const *s1, int n);
size_t			size_int(int n);
size_t			size_double(double n);
size_t			size_vec(t_vec vec);
size_t			size_color(t_color color);
size_t			size_of_str_json(void);
char			*my_strcopy(char *dest, char const *src);
char			*strcpy_db(char *str, double n);
char			*strcpy_vec(char *str, t_vec vec);
char			*color_toa(char *str, t_color color);

/*
** function for handle user interface event :
** =>toolbar event
*/
void			click_open(GtkWidget *widget, gpointer param);
void			click_save(GtkWidget *widget, gpointer param);
void			click_export(GtkWidget *widget, gpointer param);
void			click_redraw(GtkWidget *widget, gpointer param);
void			entry_change_scale(GtkWidget *widget, gpointer param);
size_t			size_of_str_json(void);
char			*fill_object_json(char *str, int type, int i);
int				size_of_object_json(int size, int type, int i);
char			*fill_str_json(size_t size);
int				fill_widget_vec(t_widget_vec *dst, GtkSizeGroup *group,
		t_vec *vec);

/*
** => Other UI event
*/
gboolean	change_page_light(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data);
int				make_entry_and_scale(t_wid_data *wid_d, const char *txt,
			GtkSizeGroup *group, gdouble value);
void			change_vec_from_scale(GtkSizeGroup *group, t_vec *vec);
void			change_light_pos(GtkWidget *widget, gpointer param);
void			change_light_dir(GtkWidget *widget, gpointer param);
void			free_to_free(void *content);
void			switch_light(GtkWidget *widget, gboolean state, gpointer param);
#endif
