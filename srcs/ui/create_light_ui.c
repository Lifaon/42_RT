/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light_ui.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:50:23 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/29 18:33:28 by fchevrey         ###   ########.fr       */
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
	if (!(entry = entry_new(wid_d, NULL, "")))
		return (0);
	param = (gpointer)group;
	gtk_size_group_add_widget(group, entry);
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	wid_d->size = pt_set(2, 1);
	if (!(scale = scale_new(wid_d, param, ptdb_set(-2000000, 2000000), 10)))
		return (0);
	gtk_size_group_add_widget(group, scale);
	gtk_range_set_value(GTK_RANGE(scale), value);
	g_signal_connect(G_OBJECT(entry), "activate",
			G_CALLBACK(entry_change_scale), (gpointer)scale);
	wid_d->size = pt_set(1, 1);
	return (1);
}

static int		make_grid(t_wid_data *wid_d)
{
	if (!(wid_d->grid = gtk_grid_new()))
		return (0);
	gtk_grid_set_row_spacing(GTK_GRID(wid_d->grid), 5);
	gtk_grid_set_column_spacing(GTK_GRID(wid_d->grid), 5);
	gtk_grid_set_row_homogeneous(GTK_GRID(wid_d->grid), TRUE);
	gtk_grid_set_column_homogeneous(GTK_GRID(wid_d->grid), TRUE);
	set_wid_data(wid_d, pt_set(0, 0), pt_set(1, 1), NULL);
	return (1);
}

static int		construct_phase_1(t_wid_data *wid_d)
{
	GtkSizeGroup	*group;
	char			*str;
	char			s[2];

	if (!(make_grid(wid_d)) || !(l_new(wid_d, "parrallele light")))
		return (0);
	if (!(group = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (0);
	wid_d->f = &change_light_direction;
	s[0] = 'x';
	s[1] = '\0';
	while (s[0] <= 'z')
	{
		str = ft_strjoin(s, " direction");
		if (make_ray_and_dir(wid_d, str, group, 12) < 1)
			return (0);
		ft_strdel(&str);
		s[0] = s[0] + 1;
	}
	wid_d->pos = pt_set(0, 1);
	wid_d->f = &switch_parallel_light;
	if (!(tgb_new(wid_d, (gpointer)group, "ON")))
		return (0);
	return (1);
}

int				create_light_ui(GtkWidget *tab)
{
	GtkWidget		*l_title;
	t_wid_data		wid_d;
	GtkWidget		*tab_light;
	int				i;
	char			*str;

	i = 0;
	if (!(tab_light = gtk_notebook_new()))
		return (0);
	g_signal_connect(G_OBJECT(tab_light), "change-current-page",
			G_CALLBACK(change_page_light), NULL);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(tab_light), TRUE);
	while (i < g_data->nb_lights)
	{
		i++;
		if (!(str = join_int("Light ", i)) || !(l_title = gtk_label_new(str)))
			return (0);
		if (!(construct_phase_1(&wid_d)))
			return (0);
		if ((gtk_notebook_append_page(GTK_NOTEBOOK(tab_light), wid_d.grid,
						l_title)) < 0)
			return (0);
		ft_strdel(&str);
	}
	if (!(l_title = gtk_label_new("Light")))
		return (0);
	if (gtk_notebook_append_page(GTK_NOTEBOOK(tab), tab_light, l_title) < 0)
		return (0);
	return (1);
}
