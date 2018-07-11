/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 20:03:05 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/12 00:18:23 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "parse.h"

void			switch_obj(GtkWidget *widget, gboolean state, gpointer param)
{
	if (!widget && !param)
		param = NULL;
	if (state == TRUE)
		g_data->objs[g_data->ui->page_obj].enabled = 1;
	else
		g_data->objs[g_data->ui->page_obj].enabled = 0;
}

void			add_one_obj(GtkWidget *widget, gpointer param)
{
	t_obj		*objs_new;
	int			i;

	i = -1;
	g_data->nb_objects += 1;
	objs_new = (t_obj*)malloc(sizeof(t_obj) * g_data->nb_objects);
	while (++i < (g_data->nb_objects - 1))
		objs_new[i] = g_data->objs[i];
	free(g_data->objs);
	g_data->objs = objs_new;
	init_one_object(g_data, i);
	create_object_tab(g_data->ui->tab_objs, i);
	gtk_widget_show_all(g_data->win);
	get_oc();
	g_data->ui->is_active = 1;
}

void			change_obj_spec(GtkWidget *widget, gpointer param)
{
	double			value;

	if (!param && !widget)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget)) / 100;
	g_data->objs[g_data->ui->page_obj].spec = value;
}

void			change_obj_alpha(GtkWidget *widget, gpointer param)
{
	double			value;

	if (!param && !widget)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
	g_data->objs[g_data->ui->page_obj].alpha = value;
}

void			change_obj_r(GtkWidget *widget, GdkEvent *event,
		gpointer param)
{
	double		value;

	if (!param && !widget && !event)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
	value = get_double_from_entry(widget, MODE_PLUS_INF, 0, INFINITY);
	g_data->objs[g_data->ui->page_obj].r = value;
}
