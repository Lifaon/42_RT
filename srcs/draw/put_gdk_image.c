/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_gdk_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 22:38:19 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/04 06:03:26 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "rtv1.h"

void	put_gdk_image(void)
{
	!g_data->px ? cel_shading() : draw_pixelated_image(g_data);
	//!g_data->px ? depth_of_field(g_data, (t_vec){0, 200, 0}) : draw_pixelated_image(g_data);
	put_pixelbuf_to_widget(g_data->img, NULL);
	gtk_widget_show_all(g_data->win);
}
