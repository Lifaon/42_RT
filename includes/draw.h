/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:56:18 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/12 04:58:35 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "structs.h"
# include "vec.h"

/*
**	Drawing functions.
*/
void	draw_image(void);
void	draw_pixelated_image(t_data *data);
void	cel_shading(void);
t_color	get_px_color(t_data *data, t_vec ray, t_inter inter);
t_color	shadow(t_light light, t_inter inter, t_vec ray, double len);
t_color	anti_aliasing(t_data *data, t_vec vp);
t_color	draw_reflec(t_data *data, t_inter *inter, t_color ret, t_vec ray);
t_color	draw_refract(t_data *data, t_inter *inter, t_color ret, t_vec ray);

/*
**	Phong shading.
*/
t_color	ambient_shading(t_color color, t_light light);
t_color	diffuse_shading(t_color color, t_light light, double dot);
t_color	specular_shading(t_obj obj, t_color color, t_vec light, t_inter inter);

/*
**	Depth_of_field function. This function takes 3D coordinates which represent
**	the focal point of the image.
*/
void	depth_of_field();

/*
**	Filters.
*/
void	blur(t_data *data);
void	sepia(t_data *data);
void	black_and_white(t_data *data);

/*
**	Functions used for color management.
*/
t_color	add_colors(t_color col1, t_color col2);
t_color	substract_colors(t_color col1, t_color col2);
t_color	blend_colors(t_color col1, t_color col2);
t_color	col_multiply(t_color color, double nb);
t_color	col_divide(t_color color, double nb);
t_color	blend_coeff(t_color old, t_color new, double coeff);

void	exit_all(t_data *data);

#endif
