/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light_ui.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:50:23 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/30 20:09:50 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

static GtkSizeGroup		*add_vector_choose(t_wid_data *wid_d, char *label,
		t_vec *vec)
{
	t_widget_vec	*wid_vec;
	char			*str;
	char			s[3];

	wid_vec = (t_widget_vec*)malloc(sizeof(t_widget_vec));
	wid_vec->group = gtk_size_group_new(GTK_SIZE_GROUP_NONE);
	wid_vec->vec = vec;
	/*if (!(fill_widget_vec(&wid_vec, NULL, vec)))
		return (NULL);*/
	//s = ft_strcpy(s, "x ");
	s[0] = 'x';
	s[1] = ' ';
	s[2] = '\0';
	while (s[0] <= 'z')
	{
		str = ft_strjoin(s, label);
		if (s[0] == 'x')
			if (make_entry_and_scale(wid_d, str, wid_vec, vec->x) < 1)
				return (NULL);
		if (s[0] == 'y')
			if (make_entry_and_scale(wid_d, str, wid_vec, vec->y) < 1)
				return (NULL);
		if (s[0] == 'z')
			if (make_entry_and_scale(wid_d, str, wid_vec, vec->z) < 1)
				return (NULL);
		ft_strdel(&str);
		s[0] = s[0] + 1;
	}
	return (wid_vec->group);
}

static int		construct_phase_1(t_wid_data *wid_d, int index)
{
	GtkSizeGroup	*group;
	char			*str;
	t_vec			*vec;

	ft_putstr("index = ");
	ft_putnbr(index);
	ft_putchar('\n');
	if (!(make_grid(wid_d)) || !(l_new(wid_d, "parrallele light")))
		return (0);
	//wid_d->f = &change_light_direction;
	wid_d->f = &change_vec_from_scale;
	vec = &g_data->lights[index].dir;
	ft_putstr("bla\n");
	if (!(group = add_vector_choose(wid_d, "direction", vec)))
		return (0);
	vec = &g_data->lights[index].pos;
	//wid_d->f = &change_light_position;
	ft_putstr("bli\n");
	if (!(add_vector_choose(wid_d, "position", vec)))
		return (0);
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

	if (!(tab_light = gtk_notebook_new()))
		return (0);
	g_signal_connect(G_OBJECT(tab_light), "switch-page",
			G_CALLBACK(change_page_light), NULL);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(tab_light), TRUE);
	i = 0;
	while (i < g_data->nb_lights)
	{
		i++;
		if (!(str = join_int("Light ", i)) || !(l_title = gtk_label_new(str)))
			return (0);
		if (!(construct_phase_1(&wid_d, i - 1)))
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
