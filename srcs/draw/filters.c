/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 00:19:15 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/24 17:24:50 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void		black_and_white(t_data *data)
{
	t_color	color;
	int		added;
	t_point	crd;
	int		xmax;

	crd.y = -1;
	xmax = (WIN_W / (data->nb_client + 1)) * (data->x + 1) + 1;
	while (++crd.y < WIN_H)
	{
		crd.x = (WIN_W / (g_data->nb_client + 1)) * g_data->x;
		while (++crd.x < xmax)
		{
			if (data->clust_i == CLUST_CLIENT)
				color.c = data->cimg[(int)(crd.x + crd.y * WIN_W)];
			else
				color.c = data->img->pxl[(int)(crd.x + crd.y * WIN_W)];
			added = (color.argb.r + color.argb.g + color.argb.b) / 3;
			color.argb.r = added;
			color.argb.g = added;
			color.argb.b = added;
			if (data->clust_i == CLUST_CLIENT)
				data->cimg[(int)(crd.x + crd.y * WIN_W)] = color.c;
			else
				data->img->pxl[(int)(crd.x + crd.y * WIN_W)] = color.c;
		}
	}
}

void		sepia(t_data *data)
{
	t_color	color;
	t_added	sepia;
	int		i;
	int		size;

	i = -1;
	size = data->img->size.x * data->img->size.y;
	while (++i < size)
	{
		color.c = data->img->pxl[i];
		sepia.r = (color.argb.r * .393 + color.argb.g * .769 + \
			color.argb.b * .189);
		sepia.g = (color.argb.r * .349 + color.argb.g * .686 + \
			color.argb.b * .168);
		sepia.b = (color.argb.r * .272 + color.argb.g * .534 + \
			color.argb.b * .131);
		color.argb.r = sepia.r < 255 ? sepia.r : 255;
		color.argb.g = sepia.g < 255 ? sepia.g : 255;
		color.argb.b = sepia.b < 255 ? sepia.b : 255;
		data->img->pxl[i] = color.c;
	}
}
