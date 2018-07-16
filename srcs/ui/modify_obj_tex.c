/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:48:31 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/16 19:39:24 by fchevrey         ###   ########.fr       */
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

void				change_obj_tex_scale(GtkWidget *widget, gpointer param)
{
	double			value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
	g_data->objs[g_ui->page_obj].tex_scale = value;
}

void				change_obj_tex_pos_x(GtkWidget *widget, gpointer param)
{
	double			value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = get_double_from_entry(widget, MODE_NO_INF, -50000, 50000);
	g_data->objs[g_ui->page_obj].tex_pos.x = (int)value;
}

void				change_obj_tex_pos_y(GtkWidget *widget, gpointer param)
{
	double			value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = get_double_from_entry(widget, MODE_NO_INF, -50000, 50000);
	g_data->objs[g_ui->page_obj].tex_pos.y = (int)value;
}
