/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:30:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/26 22:16:08 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	create_notebook(GtkWidget *v_box)
{
	GtkWidget		*tab;

	tab = gtk_notebook_new();
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(tab), TRUE);
	if (!(create_light_ui(tab)))
		return (0);
	ft_putstr("light created \n");
	if (!(create_camera_ui(tab)))
		return (0);
	ft_putstr("camera created \n");
	if (!(create_object_ui(tab)))
		return (0);
	ft_putstr("object created \n");
	gtk_box_pack_start(GTK_BOX(v_box), tab, FALSE, FALSE, 0);
	return (1);
}

int		create_ui(void)
{
	GtkWidget		*win;
	GtkWidget		*v_box;

	if (!(win = gtk_window_new(GTK_WINDOW_TOPLEVEL)))
			return (0);
	gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(win), 250, 400);
	v_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	if (!(create_toolbar(v_box)))
		return (0);
	if (!(create_notebook(v_box)))
		return (0);
	g_signal_connect(G_OBJECT(win), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_container_add(GTK_CONTAINER(win), v_box);
	gtk_widget_show_all(win);
	g_data->win_gtk = win;
	return (1);
}
