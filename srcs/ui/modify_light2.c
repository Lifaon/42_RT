/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_light2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 20:18:47 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/10 16:02:41 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void			change_light_r(GtkWidget *widget, gpointer param)
{
	double		value;

	if (!param && !widget)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	value = get_double_from_entry(widget, MODE_PLUS_INF, 0, INFINITY);
	
	g_data->lights[g_data->ui->page_light].r = value;
}

void			change_light_ambi(GtkWidget *widget, gpointer param)
{
	double			value;

	if (!param && !widget)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget)) / 100;
	g_data->lights[g_data->ui->page_light].ambi = value;
}

void			change_light_color(GtkWidget *widget, gpointer param)
{
    t_color    *color;

	if (!param && !widget)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	color = &g_data->lights[g_data->ui->page_light].color;
	chose_color((GtkWidget*)param, (gpointer)color);
}

