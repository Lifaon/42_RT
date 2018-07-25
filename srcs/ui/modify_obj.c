/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:26:36 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 11:19:33 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ui.h"
#include "parse.h"

void			change_obj_pos(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	vec = &g_data->objs[g_ui->page_obj].pos;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
	get_oc();
}

void			change_obj_angle(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	vec = &g_data->objs[g_ui->page_obj].angle;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
	get_dir(&g_data->objs[g_ui->page_obj]);
}

void			change_obj_focus(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	gboolean		status;
	GSList			*lst;
	GtkWidget		*son;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	group = (GtkSizeGroup*)param;
	status = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	if (status == FALSE)
		g_data->depth_of_field = -1;
	else
	{
		lst = gtk_size_group_get_widgets(group);
		g_ui->is_active = 0;
		while (lst)
		{
			son = (GtkWidget*)lst->data;
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(son), FALSE);
			lst = lst->next;
		}
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), TRUE);
		g_ui->is_active = 1;
		g_data->depth_of_field = g_ui->page_obj;
	}
}

void			change_obj_color(GtkWidget *widget, gpointer param)
{
	gpointer	color;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	color = (gpointer)&g_data->objs[g_ui->page_obj].color;
	chose_color((GtkWidget*)param, color, NULL);
}

void			change_obj_color2(GtkWidget *widget, gpointer param)
{
	gpointer	color;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	color = (gpointer)&g_data->objs[g_ui->page_obj].color2;
	chose_color((GtkWidget*)param, color, NULL);
}
