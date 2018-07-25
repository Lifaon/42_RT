/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:36:34 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/23 19:11:32 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static t_color	blend(t_color colors[256], int size)
{
	t_added	added;
	int		i;

	added = (t_added){0, 0, 0, 0};
	i = -1;
	while (++i < size)
	{
		added.r += colors[i].argb.r;
		added.g += colors[i].argb.g;
		added.b += colors[i].argb.b;
		added.a += colors[i].argb.a;
	}
	return ((t_color){.argb.r = added.r / size, .argb.g = added.g / size,\
		.argb.b = added.b / size, .argb.a = added.a / size});
}

t_color			anti_aliasing(t_data *data, t_vec vp)
{
	t_color	colors[256];
	t_inter	inter;
	t_point	px;
	t_vec	vp2;
	t_vec	r;

	px.y = -1;
	vp2.z = vp.z;
	while (++px.y < data->aa)
	{
		px.x = -1;
		vp2.y = vp.y + (double)px.y / (double)data->aa;
		while (++px.x < data->aa)
		{
			vp2.x = vp.x + (double)px.x / (double)data->aa;
			r = compute_ray(vp2);
			inter.depth = 0;
			inter.in_object = 0;
			if (first_hit(data, r, &inter))
				colors[px.x + (px.y * data->aa)] = get_px_color(data, r, inter);
			else
				colors[px.x + (px.y * data->aa)].c = 0xFF000000;
		}
	}
	return (blend(colors, data->aa * data->aa));
}
