/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:48:31 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/17 16:07:18 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static void		reset_button_texture(GtkWidget *button)
{
	GList		*lst;
	GtkWidget	*box;

	if ((lst = gtk_container_get_children(GTK_CONTAINER(button))))
	{
		box = lst->data;
		g_list_free(lst);
		lst = gtk_container_get_children(GTK_CONTAINER(box));
	 }
	if (lst)
	{
		fill_img_in_color((GtkWidget*)lst->data, 0x000000);
		g_list_free(lst);
	}
	if (g_data->objs[g_ui->page_obj].tex)
		pixelbuf_free(&g_data->objs[g_ui->page_obj].tex);
	g_data->objs[g_ui->page_obj].tex = NULL;
	gtk_widget_set_sensitive(button, FALSE);
}

void			change_obj_tex(GtkWidget *widget, gpointer param)
{
	int			cb_value;
	GtkWidget	*button;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	cb_value = gtk_combo_box_get_active(GTK_COMBO_BOX(widget));
	button = (GtkWidget*)param;
	if (cb_value == 0)
		set_group_widget_active(g_ui->gp_obj_tex, FALSE);
	else
		set_group_widget_active(g_ui->gp_obj_tex, TRUE);
	if (cb_value == 3)
		gtk_widget_set_sensitive(button, TRUE);
	else
		reset_button_texture(button);
}
static int		check_img_file(char *path)
{
	char	*str;
	char	*chr;

	ft_putendl(path);
	if ((str = ft_strstr(path, "textures/")))
		ft_putendl(str);
	chr = ft_strchr(str, '/');
	if ((str = ft_strstr(str, "textures/")))
		ft_putendl(str);
	ft_putendl(g_ui->path);
	return (1);
}

void			change_obj_tex_file(GtkWidget *widget, gpointer param)
{
	GtkWidget	*select;
	gint		response;
	t_list		*lst;
	gchar		*path;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	select = gtk_file_chooser_dialog_new("chose a file",
			GTK_WINDOW(g_data->win),
			GTK_FILE_CHOOSER_ACTION_OPEN, "load texture", GTK_RESPONSE_ACCEPT, NULL);
	gtk_window_set_modal(GTK_WINDOW(select), TRUE);
	response = gtk_dialog_run(GTK_DIALOG(select));
	if (response == GTK_RESPONSE_ACCEPT)
	{
		path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(select));
		if (check_img_file(path) < 1)
			return (file_error(select));
		//if (open_json(path) < 1)
		//	exit_all(g_data);
	}
	gtk_widget_destroy(select);
}

