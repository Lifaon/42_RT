/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:31:21 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/27 15:14:03 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
/*
void	get_int_from_scale(GtkWidget *widget, gpointer param)
{
	int			value;
	int			*dst;

	if (!param && !widget)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
	dst = (int*)param;
	*dst = (int)value;
	ft_putnbr(*dst);
	ft_putchar('\n');
}*/

void	change_aa(GtkWidget *widget, gpointer param)
{
	int			value;

	if (!param && !widget)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
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
	if (g_data->ui->is_active == 0)
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
	if (value == 1)
		g_data->px = 0;
	else
		g_data->px = value;
}
/*	if (!param && !widget)
		param = NULL;
	str = gtk_combo_box_get_active_id(GTK_COMBO_BOX(widget));
	value = gtk_combo_box_get_active(GTK_COMBO_BOX(widget));
	if (value <= 1)
		value *= 2;
	else if (value == 3)
		value = 8;
	else
		value *= value;
	g_data->aa = value;*/
