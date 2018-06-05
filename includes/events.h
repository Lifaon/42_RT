/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:10:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/04 16:18:59 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "structs.h"
# include "rtv1.h"

/*
**	Functions used to handle events.
*/
t_funar_keyb	*fill_funar_key_event(int *size);
int				ft_mouse_wheel(int y, t_data *data);
int				ft_mouse(int x, int y, t_data *data);
int				ft_keyboard(int key, t_data *data);
void			translateW(t_data *data);
void			translateA(t_data *data);
void			translateS(t_data *data);
void			translateD(t_data *data);
void			translateQ(t_data *data);
void			translateE(t_data *data);

/*
**	Function to call during translations.
*/
void			choose_cam(t_data *data, int index);

/*
**	Frees everything that has to be freed.
*/
void			exit_all(t_data *data);

#endif
