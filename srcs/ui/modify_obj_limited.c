/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_limited.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:05:06 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 20:47:34 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int			get_limited_obj_type(t_obj *obj, int axe)
{
	if (axe == 1)
		return (LIMIT_AXE);
	if (axe == 2)
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
	if (axe == 3 && obj->obj_type == PLANE)
		return (LIMIT_CIRCLE);
	return (-1);
}

void		switch_obj_limited(GtkWidget *widget,
		gboolean state, gpointer param)
{	
	GList		*lst;
	GtkWidget 	*son;
	
	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	lst = gtk_container_get_children(GTK_CONTAINER(param));
	while (lst)
	{
		son = (GtkWidget*)lst->data;
		gtk_widget_set_sensitive(son, state);
		if (state == TRUE && GTK_IS_COMBO_BOX(son) == TRUE)
			gtk_combo_box_set_active(GTK_COMBO_BOX(son), 1);
		lst = lst->next;
	}
	g_list_free(lst);
	if (state == TRUE)
		g_data->objs[g_ui->page_obj].limited = LIMIT_AXE;
	else
	{
		g_data->objs[g_ui->page_obj].limited = LIMIT_NONE;
		g_data->objs[g_ui->page_obj].tex_limit = 0;
	}
}

void		modify_obj_limited_type(GtkWidget *widget, gpointer param)
{
	int			axe;
	t_obj		*obj;
	int			type;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	axe = gtk_combo_box_get_active(GTK_COMBO_BOX(widget));
	obj = &g_data->objs[g_ui->page_obj];
	if (axe == 0)
		obj->tex_limit = 1;
	else
	{
		if ((type = get_limited_obj_type(obj, axe)) < 0)
			return ;
		obj->limited = type;
		obj->limit = g_data->limit[type];
		obj->tex_limit = 0;
	}
}

void		change_obj_min(GtkWidget *widget, GdkEvent *event, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_ui->is_active == 0 || (!widget && !param && !event))
		return ;
	vec = &g_data->objs[g_ui->page_obj].min;
	group = (GtkSizeGroup*)param;
	change_vec_from_entry(group, vec, MODE_BOTH_INF,
			ptdb_set(-INFINITY, INFINITY));
}

void		change_obj_max(GtkWidget *widget, GdkEvent *event, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_ui->is_active == 0 || (!widget && !param && !event))
		return ;
	vec = &g_data->objs[g_ui->page_obj].max;
	group = (GtkSizeGroup*)param;
	change_vec_from_entry(group, vec, MODE_BOTH_INF,
			ptdb_set(-INFINITY, INFINITY));
}
