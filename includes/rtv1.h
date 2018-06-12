/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:44:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/12 16:02:57 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	RTv1 is a school project designed to learn the basics of raytracing.
*/

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "libpt.h"
# include "libmysdl.h"

# include "structs.h"
# include "defines.h"

/*
**	Function used to initialize everything.
*/
void	data_init(t_data *data, int ac, char **av);

/*
**	Function used to parse the given file.
*/
void	parse(t_data *data, char *file_name);

/*
**	Drawing functions.
*/
void	draw_image(t_data *data);
void	draw_pixelated_image(t_data *data);

/*
**	Function used to handle events.
*/
void	ft_event(t_data *data);

/*
**	Frees everything that has to be freed.
*/
void	exit_all(t_data *data);

#endif
