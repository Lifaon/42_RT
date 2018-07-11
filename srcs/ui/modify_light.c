/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:59:20 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/11 14:54:26 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parse.h"
#include "ui.h"

void			switch_light(GtkWidget *widget, gboolean state, gpointer param)
{
	if (!widget && !param)
		param = NULL;
	if (state == TRUE)
	{
		g_data->lights[g_data->ui->page_light].disabled = 0;
		++g_data->nb_lights_on;
	}
	else
	{
		g_data->lights[g_data->ui->page_light].disabled = 1;
		--g_data->nb_lights_on;
	}
}

void			switch_parallel_light(GtkWidget *widget, gboolean state,
		gpointer param)
{
	int			i;

	if (!widget && !param)
		param = NULL;
	i = g_data->ui->page_light;
	if (gtk_switch_get_active(GTK_SWITCH(widget)) == FALSE)
		g_data->lights[i].is_para = 0;
	else
		g_data->lights[i].is_para = 1;
	set_group_widget_active(GTK_SIZE_GROUP(param), state);
}

void			add_one_light(GtkWidget *widget, gpointer param)
{
	t_light		*lights_new;
	int			i;

	i = -1;
	g_data->nb_lights += 1;
	g_data->nb_lights_on += 1;
	lights_new = (t_light*)malloc(sizeof(t_light) * g_data->nb_lights);
	while (++i < (g_data->nb_lights - 1))
		lights_new[i] = g_data->lights[i];
	free(g_data->lights);
	g_data->lights = lights_new;
	init_one_light(g_data, i);
	create_light_tab(g_data->ui->tab_light, i);
	gtk_widget_show_all(g_data->win);
	g_data->ui->is_active = 1;
}

void			change_light_pos(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->lights[g_data->ui->page_light].pos;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
}

void			change_light_angle(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;
	t_vec			dir;

	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->lights[g_data->ui->page_light].angle;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
	dir = (t_vec){0, 0, -1};
	dir = pitch(dir, *vec);
	dir = yaw(dir, *vec);
	dir = roll(dir, *vec);
	g_data->lights[g_data->ui->page_light].dir = dir;
}
