/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:36:29 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/26 22:24:44 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

static void		open_json(GtkWidget *select)
{
	gchar		*path;

	path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(select));
	free(g_data->lights);
	free(g_data->objs);
	g_data->nb_lights = 0;
	g_data->nb_objects = 0;
	parse(g_data, path);
	choose_cam(g_data, 0);
	draw_image(g_data);
}

void	click_open(GtkWidget *widget, gpointer data)
{
	GtkWidget	*select;
	gint		response;

	if (!widget && !data)
		return ;
	select = gtk_file_chooser_dialog_new("chose a file",
			GTK_WINDOW(g_data->win_gtk),
			GTK_FILE_CHOOSER_ACTION_OPEN, "load", GTK_RESPONSE_ACCEPT, NULL);
	gtk_window_set_modal(GTK_WINDOW(select), TRUE);
	response = gtk_dialog_run(GTK_DIALOG(select));
	if (response == GTK_RESPONSE_ACCEPT)
		open_json(select);
	gtk_widget_destroy(select);
}
