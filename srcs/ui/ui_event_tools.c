/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_event_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:56:03 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/12 17:26:36 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

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

void			set_entry_and_scale_from_vector(GtkSizeGroup *group, t_vec vec)
{
	GSList		*lst;
	GtkWidget 	*son;
	int			i;
	char 		*str[3];

	lst = gtk_size_group_get_widgets(group);
	str[0] = ft_dbtoa(vec.z);
	str[1] = ft_dbtoa(vec.y);
	str[2] = ft_dbtoa(vec.x);
	i = 0;
	while (lst)
	{
		son = lst->data;
		if (GTK_IS_ENTRY(son))
			gtk_entry_set_text(GTK_ENTRY(son), str[i - 1]);
		if (GTK_IS_SCALE(son) && ++i == 1)
			gtk_range_set_value(GTK_RANGE(son), vec.z);
		else if (GTK_IS_SCALE(son) && i == 2)
			gtk_range_set_value(GTK_RANGE(son), vec.y);
		else if (GTK_IS_SCALE(son) && i == 3)
			gtk_range_set_value(GTK_RANGE(son), vec.x);
		lst = lst->next;
	}
	while (--i >= 0)
		ft_strdel(&str[i]);
}

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

/*
** Here we use free instead of pixelbuf_free because the widget still need 
** the pixbuf.
*/
