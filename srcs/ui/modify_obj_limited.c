/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_limited.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:05:06 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/10 17:59:58 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int	get_limited_obj_type(t_obj *obj, int axe)
{
	printf("obj_type = %d, axe = %d\n", obj->obj_type, axe);
	if (axe == 0)
		return (LIMIT_AXE);
	if (axe == 1)
	{
		if (obj->obj_type == SPHERE)
			return (LIMIT_SPHERE);
		if (obj->obj_type == CYLINDER)
			return (LIMIT_CYLINDER);
		if (obj->obj_type == CONE)
			return (LIMIT_CONE);
		if (obj->obj_type == PLANE)
			return (LIMIT_RECTANGLE);
	}
	if (axe == 2 && obj->obj_type == PLANE)
		return (LIMIT_CIRCLE);
	return (-1);
}

void		switch_obj_limited(GtkWidget *widget,
		gboolean state, gpointer param)
{
	if (!widget)
		return ;
	if (state == FALSE)
		g_data->objs[g_data->ui->page_obj].limited = -1;
	set_child_widget_active(GTK_CONTAINER(param), state);
}

void		modify_obj_limited_type(GtkWidget *widget, gpointer param)
{
	int			axe;
	t_obj		*obj;
	int			type;

	if (!param && !widget)
		param = NULL;
	axe = gtk_combo_box_get_active(GTK_COMBO_BOX(widget));
	obj = &g_data->objs[g_data->ui->page_obj];
	if ((type = get_limited_obj_type(obj, axe)) < 0)
		return ;
	ft_putnbr(type);
	obj->limited = type;
	obj->limit = g_data->limit[type];
}

void		change_obj_min(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->objs[g_data->ui->page_obj].min;
	group = (GtkSizeGroup*)param;
	change_vec_from_entry(group, vec, MODE_BOTH_INF,
			ptdb_set(-INFINITY, INFINITY));
	printf("x = %lf  y = %lf  z = %lf\n", vec->x, vec->y, vec->z);
}

void		change_obj_max(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->objs[g_data->ui->page_obj].max;
	group = (GtkSizeGroup*)param;
	change_vec_from_entry(group, vec, MODE_BOTH_INF,
			ptdb_set(-INFINITY, INFINITY));
	printf("x = %lf  y = %lf  z = %lf\n", vec->x, vec->y, vec->z);
}
