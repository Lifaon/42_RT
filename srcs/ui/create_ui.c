/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:30:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/01 19:07:57 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_ui		*ui_new(void)
{
	t_ui	*ui;

	if (!(ui = (t_ui*)malloc(sizeof(t_ui))))
		return (NULL);
	ui->to_free = NULL;
	if (!(ui->tab = gtk_notebook_new()))
		return (NULL);
	return (ui);
}

int				create_ui(void)
{
	GtkWidget		*win;
	GtkWidget		*v_box;

	if (!(win = gtk_window_new(GTK_WINDOW_TOPLEVEL)))
		return (0);
	g_data->draw = 0;
	gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(win), 250, 400);
	v_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	if (!(g_data->ui = ui_new()))
		return (0);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(g_data->ui->tab), TRUE);
	if (!(create_toolbar(v_box, g_data->ui)))
		return (0);
	if (!(create_sub_notebook(g_data->ui)))
		return (0);
	g_signal_connect(G_OBJECT(win), "delete-event", G_CALLBACK(gtk_main_quit),
			NULL);
	gtk_box_pack_start(GTK_BOX(v_box), g_data->ui->tab, FALSE, FALSE, 0);
	gtk_container_add(GTK_CONTAINER(win), v_box);
	gtk_widget_show_all(win);
	g_data->win_gtk = win;
	g_data->draw = 1;
	return (1);
}
