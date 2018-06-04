/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:56:18 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/04 16:17:04 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "structs.h"
# include "vec.h"

/*
**	Function called in draw_image.c.
*/
int		get_px_color(t_data *data, t_inter inter);

/*
**	Phong shading.
*/
t_color	ambient_shading(t_obj obj, t_light light);
t_color	diffuse_shading(t_obj obj, double dot);
t_color	specular_shading(t_camera cam, t_obj obj, t_vec light, t_inter inter);

/*
**	Functions used for color management.
*/
t_color	add_colors(t_color col1, t_color col2);
t_color	blend_colors(t_color col1, t_color col2);
t_color	col_multiply(t_color color, double nb);
t_color	col_divide(t_color color, double nb);

#endif
