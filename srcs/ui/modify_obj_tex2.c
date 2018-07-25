/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_tex2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:21:55 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 19:07:46 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void		switch_obj_tex_repeat(GtkWidget *widget, gboolean state,
		gpointer param)
{
	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	if (state == FALSE)
		g_data->objs[g_ui->page_obj].tex_repeat = 0;
	if (state == TRUE)
		g_data->objs[g_ui->page_obj].tex_repeat = 1;
}

void		switch_obj_tex_trans(GtkWidget *widget, gboolean state,
		gpointer param)
{
	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	if (state == FALSE)
		g_data->objs[g_ui->page_obj].tex_trans = 0;
	if (state == TRUE)
		g_data->objs[g_ui->page_obj].tex_trans = 1;
}

void		change_obj_tex_scale(GtkWidget *widget, gpointer param)
{
	double			value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
	g_data->objs[g_ui->page_obj].tex_scale = value;
}

void		change_obj_tex_pos_x(GtkWidget *widget, GdkEvent *event,
		gpointer param)
{
	double			value;
	t_obj			*obj;

	if (g_ui->is_active == 0 || (!widget && !param && !event))
		return ;
	obj = &g_data->objs[g_ui->page_obj];
	value = get_double_from_entry(widget, MODE_NO_INF, -50000, 50000);
	obj->tex_pos.x = (int)value;
}

void		change_obj_tex_pos_y(GtkWidget *widget, GdkEvent *event,
		gpointer param)
{
	double			value;
	t_obj			*obj;

	if (g_ui->is_active == 0 || (!widget && !param && !event))
		return ;
	obj = &g_data->objs[g_ui->page_obj];
	value = get_double_from_entry(widget, MODE_NO_INF, -50000, 50000);
	obj->tex_pos.y = (int)value;
}
