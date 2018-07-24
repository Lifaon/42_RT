/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_light2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 20:18:47 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 20:21:35 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void			change_light_r(GtkWidget *widget, GdkEvent *event,
		gpointer param)
{
	double		value;

	if (g_ui->is_active == 0 || (!widget && !param && !event))
		return ;
	value = get_double_from_entry(widget, MODE_PLUS_INF, 0, INFINITY);
	g_data->lights[g_ui->page_light].r = value;
}

void			change_light_ambi(GtkWidget *widget, gpointer param)
{
	double			value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget)) / 100;
	g_data->lights[g_ui->page_light].ambi = value;
}

void			change_light_color(GtkWidget *widget, gpointer param)
{
	t_color		*color;
	t_light		*light;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	light = &g_data->lights[g_ui->page_light];
	color = &light->color;
	chose_color((GtkWidget*)param, (gpointer)color, light);
}

