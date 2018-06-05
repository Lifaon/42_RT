/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:10:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/04 17:21:36 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "rtv1.h"
# include "structs.h"

/*
**	Functions used to handle events.
*/
t_funar_keyb	*fill_funar_key_event(int *size);
int				ft_mouse_wheel(int y, t_data *data);
int				ft_mouse(int x, int y, t_data *data);
int				ft_keyboard(int key, t_data *data);

/*
**	Rotation functions.
*/
void			rotate_x(t_data *data);
void			rotate_y(t_data *data);
void			get_vp_up_left(t_camera *cam);

#endif
