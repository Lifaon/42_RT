/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object_texture_ui.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:18:05 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/14 19:20:00 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void		scale_img(const t_pixelbuf *src, t_pixelbuf *dst, t_point new_size,
		GdkInterpType type)
{
	g_object_unref(dst->buf);
	dst->buf = gdk_pixbuf_scale_simple(src->buf, new_size.x, new_size.y, type);
	dst->size = new_size;
	dst->pxl = (uint32_t*)gdk_pixbuf_get_pixels(dst->buf);
	gtk_image_set_from_pixbuf(GTK_IMAGE(dst->widget), (GdkPixbuf*)dst->buf);
}

static int	phase_1(t_wid_data *wid_d, t_obj *obj)
{
	t_pixelbuf		*pxb;

	wid_d->f = &change_obj_tex;
	wid_d->size.x = 2;
	wid_d->size.y = 2;
	if (!(pxb = pixelbuf_new(pt_set(60, 60), NULL)))
		return (0);
	if (obj->tex)
		scale_img(obj->tex, pxb, pxb->size, GDK_INTERP_BILINEAR);
	if (!(b_new(wid_d, (gpointer)pxb->widget, NULL, (GtkWidget*)pxb->widget)))
		return (0);
	return (1);
}

int		create_object_texture_ui(t_wid_data *wid_d, t_obj *obj)
{
	gboolean		is_limited;
	GtkWidget 		*frame;
	t_wid_data		frame_d;
	t_point			crd;
	GtkWidget 		*sw;

	if (!(frame = gtk_frame_new(NULL)))
		return (0);
	init_wid_data(&frame_d, wid_d->step, wid_d->min_max);
	if (!(phase_1(&frame_d, obj)))
		return (0);
	gtk_container_add(GTK_CONTAINER(frame), frame_d.grid);
	gtk_grid_attach(GTK_GRID(wid_d->grid), frame, 0, wid_d->pos.x, 4, 7);
	wid_d->pos.x += 7;
	return (create_limited_object_ui(wid_d, obj));
}
