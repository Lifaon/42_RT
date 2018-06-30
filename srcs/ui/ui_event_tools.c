/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_event_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:56:03 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/27 17:49:06 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	set_group_widget_active(GtkSizeGroup *group, gboolean status)
{
	GSList		*lst;

	lst = gtk_size_group_get_widgets(group);
	while (lst)
	{
		gtk_widget_set_sensitive(GTK_WIDGET((GtkWidget*)lst->data), status);
		lst = lst->next;
	}
}

void    color_widget_img(GtkWidget *img, t_color color)
{
    t_pixelbuf      *pxb;

    pxb = pixelbuf_new_from_img(img);
    fill_pixelbuf_in_color(pxb, color.c);
    put_pixelbuf_to_widget(pxb, NULL);
    pixelbuf_free(&pxb);
}
