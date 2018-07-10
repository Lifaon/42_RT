/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 19:19:00 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/10 19:56:54 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void			change_cam_fov(GtkWidget *widget, gpointer param)
{
	double			value;

	if (!param && !widget)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
	g_data->cams[g_data->i].fov = value;
}

void			change_cam_angle(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->cams[g_data->i].angle;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
}

void			change_cam_pos(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->cams[g_data->i].pos;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
}

void			change_left_cam(GtkWidget *widget, gpointer param)
{
	GtkWidget		*label;
	char			*str;

	if (g_data->ui->is_active == 0)
		return ;
	label = (GtkWidget*)param;
	if (g_data->i <= 0)
		return ;
	g_data->i--;
	g_data->cam = g_data->cams[g_data->i];
	str = ft_itoa(g_data->i + 1);
	gtk_label_set_text(GTK_LABEL(label), str);
	ft_strdel(&str);
	g_data->ui->is_active = 0;
	set_entry_and_scale_from_vector(g_data->ui->gp_cam_angle,
			g_data->cam.angle);
	set_entry_and_scale_from_vector(g_data->ui->gp_cam_pos, g_data->cam.pos);
	gtk_range_set_value(GTK_RANGE(g_data->ui->sc_fov), g_data->cam.fov);
	g_data->ui->is_active = 1;
}

void			change_right_cam(GtkWidget *widget, gpointer param)
{
	GtkWidget		*label;
	char			*str;

	if (g_data->ui->is_active == 0)
		return ;
	label = (GtkWidget*)param;
	if (g_data->i >= CAM_NB - 1)
		return ;
	g_data->i++;
	g_data->cam = g_data->cams[g_data->i];
	str = ft_itoa(g_data->i + 1);
	gtk_label_set_text(GTK_LABEL(label), str);
	ft_strdel(&str);
	g_data->ui->is_active = 0;
	set_entry_and_scale_from_vector(g_data->ui->gp_cam_angle,
			g_data->cam.angle);
	set_entry_and_scale_from_vector(g_data->ui->gp_cam_pos, g_data->cam.pos);
	gtk_range_set_value(GTK_RANGE(g_data->ui->sc_fov), g_data->cam.fov);
	g_data->ui->is_active = 1;
}
