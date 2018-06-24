/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:36:29 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/24 19:30:56 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "parse.h"

static int		check_file(char *file_name)
{
	char	*str;

	if (!(str = get_full_read_file(file_name)))
		return (-1);
	remove_white_spaces(&str);
	if (brackets(str))
		return (-1);
	ft_strdel(&str);
	return (1);
}

static int		open_json(gchar *path)
{
	free(g_data->lights);
	free(g_data->objs);
	g_data->nb_lights = 0;
	g_data->nb_objects = 0;
	parse(g_data, path);
	g_data->i = 0;
	g_data->cam = g_data->cams[g_data->i];
	get_oc();
	put_gdk_image();
	if (!(create_sub_notebook(g_data->ui)))
		return (-1);
	gtk_widget_show_all(g_data->win);
	return (1);
}

static void		destroy_tabs(GtkWidget *tab)
{
	GList		*list;
	GList		*cpy;
	GtkWidget	*tab_son;
	int			i;

	if (!(list = gtk_container_get_children(GTK_CONTAINER(tab))))
		return ;
	cpy = list;
	while (cpy)
	{
		tab_son = (GtkWidget*)cpy->data;
		gtk_widget_destroy(tab_son);
		cpy = cpy->next;
	}
	ft_lstdel(&g_data->ui->to_free, free_to_free);
	g_list_free(list);
}

static void		file_error(GtkWidget *select)
{
	ft_putstr("error : invalid file\n");
	gtk_widget_destroy(select);
}

void			click_open(GtkWidget *widget, gpointer data)
{
	GtkWidget	*select;
	gint		response;
	t_ui		*ui;
	t_list		*lst;
	gchar		*path;

	if (!widget && !data)
		return ;
	ui = (t_ui*)data;
	select = gtk_file_chooser_dialog_new("chose a file",
			GTK_WINDOW(g_data->win),
			GTK_FILE_CHOOSER_ACTION_OPEN, "load", GTK_RESPONSE_ACCEPT, NULL);
	gtk_window_set_modal(GTK_WINDOW(select), TRUE);
	response = gtk_dialog_run(GTK_DIALOG(select));
	if (response == GTK_RESPONSE_ACCEPT)
	{
		path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(select));
		if (check_file(path) < 1)
			return (file_error(select));
		destroy_tabs(ui->tab);
		if (open_json(path) < 1)
			exit_all(g_data);
	}
	gtk_widget_destroy(select);
}
