/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixelbuf_to_widget.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 19:04:25 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/24 19:17:06 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mygtk.h"

void	put_pixelbuf_to_widget(t_pixelbuf *pxlbuf, GtkWidget *img)
{
	if (img)
	{
		gtk_image_set_from_pixbuf(GTK_IMAGE(img), (GdkPixbuf*)pxlbuf->buf);
		gtk_widget_show(img);
	}
	else if (pxlbuf->widget)
	{
		gtk_image_set_from_pixbuf(GTK_IMAGE(pxlbuf->widget),
				(GdkPixbuf*)pxlbuf->buf);
		gtk_widget_show((GtkWidget*)pxlbuf->widget);
	}
}
