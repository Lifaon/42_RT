/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:10:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/14 19:10:29 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "rtv1.h"
# include "structs.h"
# include "rtv1.h"

# define ANGLE 5.0
# define TRANSLATION 150

/*
**	Functions used to handle events.
*/
t_funar_keyb	*fill_funar_key_event(int *size);
int				ft_keyboard(int key, t_data *data);

/*
**	Translation functions.
*/
void			translate_w(t_data *data);
void			translate_a(t_data *data);
void			translate_s(t_data *data);
void			translate_d(t_data *data);
void			translate_e(t_data *data);
void			translate_q(t_data *data);
void			get_oc(t_data *data, t_camera cam);
void			get_vp_up_left(t_camera *cam);

/*
**	Rotation functions.
*/
void			rotate_up(t_data *data);
void			rotate_left(t_data *data);
void			rotate_down(t_data *data);
void			rotate_right(t_data *data);

/*
**	Enabling pixelation and anti-aliasing.
*/
void			pixelate(t_data *data);
void			anti_alias(t_data *data);

#endif
