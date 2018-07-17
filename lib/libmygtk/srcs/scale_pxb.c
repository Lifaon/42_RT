/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_pxb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 13:54:48 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/17 13:55:22 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mygtk.h"

void		scale_pxb(const t_pixelbuf *src, t_pixelbuf *dst, t_point new_size,
		GdkInterpType type)
{
	g_object_unref(dst->buf);
	dst->buf = gdk_pixbuf_scale_simple(src->buf, new_size.x, new_size.y, type);
	dst->size = new_size;
	dst->pxl = (uint32_t*)gdk_pixbuf_get_pixels(dst->buf);
	gtk_image_set_from_pixbuf(GTK_IMAGE(dst->widget), (GdkPixbuf*)dst->buf);
}
