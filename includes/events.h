/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:10:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/24 01:17:10 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "rtv1.h"
# include "structs.h"
# include "vec.h"

# define ANGLE 5.0
# define TRANSLATION 150

/*
**	Functions used to handle events.
*/
t_funar_keyb	*fill_funar_key_event(int *size);
//int				ft_keyboard(int key, t_data *data);
gboolean		ft_keyboard(GtkWidget *widget, GdkEventKey *event, gpointer param);

/*
**	Translation functions.
*/
void			translate_w(t_data *data);
void			translate_a(t_data *data);
void			translate_s(t_data *data);
void			translate_d(t_data *data);
void			translate_e(t_data *data);
void			translate_q(t_data *data);


/*
**	Rotation functions.
*/
void			rotate_up(t_data *data);
void			rotate_left(t_data *data);
void			rotate_down(t_data *data);
void			rotate_right(t_data *data);

/*
**	get_things.c functions.
*/
void			get_oc(void);
void			get_vp_up_left(t_camera *cam);
void			get_dir(t_obj *obj);

/*
**	Enabling pixelation and anti-aliasing.
*/
void			pixelate(t_data *data);
void			anti_alias(t_data *data);

#endif
