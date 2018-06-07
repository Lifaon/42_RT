/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:36:34 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/07 18:06:19 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static t_color	blend(t_color colors[256], int size)
{
	t_color ret;
	t_vec	added;
	int		i;

	i = -1;
	added = (t_vec){0, 0, 0};
	while (++i < size)
	{
		//ft_putnbr(i);
		added.x += colors[i].argb.r;
		added.y += colors[i].argb.g;
		added.z += colors[i].argb.b;
	}
	ret.argb.r = added.x / size;
	ret.argb.g = added.y / size;
	ret.argb.b = added.z / size;
	return (ret);
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
			if (hit(data, ray, &inter))
				colors[px.x + (px.y * data->aa)].c = get_px_color(data, inter);
			else
				colors[px.x + (px.y * data->aa)].c = 0;
		}
	}
	return (blend(colors, data->aa * data->aa).c);
}
