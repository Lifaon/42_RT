/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:34:18 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/14 19:50:15 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_color	ambient_shading(t_obj obj, t_light light)
{
	return (col_multiply(obj.color, light.ambi));
}

t_color	diffuse_shading(t_obj obj, double dot)
{
	return (col_multiply(obj.color, dot));
}

t_color	specular_shading(t_camera cam, t_obj obj, t_vec light, t_inter inter)
{
	t_color	ret;
	t_vec	r;
	t_vec	v;
	double	dot;

	ret.c = get_color_gtk(255, 255, 255, 255);
	ret = col_multiply(ret, obj.spec);
	r = vec_normalize(vec_substract(\
			vec_multiply(inter.normal, dot_product(inter.normal, light) * 2.0),\
			light));
	v = vec_normalize(vec_substract(cam.pos, inter.ip));
	dot = dot_product(v, r);
	if (dot > 0)
		ret = col_multiply(ret, pow(dot, obj.alpha));
	else
		ret.c = 0;
	return (ret);
}
