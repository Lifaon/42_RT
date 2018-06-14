/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_px_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 05:22:06 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/14 19:38:24 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/*
**	light_path_is_blocked() currently ignores the intersected object, so it
**	can't intersect with itself. But if we create objects which can put shadows
**	on themselves, this method won't work anymore.
*/

static int		light_path_is_blocked(t_data *data, t_inter inter, t_vec *light)
{
	int		i;
	double	len;

	i = -1;
	len = get_length(*light);
	*light = vec_normalize(*light);
	inter.min_dist = 0;
	while (++i < data->nb_objects)
	{
		if (i == inter.obj_i)
			continue ;
		inter.oc = vec_substract(inter.ip, data->objs[i].pos);
		if (data->objs[i].intersect(data->objs[i], *light, &inter) && \
			inter.t < len)
			return (1);
	}
	return (0);
}

static t_color	shade(t_data *data, t_camera cam, t_inter *inter, t_light light)
{
	t_color	ret;
	t_vec	light_vec;
	double	dot;

	ret = ambient_shading(data->objs[inter->obj_i], light);
	light_vec = vec_substract(light.pos, inter->ip);
	if (light_path_is_blocked(data, *inter, &light_vec))
		return (ret);
	dot = dot_product(light_vec, inter->normal);
	if (dot <= 0)
		return (ret);
	ret = add_colors(ret, diffuse_shading(data->objs[inter->obj_i], dot));
	inter->spec = add_colors(inter->spec, specular_shading(\
		cam, data->objs[inter->obj_i], light_vec, *inter));
	return (ret);
}

int				get_px_color(t_data *data, t_camera cam, t_inter inter)
{
	t_color		ret;
	t_vector	added;
	int			i;

	if (!data->nb_lights)
		return (col_multiply(data->objs[inter.obj_i].color, 0.3).c);
	added = (t_vector){0, 0, 0};
	i = -1;
	inter.spec.c = 0;
	while (++i < data->nb_lights)
	{
		ret = shade(data, cam, &inter, data->lights[i]);
		added.x += ret.argb.r;
		added.y += ret.argb.g;
		added.z += ret.argb.b;
	}
	ret.argb.r = added.x / data->nb_lights;
	ret.argb.g = added.y / data->nb_lights;
	ret.argb.b = added.z / data->nb_lights;
	ret = add_colors(ret, inter.spec);
	return (ret.c);
}
