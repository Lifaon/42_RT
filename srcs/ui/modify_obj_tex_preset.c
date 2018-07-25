/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_tex_preset.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 19:38:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 12:06:24 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int			get_state_of_scale(const char *label, GtkWidget *button,
		gboolean label_state)
{
	int				dst;
	const char		*str;

	dst = 0;
	str = gtk_button_get_label(GTK_BUTTON(button));
	if (label && ft_strcmp(str, label) == 0)
		gtk_widget_set_sensitive(button, label_state);
	if ((ft_strcmp(str, "Rainbow") == 0 ) ||
		(ft_strcmp(str, "Checkboard") == 0))
	{
		if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button)) == TRUE)
			dst = 1;
	}
	return (dst);
}

static void			check_textures(GtkSizeGroup *group, const char *label,
	gboolean label_state)
{
	GtkWidget		*son;
	GtkWidget		*scale;
	GSList			*lst;
	gboolean		state;

	state = FALSE;
	scale = NULL;
	lst = gtk_size_group_get_widgets(group);
	while (lst)
	{
		son = (GtkWidget*)lst->data;
		if (GTK_IS_CHECK_BUTTON(son))
		{
			if (get_state_of_scale(label, son, label_state) == 1)
				state = TRUE;
		}
		else if (GTK_IS_SCALE(son))
			scale = son;
		lst = lst->next;
	}
	if (scale)
		gtk_widget_set_sensitive(scale, state);
}

void				check_checkboard(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	gboolean		state;
	GtkWidget 		*son;
	GSList			*lst;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	group = (GtkSizeGroup*)param;
	state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	if (state == TRUE)
		check_textures(group, "Rainbow", FALSE);
	else
		check_textures(group, "Rainbow", TRUE);
	if (state == TRUE)
		g_data->objs[g_ui->page_obj].color_type = COLOR_CHECKERBOARD;
	else
		g_data->objs[g_ui->page_obj].color_type = COLOR_SIMPLE;
	lst = gtk_size_group_get_widgets(group);
	while (lst)
	{
		son = (GtkWidget*)lst->data;
		if (GTK_IS_BUTTON(son) == TRUE && GTK_IS_CHECK_BUTTON(son) == FALSE)
			gtk_widget_set_sensitive(son, state);
		lst = lst->next;
	}
}

void				check_rainbow(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	gboolean		state;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	group = (GtkSizeGroup*)param;
	state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	if (state == TRUE)
	{
		check_textures(group, "Checkboard", FALSE);
		g_data->objs[g_ui->page_obj].color_type = COLOR_RAINBOW;
	}
	else
	{
		check_textures(group, "Checkboard", TRUE);
		g_data->objs[g_ui->page_obj].color_type = COLOR_SIMPLE;
	}
}

void				change_color_scale(GtkWidget *widget, gpointer param)
{
	int		value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = (int)gtk_range_get_value(GTK_RANGE(widget));
	g_data->objs[g_ui->page_obj].color_scale = value;
}
