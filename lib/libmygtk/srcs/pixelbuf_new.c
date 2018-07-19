/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelbuf_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:57:12 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/29 04:55:16 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mygtk.h"

t_pixelbuf		*pixelbuf_new(t_point size, GtkWidget *image)
{
	t_pixelbuf	*pxbuf;

	if (!(pxbuf = (t_pixelbuf*)malloc(sizeof(t_pixelbuf))))
		return (NULL);
	pxbuf->size = size;
	if (!(pxbuf->buf = (void*)gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8,
					size.x, size.y)))
		return (NULL);
	pxbuf->pxl = (uint32_t*)gdk_pixbuf_get_pixels(pxbuf->buf);
	if (!image)
	{
		if (!(pxbuf->widget = (void*)gtk_image_new_from_pixbuf(pxbuf->buf)))
			return (NULL);
	}
	else
		pxbuf->widget = (void*)image;
	return (pxbuf);
}

t_pixelbuf		*pixelbuf_new_from_img(GtkWidget *img)
{
	t_pixelbuf	*pxbuf;

	if (!img)
		return (NULL);
	if (!(pxbuf = (t_pixelbuf*)malloc(sizeof(t_pixelbuf))))
		return (NULL);
	pxbuf->buf = gtk_image_get_pixbuf(GTK_IMAGE(img));
	pxbuf->size.x = gdk_pixbuf_get_width(pxbuf->buf);
	pxbuf->size.y = gdk_pixbuf_get_height(pxbuf->buf);
	pxbuf->pxl = (uint32_t*)gdk_pixbuf_get_pixels(pxbuf->buf);
	pxbuf->widget = (void*)img;
	return (pxbuf);
}

t_pixelbuf		*pixelbuf_new_from_file(char *filename)
{
	t_pixelbuf	*pxbuf;
	GtkWidget	*img;
	
	if (!(img = gtk_image_new_from_file(filename)))
		return (NULL);
	if (!(pxbuf = (t_pixelbuf*)malloc(sizeof(t_pixelbuf))))
		return (NULL);
	if (!(pxbuf->buf = gtk_image_get_pixbuf(GTK_IMAGE(img))))
		return (NULL);
	pxbuf->size.x = gdk_pixbuf_get_width(pxbuf->buf);
	pxbuf->size.y = gdk_pixbuf_get_height(pxbuf->buf);
	if (!(pxbuf->pxl = (uint32_t*)gdk_pixbuf_get_pixels(pxbuf->buf)))
		return (NULL);
	pxbuf->widget = (void*)img;
	return (pxbuf);
}
