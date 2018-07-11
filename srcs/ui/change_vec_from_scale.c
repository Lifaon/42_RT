/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_vec_from_scale.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:36:15 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/11 15:23:46 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ui.h"

static void		fill_vec(t_vec *vec, double nb)
{
	static int i = 0;

	if (!vec)
		return ;
	if (i > 2)
		i = 0;
	if (i == 0)
		vec->z = nb;
	else if (i == 1)
		vec->y = nb;
	else if (i == 2)
		vec->x = nb;
	i++;
}

static void		fill_color(t_color *color, uint8_t nb)
{
	static int i = 0;

	if (!color)
		return ;
	if (i > 2)
		i = 0;
	if (i == 0)
		color->argb.b = nb;
	else if (i == 1)
		color->argb.g = nb;
	else if (i == 2)
		color->argb.r = nb;
	i++;
}

void			change_vec_from_entry(GtkSizeGroup *group, t_vec *vec, int
					mode_infinity, t_ptdb limits)
{
	double		value;
	GtkWidget	*son;
	const char	*str;
	GSList		*lst;

	lst = gtk_size_group_get_widgets(GTK_SIZE_GROUP(group));
	while (lst)
	{	
		son = (GtkWidget*)lst->data;
		if (GTK_IS_ENTRY(son))
		{
			str = gtk_entry_get_text(GTK_ENTRY(son));
			value = get_double_from_entry(son, mode_infinity, limits.x, limits.y);
			fill_vec(vec, value);
		}
		lst = lst->next;
	}
}


void			change_vec_from_scale(GtkSizeGroup *group, t_vec *vec)
{
	double		value;
	GtkWidget	*son;
	char		*str;
	GSList		*lst;

	lst = gtk_size_group_get_widgets(GTK_SIZE_GROUP(group));
	while (lst)
	{
		son = (GtkWidget*)lst->data;
		if (GTK_IS_SCALE(son))
		{
			value = gtk_range_get_value(GTK_RANGE(son));
			fill_vec(vec, value);
		}
		if (GTK_IS_ENTRY(son))
		{
			str = ft_dbtoa(value);
			gtk_entry_set_text(GTK_ENTRY(son), str);
			ft_strdel(&str);
		}
		lst = lst->next;
	}
}

void			change_color_from_group(GtkSizeGroup *group, t_color *color)
{
	double		value;
	GtkWidget	*son;
	char		*str;
	GSList		*lst;

	lst = gtk_size_group_get_widgets(GTK_SIZE_GROUP(group));
	while (lst)
	{
		son = (GtkWidget*)lst->data;
		if (GTK_IS_SCALE(son))
		{
			value = gtk_range_get_value(GTK_RANGE(son));
			fill_color(color, (uint8_t)value);
		}
		if (GTK_IS_ENTRY(son))
		{
			str = ft_dbtoa(value);
			gtk_entry_set_text(GTK_ENTRY(son), str);
			ft_strdel(&str);
		}
		lst = lst->next;
	}
}
