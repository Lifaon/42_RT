/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:30:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/26 10:40:21 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "events.h"

static void			make_window(GtkApplication *app, gpointer param)
{
	GtkWidget		*win;

	if (!param)
		param = NULL;
	g_data->win = NULL;
	if (!(win = gtk_application_window_new(app)))
		 return ;
	gtk_application_add_window(app, GTK_WINDOW(win));
	g_data->win = (void*)win;
	gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(win), 250, 400);
}

static int			create_renderer(t_ui *ui)
{
	GtkWidget	*wid;

	if (!(g_data->img = pixelbuf_new(pt_set(WIN_W, WIN_H), NULL)))
		return (0);
	wid = (GtkWidget*)g_data->img->widget;
	if (!(ui->ev_box = gtk_event_box_new()))
		return (0);
	gtk_container_add(GTK_CONTAINER(ui->ev_box), wid);
	gtk_widget_set_can_focus(ui->ev_box, TRUE);
	gtk_widget_set_can_default(ui->ev_box, TRUE);
	gtk_widget_add_events(ui->ev_box, GDK_KEY_PRESS);
	g_signal_connect(G_OBJECT(ui->ev_box), "key_press_event",
				G_CALLBACK(ft_keyboard), g_data);
	//gtk_event_box_set_above_child(GTK_EVENT_BOX(ui->ev_box), TRUE);
	return (1);
}

static t_ui			*ui_new(int ac, char **av)
{
	t_ui				*ui;

	if (!(ui = (t_ui*)malloc(sizeof(t_ui))))
		return (NULL);
	ui->page_light = 0;
	ui->page_obj = 0;
	ui->page_cam = 0;
	ui->is_active = 0;
	ui->gp_cam_pos = NULL;
	ui->gp_cam_angle = NULL;
	ft_putstr("pouici\n");
	if (!(ui->app = gtk_application_new("org.gtk.exemple", G_APPLICATION_FLAGS_NONE)))
		return (NULL);
	g_signal_connect(ui->app, "activate", G_CALLBACK(&make_window), ui);
	g_application_run(G_APPLICATION(ui->app), ac, av);
	ft_putstr("maow\n");
/*	if (!(make_window(ui->app)))
		return (0);*/
	ft_putstr("pouici\n");
	if (!(ui->gp_dof_focus = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (NULL);
	if (!(ui->tab = gtk_notebook_new()))
		return (NULL);
	if (g_data->win == NULL)
		sleep(1);
	if (!(create_renderer(ui)))
		return (NULL);
	ft_putstr("pouici\n");
	return (ui);
}

int					create_ui(int ac, char **av)
{
	GtkWidget		*v_box;
	GtkWidget		*h_box;

	if (!(g_ui = ui_new(ac, av)))
		return (0);
	if (!(v_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5)))
		return (0);
	if (!(h_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5)))
		return (0);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(g_ui->tab), TRUE);
	if (!(create_toolbar(v_box, g_ui)))
		return (0);
	if (!(create_sub_notebook(g_ui)))
		return (0);
	g_signal_connect(G_OBJECT(g_data->win), "delete-event",
			G_CALLBACK(gtk_main_quit), NULL);
	gtk_box_pack_start(GTK_BOX(v_box), g_ui->tab, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(h_box), v_box, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(h_box), g_ui->ev_box, FALSE, FALSE, 0);
	gtk_container_add(GTK_CONTAINER(g_data->win), h_box);
	gtk_widget_show_all(g_data->win);
	return (1);
}
