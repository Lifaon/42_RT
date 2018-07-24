/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:30:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 23:15:23 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "events.h"

static int		create_renderer(void)
{
	GtkWidget	*wid;

	if (!(g_data->img = pixelbuf_new(pt_set(WIN_W, WIN_H), NULL)))
		return (0);
	wid = (GtkWidget*)g_data->img->widget;
	gtk_widget_set_can_focus(wid, TRUE);
	gtk_widget_set_can_default(wid, TRUE);
	if (!(g_ui->ev_box = gtk_event_box_new()))
		return (0);
	gtk_container_add(GTK_CONTAINER(g_ui->ev_box), wid);
	gtk_widget_set_can_focus(g_ui->ev_box, TRUE);
	gtk_widget_set_can_default(g_ui->ev_box, TRUE);
	gtk_widget_add_events(g_ui->ev_box, GDK_KEY_PRESS);
	g_signal_connect(G_OBJECT(g_ui->ev_box), "key_press_event",
				G_CALLBACK(ft_keyboard), g_data);
	gtk_event_box_set_above_child(GTK_EVENT_BOX(g_ui->ev_box), TRUE);
	return (1);
}

static t_ui		*ui_new(void)
{
	t_ui	*ui;

	if (!(ui = (t_ui*)malloc(sizeof(t_ui))))
		return (NULL);
	ui->page_light = 0;
	ui->page_obj = 0;
	ui->page_cam = 0;
	ui->is_active = 0;
	ui->gp_cam_pos = NULL;
	ui->gp_cam_angle = NULL;
	if (!(ui->gp_dof_focus = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (NULL);
	if (!(ui->tab = gtk_notebook_new()))
		return (NULL);
	if (!(create_renderer()))
		return (NULL);
	return (ui);
}

static GtkWidget	*make_window(void)
{
	GtkWidget		*win;

	if (!(win = gtk_window_new(GTK_WINDOW_TOPLEVEL)))
		return (0);
	g_data->win = (void*)win;
	gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(win), 250, 400);
	return (win);
}

int				create_ui(void)
{
	GtkWidget		*win;
	GtkWidget		*v_box;
	GtkWidget		*h_box;

	if (!(win = make_window()))
		return (0);
	if (!(v_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5)))
		return (0);
	if (!(h_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5)))
		return (0);
	if (!(g_ui = ui_new()))
		return (0);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(g_ui->tab), TRUE);
	if (!(create_toolbar(v_box, g_ui)))
		return (0);
	if (!(create_sub_notebook(g_ui)))
		return (0);
	g_signal_connect(G_OBJECT(win), "delete-event", G_CALLBACK(gtk_main_quit),
			NULL);
	gtk_box_pack_start(GTK_BOX(v_box), g_ui->tab, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(h_box), v_box, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(h_box), g_ui->ev_box, FALSE, FALSE, 0);
	gtk_container_add(GTK_CONTAINER(win), h_box);
	gtk_widget_show_all(win);
	return (1);
}
