/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_change_scale.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:15:17 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/11 12:35:59 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	entry_change_scale(GtkWidget *widget, GdkEvent *event, gpointer param)
{
	GtkWidget		*scale;
	double			value;
	double			min;
	double			max;
	GtkAdjustment	*adj;

	if (!widget && !param && !event)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	scale = (GtkWidget*)param;
	adj = gtk_range_get_adjustment(GTK_RANGE(scale));
	min = gtk_adjustment_get_lower(adj);
	max = gtk_adjustment_get_upper(adj);
	//value = ft_atof(gtk_entry_get_text(GTK_ENTRY(widget)));
	value = get_double_from_entry(widget, MODE_NO_INF, min, max);
	gtk_range_set_value(GTK_RANGE(scale), value);
}
