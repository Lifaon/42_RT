/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:56:18 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/24 21:11:22 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "structs.h"
# include "vec.h"
# define B 0x100
# define BM 0xff
# define N 0x1000
# define NM 0xfff

/*
**	Drawing functions.
*/
void	draw_image(void);
void	draw_pixelated_image(t_data *data);
void	get_photon_map(void);
t_color	get_px_color(t_data *data, t_vec ray, t_inter inter);
t_color	shadow(t_light light, t_inter inter, t_vec ray, double len);
t_color	anti_aliasing(t_data *data, t_vec vp);
t_color	draw_reflec(t_data *data, t_inter *inter, t_color ret, t_vec ray);
t_color	draw_refract(t_data *data, t_inter *inter, t_color ret, t_vec ray);
t_vec	get_refrac_ray(t_data *data, t_inter *inter, t_vec ray);

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
**	Object filters.
*/
t_color	checkerboard(t_obj obj, t_vec ray, t_inter *inter);
t_color	rainbow(t_obj obj, t_vec ray, t_inter *inter);

/*
**	Scene filters.
*/
void	cel_shading(void);
void	get_stereo(void);
void	sepia(t_data *data);
void	black_and_white(t_data *data);
void	blur(t_data *data);

/*
**	Perlin
*/
t_color	ft_perlin(t_obj obj, t_color color, t_inter *inter);
t_color	color_mod(double coef, t_obj obj);
double	lerp(double t, double a, double b);
double	curve(const double t);
double	at3(const float *v, const double x, const double y, const double z);
float	noise(float vecx, float vecy, float vecz);
float	noise_vec(float vec[3]);
void	get_d(t_perlin *p, float grad3[B + B + 2][3]);
void	get_c(t_perlin *p, float grad3[B + B + 2][3]);
void	get_a(t_perlin *p, int i, float grad3[B + B + 2][3]);
void	setup_x(t_perlin *p, float vecx);
void	setup_y(t_perlin *p, float vecy);
void	setup_z(t_perlin *p, float vecz);

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
