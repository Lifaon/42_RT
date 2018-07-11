/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_change_scale.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:15:17 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/11 11:40:50 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	entry_change_scale(GtkWidget *widget, GdkEvent *event, gpointer param)
{
	GtkWidget	*scale;
	double		value;

	if (!widget && !param && !event)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	scale = (GtkWidget*)param;
	value = ft_atof(gtk_entry_get_text(GTK_ENTRY(widget)));
	gtk_range_set_value(GTK_RANGE(scale), value);
}
