/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:26:36 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/28 20:59:04 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ui.h"
#include "parse.h"

void			change_obj_pos(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	ft_putnbr(g_data->ui->is_active);
	ft_putchar('\n');
	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->objs[g_data->ui->page_obj].pos;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
	printf("x = %lf y = %lf  z = %lf\n", vec->x, vec->y, vec->z);
}

void			change_obj_angle(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	t_vec			*vec;

	if (g_data->ui->is_active == 0)
		return ;
	vec = &g_data->objs[g_data->ui->page_obj].angle;
	group = (GtkSizeGroup*)param;
	change_vec_from_scale(group, vec);
	get_dir(&g_data->objs[g_data->ui->page_obj]);
}

void	modify_obj_limited_type(GtkWidget *widget, gpointer param)
{
	const char	*str;
	int			type;
	t_obj		*obj;

	if (!param && !widget)
		param = NULL;
	str = gtk_combo_box_get_active_id(GTK_COMBO_BOX(widget));
	obj = &g_data->objs[g_data->ui->page_obj];
	if ((type = get_int_obj_type(str)) < 0)
		return ;
	obj->obj_type = type;
	obj->intersect = g_data->intersect[type];
	obj->get_normal = g_data->get_normal[type];
}

void    change_obj_color(GtkWidget *widget, gpointer param)
{
    gpointer    color;

	if (!param && !widget)
		return ;
	if (g_data->ui->is_active == 0)
		return ;
    color = (gpointer)&g_data->objs[g_data->ui->page_obj].color;
	chose_color((GtkWidget*)param, color);
}
