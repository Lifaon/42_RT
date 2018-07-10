/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:56:18 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/29 01:32:10 by mlantonn         ###   ########.fr       */
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
t_color	get_px_color(t_data *data, t_inter inter);
t_color	anti_aliasing(t_data *data, t_vec vp);
t_color	draw_reflec(t_data *data, t_inter inter, t_vec ray, int rec, t_color r);

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
void	depth_of_field(t_data *data, t_vec point);

/*
**	Filters.
*/
void	blur(t_data *data);
void	sepia(t_data *data);
void	black_and_white(t_data *data);
double	noise_3D_setup(t_perlin p);

/*
** Functions used for perlin noise/noises
*/
void		perlin_tab1(t_perlin p);
void		perlin_tab6(t_perlin p);
void		perlin_tab11(t_perlin p);
double		dot_perlin(const int *v, const double x, const double y, \
			const double z);
int			*get_grad(int x, int y, int z, t_perlin *p);
double		quintic_poly(const double t);
double		linear_interpolation(double a, double b, double t);
void		int_frac(double value, int *int_part, double *frac_part);
void		apply_perlin(t_data data);
void		call_perlin(t_data data);
double		noise_3D(double pos_x, double pos_y, double pos_z, t_perlin p);
double		noise_3D_setup(t_perlin p);
void		grad_tab(t_perlin *p);



/*
**	Functions used for color management.
*/
t_color	add_colors(t_color col1, t_color col2);
t_color	substract_colors(t_color col1, t_color col2);
t_color	blend_colors(t_color col1, t_color col2);
t_color	col_multiply(t_color color, double nb);
t_color	col_divide(t_color color, double nb);

void	exit_all(t_data *data);

#endif
