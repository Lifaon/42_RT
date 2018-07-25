/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_gdk_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 22:38:19 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/25 14:42:24 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "rtv1.h"

void	put_gdk_image(void)
{
	if (g_data->clust_i == CLUST_HOST)
		host_work(1);
	else
	{
		if (g_data->px > 1)
			draw_pixelated_image(g_data);
		else if (g_data->cel_shading)
			cel_shading();
		else if (g_data->depth_of_field >= 0 \
				&& g_data->depth_of_field < g_data->nb_objects)
			depth_of_field();
		else
			draw_image();
		if (g_data->filter == FILTER_BNW)
			black_and_white(g_data);
		else if (g_data->filter == FILTER_SEPIA)
			sepia(g_data);
		else if (g_data->filter == FILTER_STEREO)
			get_stereo();
	}
	if (g_data->clust_i == CLUST_NONE)
	{
		put_pixelbuf_to_widget(g_data->img, NULL);
		gtk_widget_show_all(g_data->win);
	}
}
