/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_event_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:56:03 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/10 17:45:19 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	set_child_widget_active(GtkContainer *container, gboolean status)
{
	GList		*lst;

	lst = gtk_container_get_children(container);
	while (lst)
	{
		gtk_widget_set_sensitive(GTK_WIDGET((GtkWidget*)lst->data), status);
		lst = lst->next;
	}
	g_list_free(lst);
}

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

void	color_widget_img(GtkWidget *img, t_color color)
{
	t_pixelbuf		*pxb;

	pxb = pixelbuf_new_from_img(img);
	fill_pixelbuf_in_color(pxb, color.c);
	put_pixelbuf_to_widget(pxb, NULL);
	free(pxb);
}
