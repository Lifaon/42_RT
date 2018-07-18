/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:48:31 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/17 20:50:58 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "parse.h"

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
	int				cb_value;
	GtkWidget		*button;
	GtkSizeGroup	*group;
	GSList		*lst;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	cb_value = gtk_combo_box_get_active(GTK_COMBO_BOX(widget));
	group = (GtkSizeGroup*)param;
	button = NULL;
	lst = gtk_size_group_get_widgets(group);
	while (lst)
	{
		if (GTK_IS_BUTTON(lst->data))
			button = (GtkWidget*)lst->data;
		lst = lst->next;
	}
	if (cb_value == 0)
		set_group_widget_active(group, FALSE);
	else
		set_group_widget_active(group, TRUE);
	if (cb_value == 3)
		gtk_widget_set_sensitive(button, TRUE);
	else
		reset_button_texture(button);
}

static void load_texture(t_obj *obj, char *path)
{
	t_pixelbuf		*pxb;

	ft_putstr("un\n");
	if (check_img_file(path, obj))
	{
			ft_putstr("deux\n");
		pxb = obj->tex;
		if (!(obj->tex = pixelbuf_new_from_file(path)))
		{
			ft_putstr("ahah\n");
			obj->tex = pxb;
			return ;
		}
		if (gdk_pixbuf_get_has_alpha(obj->tex->buf) == FALSE && add_alpha(obj))
		{
			pixelbuf_free(&obj->tex);
			obj->tex = pxb;
			ft_putstr("pouet\n");
		}
		if (obj->tex)
			scale_pxb(obj->tex, pxb, pxb->size, GDK_INTERP_BILINEAR);
	}
}
/*
** the add_alpha function is in parse_texture.c
*/

void			change_obj_tex_file(GtkWidget *widget, gpointer param)
{
	GtkWidget	*select;
	gint		response;
	t_list		*lst;
	gchar		*path;
	t_obj		*obj;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	select = gtk_file_chooser_dialog_new("chose a file",
			GTK_WINDOW(g_data->win),
			GTK_FILE_CHOOSER_ACTION_OPEN, "load texture", GTK_RESPONSE_ACCEPT, NULL);
	gtk_window_set_modal(GTK_WINDOW(select), TRUE);
	response = gtk_dialog_run(GTK_DIALOG(select));
	obj = &g_data->objs[g_ui->page_obj];
	if (response == GTK_RESPONSE_ACCEPT)
	{
		path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(select));
		load_texture(obj, path);
	}
	gtk_widget_destroy(select);
}
