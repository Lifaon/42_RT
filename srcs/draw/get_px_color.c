/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_px_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 05:22:06 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/14 03:39:11 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int		blocked(t_light light, t_inter *inter, t_vec *vec, double *dot)
{
	t_inter	inter_tmp;
	double	len;

	len = light.is_para ? INFINITY : get_length(*vec);
	*vec = vec_normalize(*vec);
	*dot = dot_product(inter->normal, *vec);
	inter_tmp.origin = inter->origin;
	inter_tmp.min_dist = 0.01;
	if (*dot <= 0)
	{
		if (inter->trans_at_ip != 0)
			inter->shadow = shadow(light, *inter, *vec, len);
		return (1);
	}
	if (other_hit(g_data, *vec, &inter_tmp) && inter_tmp.t < len)
	{
		inter->shadow = shadow(light, *inter, *vec, len);
		return (1);
	}
	return (0);
}

static t_color	shade(t_data *data, t_vec ray, t_inter *inter, t_light light)
{
	t_color	color;
	t_color	ret;
	t_vec	light_vec;
	t_inter	tmp;
	double	dot;

	color = inter->color;
	ret = ambient_shading(color, light);
	tmp = *inter;
	tmp.origin = inter->ip;
	tmp.shadow = ret;
	light_vec = light.is_para ? light.dir : vec_substract(light.pos, inter->ip);
	if (blocked(light, &tmp, &light_vec, &dot))
		return (tmp.shadow);
	ret = add_colors(ret, diffuse_shading(color, light, dot));
	inter->spec = add_colors(inter->spec, specular_shading(\
		data->objs[inter->obj_i], light.color, light_vec, *inter));
	return (ret);
}

static t_color	refra_refrec(t_data *data, t_inter inter, t_color ret, t_vec r)
{
	if (inter.depth < data->depth_max && data->objs[inter.obj_i].shiny != 0)
		return (draw_reflec(data, &inter, ret, r));
	if (inter.depth < data->depth_max && inter.trans_at_ip != 0)
		return (draw_refract(data, &inter, ret, r));
	return (ret);
}

t_color			get_px_color(t_data *data, t_vec ray, t_inter inter)
{
	t_color		ret;
	t_added		added;
	int			i;

	if (!data->nb_lights || !data->nb_lights_on)
		return (col_multiply(data->objs[inter.obj_i].color, 0.3));
	added = (t_added){0, 0, 0, 0};
	i = -1;
	inter.spec.c = 0;
	while (++i < data->nb_lights)
	{
		if (data->lights[i].disabled)
			continue ;
		ret = shade(data, ray, &inter, data->lights[i]);
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
	return (refra_refrec(data, inter, ret, ray));
}
