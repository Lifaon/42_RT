/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 00:19:15 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/13 03:54:14 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	black_and_white(t_data *data)
{
	t_color	color;
	int		added;
	int		i;
	int		size;

	i = -1;
	size = data->img->size.x * data->img->size.y;
	while (++i < size)
	{
		color.c = data->img->pxl[i];
		added = (color.argb.r + color.argb.g + color.argb.b) / 3;
		color.argb.r = added;
		color.argb.g = added;
		color.argb.b = added;
		data->img->pxl[i] = color.c;
	}
}

void	sepia(t_data *data)
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
