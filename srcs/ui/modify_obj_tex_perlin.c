/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_tex_perlin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:22:26 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 11:36:27 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void		check_perlin(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	gboolean		state;
	GSList			*lst;
	GtkWidget		*son;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	group = (GtkSizeGroup*)param;
	state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	set_group_widget_active(group, state);
	if (state == FALSE)
	{
		g_data->objs[g_ui->page_obj].perl_type = PERLIN_NONE;
		return ;
	}
	g_data->objs[g_ui->page_obj].perl_type = PERLIN_CLASSIC;
	lst = gtk_size_group_get_widgets(group);
	while (lst)
	{
		son = (GtkWidget*)lst->data;
		if (GTK_IS_CHECK_BUTTON(son))
			if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(son)) == TRUE)
				g_data->objs[g_ui->page_obj].perl_type = PERLIN_COSINE;
		lst = lst->next;
	}
}

void		check_perlin_cosine(GtkWidget *widget, gpointer param)
{
	gboolean		state;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	if (state == TRUE)
		g_data->objs[g_ui->page_obj].perl_type = PERLIN_COSINE;
	else
		g_data->objs[g_ui->page_obj].perl_type = PERLIN_CLASSIC;
}

void		change_perlin_scale(GtkWidget *widget, gpointer param)
{
	int		value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = (int)gtk_range_get_value(GTK_RANGE(widget));
	g_data->objs[g_ui->page_obj].perl_scale = value;
}

void		change_perlin_opacity(GtkWidget *widget, gpointer param)
{
	double	value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
	g_data->objs[g_ui->page_obj].perl_opacity = value;
}
