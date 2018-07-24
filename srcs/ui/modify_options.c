/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:31:21 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 19:39:56 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	switch_cel_shading(GtkWidget *widget, gboolean state,
		gpointer param)
{
	if (!widget && !param)
		param = NULL;
	if (state == TRUE)
		g_data->cel_shading = 1;
	else
		g_data->cel_shading = 0;
}

void	change_aa(GtkWidget *widget, gpointer param)
{
	int			value;

	if (!param && !widget)
		return ;
	if (g_ui->is_active == 0)
		return ;
	value = (int)gtk_range_get_value(GTK_RANGE(widget));
	if (value == 1)
		g_data->aa = 0;
	else
		g_data->aa = value;
}

void	change_px(GtkWidget *widget, gpointer param)
{
	int			value;

	if (!param && !widget)
		return ;
	if (g_ui->is_active == 0)
		return ;
	value = (int)gtk_range_get_value(GTK_RANGE(widget));
		g_data->px = value;
}

void	change_filter(GtkWidget *widget, gpointer param)
{
	int			filter;

	if (!param && !widget)
		param = NULL;
	filter = gtk_combo_box_get_active(GTK_COMBO_BOX(widget));
	if (filter >= 0)
		g_data->filter = filter;
}

void	change_dof_coeff(GtkWidget *widget, gpointer param)
{
	int			value;

	if (!param && !widget)
		return ;
	if (g_ui->is_active == 0)
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
	g_data->dof_coeff = value;
}
