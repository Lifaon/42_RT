/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light_ui.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:50:23 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/23 20:09:31 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		make_ray_and_dir(t_wid_data *wid_d, const char *txt,
		GtkSizeGroup *group, gdouble value)
{
	GtkWidget	*entry;
	GtkWidget	*scale;
	gpointer	param;

	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	if (!(l_new(wid_d, txt)))
		return (0);
	wid_d->pos.y = 1;
	if (!(entry = entry_new(wid_d, "", NULL)))
		return (0);
	param = (gpointer)entry;
	if (group)
		param = (gpointer)group;
	if (group)
		gtk_size_group_add_widget(group, entry);
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	wid_d->size = pt_set(2, 1);
	if (!(scale = scale_new(wid_d, param, ptdb_set(-2000000, 2000000), 10)))
		return (0);
	if (group)
		gtk_size_group_add_widget(group, scale);
	gtk_range_set_value(GTK_RANGE(scale), value);
	g_signal_connect(G_OBJECT(entry), "activate", G_CALLBACK(wid_d->f), param);
	wid_d->size = pt_set(1, 1);
	return (1);
}

static int		construct_phase_1(t_wid_data *wid_d)
{
	gpointer		f_data;
	GtkSizeGroup	*group;
	char			*str;
	int				i;
	char			s;

	f_data = (gpointer)g_data;
	if (!(l_new(wid_d, "parrallele light")))
		return (0);
	wid_d->pos.y = 1;
	wid_d->f = &switch_parallel_light;
	if (!(tgb_new(wid_d, f_data, "ON")))
		return (0);
	if (!(group = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (0);
	wid_d->f = &change_light_distance;
	make_ray_and_dir(wid_d, "distance", NULL, 4);
	wid_d->f = &change_light_direction;
	i = -1;
	s = 'x';
	while (++i < 3)
	{
		str = ft_strjoin(&s, " direction");
		make_ray_and_dir(wid_d, str, group, 12);
		ft_strdel(&str);
		s++;
	}
	return (1);
}

int				create_light_ui(GtkWidget *tab)
{
	GtkWidget		*l_title;
	t_wid_data		wid_d;

	l_title = gtk_label_new("Light");
	wid_d.grid = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(wid_d.grid), 5);
	gtk_grid_set_column_spacing(GTK_GRID(wid_d.grid), 5);
	gtk_grid_set_row_homogeneous(GTK_GRID(wid_d.grid), TRUE);
	gtk_grid_set_column_homogeneous(GTK_GRID(wid_d.grid), TRUE);
	set_wid_data(&wid_d, pt_set(0, 0), pt_set(1, 1), NULL);
	if (!(construct_phase_1(&wid_d)))
		return (0);
	if (gtk_notebook_append_page(GTK_NOTEBOOK(tab), wid_d.grid, l_title) < 0)
		return (0);
	return (1);
}
