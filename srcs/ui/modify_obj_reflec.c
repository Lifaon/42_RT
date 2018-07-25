/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_reflec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:17:40 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 11:17:55 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void			change_obj_ior(GtkWidget *widget, gpointer param)
{
	double			value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
	g_data->objs[g_ui->page_obj].ior = value;
}

void			change_obj_trans(GtkWidget *widget, gpointer param)
{
	double			value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget)) / 100;
	g_data->objs[g_ui->page_obj].trans = value;
}

void			change_obj_reflex(GtkWidget *widget, gpointer param)
{
	double			value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget)) / 100;
	g_data->objs[g_ui->page_obj].shiny = value;
}
