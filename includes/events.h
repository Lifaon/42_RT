/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:10:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/07 15:04:10 by mlantonn         ###   ########.fr       */
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
void			choose_cam(t_data *data, int index);

/*
**	Rotation functions.
*/
void			rotate_i(t_data *data);
void			rotate_k(t_data *data);
void			rotate_j(t_data *data);
void			rotate_l(t_data *data);
void			get_vp_up_left(t_camera *cam);

#endif
