/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:48:31 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 12:34:30 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "parse.h"

static void			reset_button_texture(GtkWidget *button)
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

void				check_tex_file(GtkWidget *widget, gpointer param)
{
	gboolean		state;
	GtkWidget		*button;
	GtkSizeGroup	*group;
	GSList			*lst;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	group = (GtkSizeGroup*)param;
	button = NULL;
	lst = gtk_size_group_get_widgets(group);
	state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	while (lst)
	{
		if (GTK_IS_BUTTON(lst->data) && !GTK_IS_CHECK_BUTTON(lst->data))
			button = (GtkWidget*)lst->data;
		lst = lst->next;
	}
	set_group_widget_active(group, state);
	if (state == FALSE)
		reset_button_texture(button);
}

static void			load_texture(t_obj *obj, char *path, GtkWidget *img)
{
	t_pixelbuf		*old_tex;
	t_pixelbuf		*button_pxb;

	if (!(button_pxb = pixelbuf_new_from_img(img)))
		if (!(button_pxb = pixelbuf_new(pt_set(60, 60), img)))
			return ;
	if (check_img_file(path, obj))
	{
		old_tex = obj->tex;
		if (!(obj->tex = pixelbuf_new_from_file(path)))
		{
			obj->tex = old_tex;
			return ;
		}
		if (gdk_pixbuf_get_has_alpha(obj->tex->buf) == FALSE && add_alpha(obj))
		{
			pixelbuf_free(&obj->tex);
			obj->tex = old_tex;
		}
		if (obj->tex)
			scale_pxb(obj->tex, button_pxb, button_pxb->size,
					GDK_INTERP_BILINEAR);
	}
}

static GtkWidget	*get_img(GtkWidget *button)
{
	GList		*lst;
	GtkWidget	*img;

	if ((lst = gtk_container_get_children(GTK_CONTAINER(button))))
	{
		img = (GtkWidget*)lst->data;
		g_list_free(lst);
		lst = gtk_container_get_children(GTK_CONTAINER(img));
	}
	if (lst)
	{
		img = (GtkWidget*)lst->data;
		g_list_free(lst);
	}
	return (img);
}

/*
** the add_alpha function is in parse_texture.c
*/

void				change_obj_tex_file(GtkWidget *widget, gpointer param)
{
	GtkWidget	*select;
	gchar		*path;
	t_obj		*obj;
	GtkWidget	*img;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	select = gtk_file_chooser_dialog_new("chose a file",
			GTK_WINDOW(g_data->win), GTK_FILE_CHOOSER_ACTION_OPEN,
			"load texture", GTK_RESPONSE_ACCEPT, NULL);
	gtk_window_set_modal(GTK_WINDOW(select), TRUE);
	obj = &g_data->objs[g_ui->page_obj];
	if (gtk_dialog_run(GTK_DIALOG(select)) == GTK_RESPONSE_ACCEPT)
	{
		img = get_img(widget);
		path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(select));
		load_texture(obj, path, img);
	}
	gtk_widget_destroy(select);
}
