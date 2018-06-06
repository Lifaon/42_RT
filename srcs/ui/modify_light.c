/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_parallel_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:59:20 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/06 17:42:46 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			switch_light(GtkWidget *widget, gpointer param)
{
	gboolean	status;
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == TRUE)
	{
		gtk_button_set_label(GTK_BUTTON(widget), "OFF");
		status = FALSE;
	}
	else
	{
		gtk_button_set_label(GTK_BUTTON(widget), "ON");
		status = TRUE;
	}
}

void			switch_parallel_light(GtkWidget *widget, gpointer param)
{
	GSList		*lst;
	gboolean	status;
	int			i;

	if (!param)
		return ;
	lst = gtk_size_group_get_widgets(GTK_SIZE_GROUP(param));
	i = g_data->ui->tab_light;
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == TRUE)
	{
		gtk_button_set_label(GTK_BUTTON(widget), "OFF");
		status = FALSE;
		g_data->lights[i].is_para = 0;
	}
	else
	{
		gtk_button_set_label(GTK_BUTTON(widget), "ON");
		status = TRUE;
		g_data->lights[i].is_para = 1;
	}
	while (lst)
	{
		gtk_widget_set_sensitive(GTK_WIDGET((GtkWidget*)lst->data), status);
		lst = lst->next;
	}
}
