/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:59:20 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/27 20:42:55 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		write_cams(int fd)
{
	char		*str;
	size_t		size;

	size = 5 + ft_strlen("\"position\" : ") + ft_strlen("\"fov\" : ");
	//size += 3 + size_double(g_data->cam)
	return (1);
}

static int		write_lights(int fd)
{
	char		*str;
	size_t		size;

	size = 5 + ft_strlen("\"position\" : ") + ft_strlen("\"fov\" : ");
	//size += 3 + size_double(g_data->cam)
	return (1);
}

static int		write_objs(int fd)
{
	char		*str;
	size_t		size;

	size = 5 + ft_strlen("\"position\" : ") + ft_strlen("\"fov\" : ");
	//size += 3 + size_double(g_data->cam)
	return (1);
}

static int		create_file(GtkWidget *select)
{
	char	*path;
	int		fd;

	if (!(path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(select))))
		return (-1);
	fd = open(path, O_WONLY | O_CREAT);
	if (fd < 0)
		return (-1);
	if (!(write_cams(fd)))
		return (-2);
	if (!(write_lights(fd)))
		return (-2);
	if (!(write_objs(fd)))
		return (-2);
	close(fd);
	return (1);
}

void			click_save(GtkWidget *widget, gpointer data)
{
	GtkWidget	*select;
	gint		response;

	if (!widget && !data)
		return ;
	select = gtk_file_chooser_dialog_new("save work",
			GTK_WINDOW(g_data->win_gtk),
			GTK_FILE_CHOOSER_ACTION_SAVE, "save", GTK_RESPONSE_ACCEPT, NULL);
	gtk_window_set_modal(GTK_WINDOW(select), TRUE);
	response = gtk_dialog_run(GTK_DIALOG(select));
	if (response == GTK_RESPONSE_ACCEPT)
	{
	}
	gtk_widget_destroy(select);
}
