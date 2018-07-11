/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:26:36 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/12 00:22:34 by mlantonn         ###   ########.fr       */
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
	get_oc();
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

void	change_obj_color(GtkWidget *widget, gpointer param)
{
	gpointer	color;

	if (!param && !widget)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	color = (gpointer)&g_data->objs[g_data->ui->page_obj].color;
	chose_color((GtkWidget*)param, color);
}
