/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_tex_bump.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:20:10 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 11:20:11 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void		check_bump(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	gboolean		state;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	group = (GtkSizeGroup*)param;
	state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	set_group_widget_active(group, state);
	if (state == TRUE)
		g_data->objs[g_ui->page_obj].bump_flag = 1;
	else
		g_data->objs[g_ui->page_obj].bump_flag = 0;
}

void		change_bump_scale(GtkWidget *widget, gpointer param)
{
	int		value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = (int)gtk_range_get_value(GTK_RANGE(widget));
	g_data->objs[g_ui->page_obj].bump_scale = value;
}

void		change_bump_noise(GtkWidget *widget, gpointer param)
{
	double	value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
	g_data->objs[g_ui->page_obj].bump_intensity = value / 100;
}
