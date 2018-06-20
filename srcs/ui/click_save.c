/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:59:20 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/20 20:13:36 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ui.h"

static int		create_file(char *path)
{
	int			fd;
	char		*str;
	char		*name;
	int			need_free;

	need_free = 0;
	if ((name = ft_strstr(path, ".json")) && ft_strlen(name) < 1)
		name = path;
	else
	{
		name = ft_strjoin(path, ".json");
		need_free = 1;
	}
	if ((fd = open(name, O_WRONLY | O_CREAT | O_NOFOLLOW,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)) < 0)
		return (-1);
	str = fill_str_json(size_of_str_json());
	ft_putstr_fd(str, fd);
	ft_strdel(&str);
	if (need_free)
		ft_strdel(&name);
	ft_strdel(&path);
	close(fd);
	return (1);
}

void			click_save(GtkWidget *widget, gpointer data)
{
	GtkWidget	*select;
	gint		response;
	char		*path;

	if (!widget && !data)
		return ;
	select = gtk_file_chooser_dialog_new("save work",
			GTK_WINDOW(g_data->win),
			GTK_FILE_CHOOSER_ACTION_SAVE, "save", GTK_RESPONSE_ACCEPT, NULL);
	gtk_window_set_modal(GTK_WINDOW(select), TRUE);
	response = gtk_dialog_run(GTK_DIALOG(select));
	if (response == GTK_RESPONSE_ACCEPT)
	{
		if (!(path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(select))))
			ft_putstr("an error occured when writing file \n");
		if ((create_file(path)) < 0)
			ft_putstr("file not saved\n");
	}
	gtk_widget_destroy(select);
}
