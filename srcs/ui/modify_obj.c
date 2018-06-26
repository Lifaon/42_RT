/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:26:36 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/26 18:48:07 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ui.h"
#include "parse.h"

void			change_obj_pos(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->objs[g_data->ui->page_obj].pos;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
}

void			change_obj_angle(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->objs[g_data->ui->page_obj].angle;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
	get_dir(&g_data->objs[g_data->ui->page_obj]);
}

void			switch_obj_limited(GtkWidget *widget, gboolean state, gpointer param)
{
	if (!widget && !param)
		param = NULL;
	if (state == TRUE)
		g_data->objs[g_data->ui->page_obj].limited = 1;
	else
		g_data->objs[g_data->ui->page_obj].limited = 0;
}
