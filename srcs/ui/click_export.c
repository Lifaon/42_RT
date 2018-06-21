/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 19:42:25 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/20 20:13:33 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static void			export_png(char *name)
{
	GError				*error;

	error = NULL;
	gdk_pixbuf_save((GdkPixbuf*)g_data->img->buf, name, "png", &error, NULL);
	ft_putstr("pouet\n");
	if (error && error->message)
		ft_putstr(error->message);
}

void				click_export(GtkWidget *widget, gpointer data)
{
	char		*path;
	char		*name;
	GtkWidget	*select;
	gint		response;

	if (!widget && !data)
		return ;
	select = gtk_file_chooser_dialog_new("name the export image",
			GTK_WINDOW(g_data->win), GTK_FILE_CHOOSER_ACTION_SAVE,
			"export to png", GTK_RESPONSE_ACCEPT, NULL);
	gtk_window_set_modal(GTK_WINDOW(select), TRUE);
	response = gtk_dialog_run(GTK_DIALOG(select));
	if (response == GTK_RESPONSE_ACCEPT)
	{
		path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(select));
		name = ft_strjoin(path, ".png");
		export_png(name);
		ft_strdel(&path);
		ft_strdel(&name);
	}
	gtk_widget_destroy(select);
}
