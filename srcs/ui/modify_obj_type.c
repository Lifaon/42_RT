/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 14:48:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/22 21:23:13 by fchevrey         ###   ########.fr       */
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
	int			dst;

	if (!param && !widget)
		param = NULL;
	str = gtk_combo_box_get_active_id(GTK_COMBO_BOX(widget));
	if ((dst = get_int_obj_type(str)) < 0)
		return ;
	printf("%s dst = %d",str, dst);
	g_data->objs[g_data->ui->page_obj].obj_type = dst;
	printf("  => g_data[%d].obj_type = %d\n",g_data->ui->page_obj, g_data->objs[g_data->ui->page_obj].obj_type);
}
