/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_light_caustic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:16:00 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 11:16:57 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "draw.h"

void		check_caustic(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	gboolean		state;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	group = (GtkSizeGroup*)param;
	state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	set_group_widget_active(group, state);
	if (state == TRUE)
		get_photon_map();
	else
	{
		free(g_data->photon_map);
		g_data->photon_map = NULL;
	}
}

void		change_photon_size(GtkWidget *widget, gpointer param)
{
	int		value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
	g_data->photon_size = value;
}

void		change_photon_intensity(GtkWidget *widget, gpointer param)
{
	double	value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = (int)gtk_range_get_value(GTK_RANGE(widget));
	g_data->photon_ppx = value;
}
