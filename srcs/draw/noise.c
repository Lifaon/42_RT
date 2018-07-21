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

t_vec	bump_mapping(t_inter inter, t_vec normal)
{
	t_vec vec;
	t_vec ret;

	vec.x = vec.x + inter.ip.x;
	vec.y = 50 * vec.y + 100 * inter.ip.y;
	vec.z = vec.z + inter.ip.z;
	//printf("x : %f \n y : %f \n z : %f \n", inter.ip.x, inter.ip.y, inter.ip.z);
	ret.x = noise(vec.x - 0.001f, vec.y, vec.z) - noise(vec.x + 0.001f, vec.y, vec.z);
	ret.y = noise(vec.x, vec.y - 0.001f, vec.z) - noise(vec.x, vec.y + 0.001f, vec.z);
	ret.z = noise(vec.x, vec.y, vec.z - 0.001f) - noise(vec.x, vec.y, vec.z + 0.001f);
	normal.x = normal.x + ret.x;
	normal.y = normal.y + ret.y;
	normal.z = normal.z + ret.z;
	vec_normalize(normal);
	return (normal);
}
