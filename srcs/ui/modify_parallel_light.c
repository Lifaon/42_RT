/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_parallel_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:59:20 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/25 16:09:29 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	switch_parallel_light(GtkWidget *widget, gpointer param)
{
	GSList		*lst;
	GSList		*cpy;
	gboolean	status;
	int			i = 0;

	if (!param)
		return ;
	ft_putstr("lala");
	lst = gtk_size_group_get_widgets(GTK_SIZE_GROUP(param));
	ft_putstr("pouet");
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == TRUE)
	{
		gtk_button_set_label(GTK_BUTTON(widget), "OFF");
		status = FALSE;
	}
	else
	{
		gtk_button_set_label(GTK_BUTTON(widget), "ON");
		status = TRUE;
	}
	//ft_putnbr(status);
	cpy = lst;
	while (lst)
	{
		ft_putnbr(i++);
		ft_putchar('\n');
		gtk_widget_set_sensitive(GTK_WIDGET((GtkWidget*)lst->data), status);
		lst = lst->next;
	}
	//g_slist_free(cpy);
}

void	change_light_distance(GtkWidget *widget, gpointer param)
{
	double		dist;

	if (!widget && !param)
		return ;
	dist = gtk_range_get_value(GTK_RANGE(widget));
	printf("dist = %lf\n", dist);
}

void	change_light_direction(GtkWidget *widget, gpointer param)
{
	double		dir;

	if (!widget && !param)
		return ;
	dir = gtk_range_get_value(GTK_RANGE(widget));
	printf("direction = %lf\n", dir);
}
