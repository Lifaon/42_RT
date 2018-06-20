/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_parallel_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:59:20 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/20 20:13:53 by fchevrey         ###   ########.fr       */
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
		g_data->lights[g_data->ui->page_light].enabled = 1;
	else
		g_data->lights[g_data->ui->page_light].enabled = 0;
}

void			switch_parallel_light(GtkWidget *widget, gboolean state,
		gpointer param)
{
	GSList		*lst;
	gboolean	status;
	int			i;

	if (!widget && !param)
		param = NULL;
	lst = gtk_size_group_get_widgets(GTK_SIZE_GROUP(param));
	i = g_data->ui->page_light;
	if (gtk_switch_get_active(GTK_SWITCH(widget)) == FALSE)
	{
		status = FALSE;
		g_data->lights[i].is_para = 0;
	}
	else
	{
		status = TRUE;
		g_data->lights[i].is_para = 1;
	}
	while (lst)
	{
		gtk_widget_set_sensitive(GTK_WIDGET((GtkWidget*)lst->data), status);
		lst = lst->next;
	}
}

void			add_one_light(GtkWidget *widget, gpointer param)
{
	t_light		*lights_new;
	int			i;

	i = -1;
	g_data->nb_lights += 1;
	lights_new = (t_light*)malloc(sizeof(t_light) * g_data->nb_lights);
	while (++i < (g_data->nb_lights - 1))
		lights_new[i] = g_data->lights[i];
	free(g_data->lights);
	g_data->lights = lights_new;
	init_one_light(g_data, i);
	add_one_light_tab(g_data->ui->tab_light, i);
	gtk_widget_show_all(g_data->win);
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

void			change_light_dir(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->lights[g_data->ui->page_light].dir;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
}
