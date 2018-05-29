/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:59:20 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/29 13:21:56 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <fcntl.h>

static int		create_file(GtkWidget *select)
{
	char		*path;
	int			fd;
	size_t		size;
	char		*str;

	if (!(path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(select))))
		return (-1);
	ft_putstr(path);
	//fd = open(path, O_WRONLY | O_CREAT | O_NOFOLLOW);
	//if ((fd = open(path, O_WRONLY | O_NOFOLLOW)) < 0)
	if ((fd = open(path, O_WRONLY | O_CREAT | O_NOFOLLOW,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)) < 0)
			return (-1);
	ft_putnbr(fd);
	size = size_of_str_json();
	str = fill_str_json(size);
	ft_putstr_fd(str, fd);
	ft_strdel(&str);
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
		if ((create_file(select)) < 0)
			ft_putstr("an error occured when writing file \n");
	gtk_widget_destroy(select);
}
