/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_of_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:10:12 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/14 17:35:24 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mygtk.h"

t_color		get_color_of_img(GtkWidget *img)
{
	t_color			color;
	GdkPixbuf		*pxb;
	uint32_t		*pxl;

	color.c = 0;
	if (!(pxb = gtk_image_get_pixbuf(GTK_IMAGE(img))))
		return (color);
	if (!(pxl = (uint32_t*)gdk_pixbuf_get_pixels(pxb)))
		return (color);
	color.c = pxl[0];
	return (color);
}
