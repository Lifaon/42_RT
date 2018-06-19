/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:36:34 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/19 18:21:43 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static t_color	blend(t_color colors[256], int size)
{
	int	r;
	int	g;
	int	b;
	int	a;
	int	i;

	i = -1;
	r = 0;
	g = 0;
	b = 0;
	a = 0;
	while (++i < size)
	{
		r += colors[i].argb.r;
		g += colors[i].argb.g;
		b += colors[i].argb.b;
		a += colors[i].argb.a;
	}
	return ((t_color){.argb.r = r / size, .argb.g = g / size,\
		.argb.b = b / size, .argb.a = a / size});
}

int				anti_aliasing(t_data *data, t_vec vp)
{
	t_color	colors[256];
	t_inter	inter;
	t_point	px;
	t_vec	vp2;
	t_vec	ray;

	inter.min_dist = 0;
	px.y = -1;
	vp2.z = vp.z;
	while (++px.y < data->aa)
	{
		px.x = -1;
		vp2.y = vp.y + (double)px.y / (double)data->aa;
		while (++px.x < data->aa)
		{
			vp2.x = vp.x + (double)px.x / (double)data->aa;
			ray = compute_ray(vp2, data->cams[data->i]);
			if (hit(data, data->cams[data->i], ray, &inter))
				colors[px.x + (px.y * data->aa)].c = \
					get_px_color(data, data->cams[data->i], inter);
			else
				colors[px.x + (px.y * data->aa)].c = 0xFF000000;
		}
	}
	return (blend(colors, data->aa * data->aa).c);
}
