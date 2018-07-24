/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 14:48:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 20:19:09 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

int		get_int_obj_type(const char *type)
{
	if (!type)
		return (-1);
	if (ft_strcmp(type, "cone") == 0)
		return (CONE);
	if (ft_strcmp(type, "sphere") == 0)
		return (SPHERE);
	if (ft_strcmp(type, "plane") == 0)
		return (PLANE);
	if (ft_strcmp(type, "cylinder") == 0)
		return (CYLINDER);
	return (-1);
}

char	*get_str_obj_type(int type)
{
	if (type == CONE)
		return (ft_strdup("cone"));
	if (type == SPHERE)
		return (ft_strdup("sphere"));
	if (type == PLANE)
		return (ft_strdup("plane"));
	if (type == CYLINDER)
		return (ft_strdup("cylinder"));
	return (NULL);
}

void	modify_obj_type(GtkWidget *widget, gpointer param)
{
	const char	*str;
	int			prev_type;
	int			type;
	t_obj		*obj;
	GtkWidget 	*cb_lim;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	str = gtk_combo_box_get_active_id(GTK_COMBO_BOX(widget));
	obj = &g_data->objs[g_ui->page_obj];
	if ((type = get_int_obj_type(str)) < 0)
		return ;
	cb_lim = (GtkWidget*)param;
	prev_type = obj->obj_type;
	obj->obj_type = type;
	obj->intersect = g_data->intersect[type];
	obj->get_normal = g_data->get_normal[type];
	if (prev_type != PLANE && type == PLANE)
		gtk_combo_box_text_insert_text(
			GTK_COMBO_BOX_TEXT(cb_lim), 3, "circle");
	if (prev_type == PLANE && type != PLANE)
		gtk_combo_box_text_remove(
				GTK_COMBO_BOX_TEXT(cb_lim), 3);
}
