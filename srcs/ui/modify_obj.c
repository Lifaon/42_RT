/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:26:36 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/21 20:26:37 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parse.h"
#include "ui.h"

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

	check_ui_active(0);
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
	check_ui_active(1);
}

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

void			change_obj_dir(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_data->ui->is_active == 0)
		return ;
	check_ui_active(0);
	vec = &g_data->objs[g_data->ui->page_obj].dir;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
	check_ui_active(1);
}
