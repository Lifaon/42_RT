/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_parallel_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:59:20 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/29 20:01:04 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			switch_parallel_light(GtkWidget *widget, gpointer param)
{
	GSList		*lst;
	gboolean	status;
	int			i;

	if (!param)
		return ;
	lst = gtk_size_group_get_widgets(GTK_SIZE_GROUP(param));
	i = g_data->ui->tab_light;
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == TRUE)
	{
		gtk_button_set_label(GTK_BUTTON(widget), "OFF");
		status = FALSE;
		g_data->lights[i].is_para = 0;
	}
	else
	{
		gtk_button_set_label(GTK_BUTTON(widget), "ON");
		status = TRUE;
		g_data->lights[i].is_para = 1;
	}
	while (lst)
	{
		gtk_widget_set_sensitive(GTK_WIDGET((GtkWidget*)lst->data), status);
		lst = lst->next;
	}
}

static void		fill_vec(t_vec *vec, double nb)
{
	static int i = 0;

	if (!vec)
		return ;
	if (i > 2)
		i = 0;
	if (i == 0)
		vec->x = nb;
	else if (i == 1)
		vec->y = nb;
	else if (i == 2)
		vec->z = nb;
	i++;
}

void			change_light_direction(GtkWidget *widget, gpointer param)
{
	double		value;
	GSList		*lst;
	GtkWidget	*son;
	t_vec		pos;
	char		*str;

	if (!widget || !param)
		return ;
	lst = gtk_size_group_get_widgets(GTK_SIZE_GROUP(param));
	while (lst)
	{
		son = (GtkWidget*)lst->data;
		if (GTK_IS_SCALE(son))
		{
			value = gtk_range_get_value(GTK_RANGE(son));
			fill_vec(&pos, value);
		}
		if (GTK_IS_ENTRY(son))
		{
			str = ft_dbtoa(value);
			gtk_entry_set_text(GTK_ENTRY(son), str);
			ft_strdel(&str);
		}
		lst = lst->next;
	}
	g_data->lights[g_data->ui->tab_light].pos = pos;
}
/*void			change_light_direction(GtkWidget *widget, gpointer param)
{
	double		value;
	GSList		*lst;
	GtkWidget	*son;
	t_vec		dir;
	char		*str;

	if (!widget || !param)
		return ;
	lst = gtk_size_group_get_widgets(GTK_SIZE_GROUP(param));
	while (lst)
	{
		son = (GtkWidget*)lst->data;
		if (GTK_IS_SCALE(son))
		{
			value = gtk_range_get_value(GTK_RANGE(son));
			fill_vec(&dir, value);
		}
		if (GTK_IS_ENTRY(son))
		{
			str = ft_dbtoa(value);
			gtk_entry_set_text(GTK_ENTRY(son), str);
			ft_strdel(&str);
		}
		lst = lst->next;
	}
	g_data->lights[g_data->ui->tab_light].dir = dir;
	draw_image(g_data);
}*/
