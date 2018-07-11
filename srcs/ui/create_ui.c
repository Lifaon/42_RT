/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:30:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/11 18:06:40 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "events.h"

static t_ui		*ui_new(char *path)
{
	t_ui	*ui;
	char	*chr;

	if (!(ui = (t_ui*)malloc(sizeof(t_ui))))
		return (NULL);
	ui->to_free = NULL;
	ui->page_light = 0;
	ui->page_obj = 0;
	ui->page_cam = 0;
	ui->is_active = 0;
	chr = ft_strstr(path, "/rt");
	ui->path = ft_strsub(path, 0, ft_strlen(path) - ft_strlen(chr));
	//ui->path = ft_strdup(path);
	if (!(ui->tab = gtk_notebook_new()))
		return (NULL);
	return (ui);
}

int				make_grid(t_wid_data *wid_d)
{
	if (!(wid_d->grid = gtk_grid_new()))
		return (0);
	wid_d->pos = pt_set(0, 1);
	wid_d->size = pt_set(1, 1);
	wid_d->f = NULL;
	gtk_grid_set_row_spacing(GTK_GRID(wid_d->grid), 5);
	gtk_grid_set_column_spacing(GTK_GRID(wid_d->grid), 5);
	//gtk_grid_set_row_homogeneous(GTK_GRID(wid_d->grid), TRUE);
	gtk_grid_set_column_homogeneous(GTK_GRID(wid_d->grid), TRUE);
	set_wid_data(wid_d, pt_set(0, 0), pt_set(1, 1), NULL);
	return (1);
}

void            focus_me(GtkWidget  *widget, gpointer data)
{
    gtk_widget_grab_focus(widget);
    gtk_widget_grab_default(widget);
}

static int      create_renderer(void)
{
	GtkWidget	*wid;
	GtkWidget	*ev_box;

	if (!(g_data->img = pixelbuf_new(pt_set(WIN_W, WIN_H), NULL)))
		return (0);
	wid = (GtkWidget*)g_data->img->widget;
	gtk_widget_set_can_focus(wid, TRUE);
	gtk_widget_set_can_default(wid, TRUE);
	if (!(g_data->ui->ev_box = gtk_event_box_new()))
		return (0);
	ev_box = g_data->ui->ev_box;
	gtk_container_add(GTK_CONTAINER(ev_box), wid);
	gtk_widget_set_can_focus(ev_box, TRUE);
	gtk_widget_set_can_default(ev_box, TRUE);
	gtk_widget_add_events(ev_box, GDK_KEY_PRESS);
	//g_signal_connect(G_OBJECT(g_data->win), "key_press_event",
	//			G_CALLBACK(ft_keyboard), data);
	g_signal_connect(G_OBJECT(ev_box), "key_press_event",
				G_CALLBACK(ft_keyboard), g_data);
	gtk_event_box_set_above_child(GTK_EVENT_BOX(ev_box), TRUE);
	//g_signal_connect(G_OBJECT(wid), "clicked",
	  //      G_CALLBACK(&focus_me), g_data);
	//g_signal_connect(G_OBJECT(ev_box), "clicked",
	//			G_CALLBACK(&focus_me), g_data);
    return(1);
}

int				create_ui(char *path)
{
	GtkWidget		*win;
	GtkWidget		*v_box;
	GtkWidget		*h_box;

	if (!(win = (void*)gtk_window_new(GTK_WINDOW_TOPLEVEL)))
		return (0);

	gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(win), 250, 400);
	v_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	h_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	if (!(g_data->ui = ui_new(path)))
		return (0);
	create_renderer();
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(g_data->ui->tab), TRUE);
	if (!(create_toolbar(v_box, g_data->ui)))
		return (0);
	if (!(create_sub_notebook(g_data->ui)))
		return (0);
	g_signal_connect(G_OBJECT(win), "delete-event", G_CALLBACK(gtk_main_quit),
			NULL);
	gtk_box_pack_start(GTK_BOX(v_box), g_data->ui->tab, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(h_box), v_box, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(h_box), g_data->ui->ev_box, FALSE, FALSE, 0);
	//gtk_box_pack_start(GTK_BOX(h_box), g_data->img->widget, FALSE, FALSE, 0);
	gtk_container_add(GTK_CONTAINER(win), h_box);
	gtk_widget_show_all(win);
	g_data->win = win;
	return (1);
}
