/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:31:21 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/27 13:32:13 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	change_aa(GtkWidget *widget, gpointer param)
{
	const char	*str;
	int			value;
	t_obj		*obj;

/*	if (!param && !widget)
		param = NULL;
	str = gtk_combo_box_get_active_id(GTK_COMBO_BOX(widget));
	value = gtk_combo_box_get_active(GTK_COMBO_BOX(widget));
	if (value <= 1)
		value *= 2;
	else if (value == 3)
		value = 8;
	else
		value *= value;
	g_data->aa = value;
	ft_putnbr(value);*/
	/*obj = &g_data->objs[g_data->ui->page_obj];
	if (ft_strcmp(type, "icone") == 0)
		value = 1;
	if (ft_strcmp(type, "sphere") == 0)
		return (SPHERE);
	if (ft_strcmp(type, "plane") == 0)
		return (PLANE);
	if (ft_strcmp(type, "cylinder") == 0)
		return (CYLINDER);
	if ((type = get_int_obj_type(str)) < 0)
		return ;
	obj->obj_type = type;
	obj->intersect = g_data->intersect[type];
	obj->get_normal = g_data->get_normal[type];*/
}
