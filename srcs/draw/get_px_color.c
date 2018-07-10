/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_px_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 05:22:06 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/04 00:05:41 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int		blocked(t_light light, t_inter inter, t_vec *vec, double *dot)
{
	int		i;
	double	len;

	i = -1;
	if (light.is_para)
		len = INFINITY;
	else
		len = get_length(*vec);
	*vec = vec_normalize(*vec);
	*dot = dot_product(inter.normal, *vec);
	if (*dot <= 0)
		return (1);
	if (other_hit(g_data, *vec, &inter) && inter.t < len)
		return (1);
	return (0);
}

static t_color	shade(t_data *data, t_inter *inter, t_light light)
{
	t_color	color;
	t_color	ret;
	t_vec	light_vec;
	double	dot;

	color = inter->color;
	inter->origin = inter->ip;
	ret = ambient_shading(color, light);
	if (light.is_para)
		light_vec = light.dir;
	else
		light_vec = vec_substract(light.pos, inter->ip);
	if (blocked(light, *inter, &light_vec, &dot))
		return (ret);
	ret = add_colors(ret, diffuse_shading(color, light, dot));
	inter->spec = add_colors(inter->spec, specular_shading(\
		data->objs[inter->obj_i], light.color, light_vec, *inter));
	return (ret);
}

t_color			get_px_color(t_data *data, t_inter inter)
{
	t_color		ret;
	t_added		added;
	int			i;

	if (!data->nb_lights || !data->nb_lights_on)
		return (col_multiply(data->objs[inter.obj_i].color, 0.3));
	call_perlin(*data);
	added = (t_added){0, 0, 0, 0};
	i = -1;
	inter.spec.c = 0;
	while (++i < data->nb_lights)
	{
		if (data->lights[i].disabled)
			continue ;
		ret = shade(data, &inter, data->lights[i]);
		added.r += ret.argb.r;
		added.g += ret.argb.g;
		added.b += ret.argb.b;
		added.a += ret.argb.a;
	}
	ret.argb.r = added.r / data->nb_lights_on;
	ret.argb.g = added.g / data->nb_lights_on;
	ret.argb.b = added.b / data->nb_lights_on;
	ret.argb.a = added.a / data->nb_lights_on;
	ret = add_colors(ret, inter.spec);
	return (ret);
}
