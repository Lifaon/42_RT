/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light_ui.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:50:23 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/07 16:15:48 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		make_grid(t_wid_data *wid_d)
{
	if (!(wid_d->grid = gtk_grid_new()))
		return (0);
	wid_d->pos = pt_set(0, 1);
	wid_d->size = pt_set(1, 1);
	wid_d->f = NULL;
	gtk_grid_set_row_spacing(GTK_GRID(wid_d->grid), 5);
	gtk_grid_set_column_spacing(GTK_GRID(wid_d->grid), 5);
	//gtk_grid_set_row_homogeneous(GTK_GRID(wid_d->grid), TRUE);
	gtk_grid_set_column_homogeneous(GTK_GRID(wid_d->grid), TRUE);
	set_wid_data(wid_d, pt_set(0, 0), pt_set(1, 1), NULL);
	return (1);
}

static int		construct_phase_1(t_wid_data *wid_d, int index)
{
	GtkSizeGroup	*group;
	t_vec			vec;

	if (!(l_new(wid_d, "light")))
		return (0);
	wid_d->pos = pt_set(0, 1);
	if (!(switch_new(wid_d, NULL, TRUE, &switch_light)))
		return (0);
	wid_d->pos = pt_set(1, 0);
	if (!(l_new(wid_d, "parrallele light")))
		return (0);
	wid_d->f = &change_light_dir;
	vec = g_data->lights[index].dir;
	if (!(group = add_vector_choose(wid_d, "direction", vec)))
		return (0);
	vec = g_data->lights[index].pos;
	wid_d->f = &change_light_pos;
	if (!(add_vector_choose(wid_d, "position", vec)))
		return (0);
	wid_d->pos = pt_set(1, 1);
	if (!(switch_new(wid_d, (gpointer)group, TRUE, &switch_parallel_light)))
		return (0);
	return (1);
}

static int		create_light_button(GtkWidget *box)
{
	GtkWidget		*button;

	if (!(button = gtk_button_new_with_label("add new light")))
		return (0);
	gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 10);
	g_signal_connect(G_OBJECT(button), "clicked",
			G_CALLBACK(add_one_light), NULL);
	return (1);
}

int				add_one_light_tab(GtkWidget *tab_light, int index)
{
	GtkWidget		*l_title;
	t_wid_data		wid_d;
	char			*str;

	if (!(make_grid(&wid_d)))
		return (0);
	if (!(str = join_int("Light ", index + 1)) || !(l_title = gtk_label_new(str)))
		return (0);
	if ((gtk_notebook_append_page(GTK_NOTEBOOK(tab_light), wid_d.grid,
			l_title)) < 0)
		return (0);
	gtk_widget_show_all(tab_light);
	while (g_data->ui->page_light < index)
		gtk_notebook_next_page(GTK_NOTEBOOK(tab_light));
	if (!(construct_phase_1(&wid_d, index)))
		return (0);
	ft_strdel(&str);
	return (1);
}

int				create_light_ui(GtkWidget *tab)
{
	GtkWidget		*l_title;
	GtkWidget		*box;
	int				i;

	if (!(g_data->ui->tab_light = gtk_notebook_new()))
		return (0);
	g_signal_connect(G_OBJECT(g_data->ui->tab_light), "switch-page",
			G_CALLBACK(change_page_light), NULL);
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	create_light_button(box);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(g_data->ui->tab_light), TRUE);
	i = -1;
	while (++i < g_data->nb_lights)
		if (!(add_one_light_tab(g_data->ui->tab_light, i)))
			return (0);
	if (!(l_title = gtk_label_new("Light")))
		return (0);
	gtk_box_pack_start(GTK_BOX(box), g_data->ui->tab_light, FALSE, FALSE, 0);
	if (gtk_notebook_append_page(GTK_NOTEBOOK(tab), box, l_title) < 0)
		return (0);
	return (1);
}
