/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:34:18 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/12 23:17:19 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_color	ambient_shading(t_color color, t_light light)
{
	return (substract_colors(col_multiply(color, light.ambi), \
		light.color_neg));
}

t_color	diffuse_shading(t_color color, t_light light, double dot)
{
	if (g_data->cel_shading && g_data->px < 2)
	{
		if (dot >= 0.5)
			return (substract_colors(col_multiply(color, 0.8), light.color_neg));
		else
			dot = (double)(int)((dot + 0.2) * 10) / 10;
	}
	return (substract_colors(col_multiply(color, dot), light.color_neg));
}

t_color	specular_shading(t_obj obj, t_color color, t_vec light, t_inter inter)
{
	t_color	ret;
	t_vec	r;
	t_vec	v;
	double	dot;

	ret = col_multiply(color, obj.spec);
	r = vec_normalize(vec_substract(\
			vec_multiply(inter.normal, dot_product(inter.normal, light) * 2.0),\
			light));
	v = vec_normalize(vec_substract(g_data->cam.pos, inter.ip));
	dot = dot_product(v, r);
	if (dot > 0)
		ret = col_multiply(ret, pow(dot, obj.alpha));
	else
		ret.c = 0;
	return (ret);
}
