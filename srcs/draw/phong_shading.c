/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:34:18 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/31 17:12:46 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color	ambient_shading(t_data *data, int light_i, int index)
{
	return (col_multiply(data->objs[index].color, data->lights[light_i].ambi));
}

t_color	diffuse_shading(t_data *data, double dot, int index)
{
	return (col_multiply(data->objs[index].color, dot));
}

t_color	specular_shading(t_data *data, int index, t_inter inter, t_vec light)
{
	t_color	ret;
	t_vec	r;
	t_vec	v;
	double	dot;

	ret.c = 0xFFFFFF;
	ret = col_multiply(ret, data->objs[index].spec);
	r = vec_normalize(vec_substract(\
			vec_multiply(inter.normal, dot_product(inter.normal, light) * 2.0),\
			light));
	v = vec_normalize(vec_substract(data->cams[data->i].pos, inter.ip));
	dot = dot_product(v, r);
	if (dot > 0)
		ret = col_multiply(ret, pow(dot, data->objs[index].alpha));
	else
		ret.c = 0;
	return (ret);
}
