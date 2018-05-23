/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_parallel_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:59:20 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/23 20:10:15 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	switch_parallel_light(GtkWidget *widget, gpointer param)
{
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == TRUE)
		gtk_button_set_label(GTK_BUTTON(widget), "OFF");
	else
		gtk_button_set_label(GTK_BUTTON(widget), "ON");
}

void	change_light_distance(GtkWidget *widget, gpointer param)
{
	double		dist;

	if (!widget && !param)
		return ;
	dist = gtk_range_get_value(GTK_RANGE(widget));
	printf("dist = %lf\n", dist);
}

void	change_light_direction(GtkWidget *widget, gpointer param)
{
	double		dir;

	if (!widget && !param)
		return ;
	dir = gtk_range_get_value(GTK_RANGE(widget));
	printf("direction = %lf\n", dir);
}
