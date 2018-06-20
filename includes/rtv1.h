/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:44:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/20 20:07:43 by fchevrey         ###   ########.fr       */
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

/*
**	Function used to parse the given file.
*/
void			parse(t_data *data, char *file_name);

/*
**	Functions used to initialize the different structures.
*/
t_data			*data_init(int ac, char **av);
void			get_oc(void);

/*
**	Drawing functions.
*/
void			put_gdk_image(void);

/*
**	Function used to handle events.
*/
void			ft_event(t_data *data);

/*
**	Frees everything that has to be freed.
*/
void			exit_all(t_data *data);

#endif
