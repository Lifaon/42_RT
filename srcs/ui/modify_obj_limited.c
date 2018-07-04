/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_limited.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:05:06 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/27 17:48:41 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	switch_obj_limited(GtkWidget *widget, gboolean state,  gpointer param)
{
	if (!widget)
		return ;
	if (state == FALSE)
		g_data->objs[g_data->ui->page_obj].limited = -1;
	set_child_widget_active(GTK_CONTAINER(param), state);
}

void			change_obj_min(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->objs[g_data->ui->page_obj].min;
	group = (GtkSizeGroup*)param;
	change_vec_from_entry(group, vec, MODE_BOTH_INF);
}

void			change_obj_max(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->objs[g_data->ui->page_obj].max;
	group = (GtkSizeGroup*)param;
	change_vec_from_entry(group, vec, MODE_BOTH_INF);
	//change_vec_from_scale(group, vec);
}
