/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 09:36:28 by vtudes            #+#    #+#             */
/*   Updated: 2018/07/21 10:17:51 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_color	ft_perlin(t_obj obj, t_color color, t_inter *inter)
{
	double	coef;
	int		level;
	float	vec[3];
	t_color ret;

	coef = 0;
	vec[0] = inter->ip.x * 0.05;
	vec[1] = inter->ip.y * 0.05;
	vec[2] = inter->ip.z * 0.05;
	level = 1;
	while (++level < 40)
		coef += (1.0 / level) * fabs(noise_vec(vec));
	if (obj.perl_type == PERLIN_CLASSIC)
		coef = (double)obj.perl_scale * 0.01 * coef + 1. - obj.perl_opacity;
	else
		coef = obj.perl_opacity * cos((inter->ip.x + inter->ip.y + inter->ip.z)\
			* ((double)obj.perl_scale * .0005) + coef) + 0.9;
	if (coef < 0)
		coef = 0;
	else if (coef > 1)
		coef = 1;
	return (col_multiply(obj.color, coef));
}

t_vec	bump_mapping(t_inter inter)
{
	float x;
	float y;
	float z;
	float bump_coef;
	float noise_scale;
	t_vec temp;


	bump_coef = 0.5;
	noise_scale = 0.1;

	x = noise(noise_scale * inter.ip.x, noise_scale * inter.ip.y, noise_scale * inter.ip.z);
	y = noise(noise_scale * inter.ip.y, noise_scale * inter.ip.z, noise_scale * inter.ip.x);
	z = noise(noise_scale * inter.ip.z, noise_scale * inter.ip.x, noise_scale * inter.ip.y);

	inter.normal.x = (1.0 - bump_coef) * inter.normal.x + bump_coef * x;
	inter.normal.y = (1.0 - bump_coef)* inter.normal.y + bump_coef * y;
	inter.normal.z = (1.0 - bump_coef) * inter.normal.z + bump_coef * z;
	inter.normal = vec_normalize(inter.normal);
	return (inter.normal);
}
