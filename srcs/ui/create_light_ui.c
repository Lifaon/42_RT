/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light_ui.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:50:23 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/14 17:32:12 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int		construct_phase_2(t_wid_data *wid_d, t_light *light,
		GtkSizeGroup *group)
{
	t_pixelbuf		*pxb;
	gboolean		para;

	wid_d->pos = pt_set(wid_d->pos.x - 1, 2);
	wid_d->f = &change_light_ambi;
	set_wid_data_scale(wid_d, 1, ptdb_set(0, 100));
	if (!(make_label_and_scale(wid_d, "ambiante", light->ambi, light)))
		return (0);
	pxb = pixelbuf_new(pt_set(30, 30), NULL);
	fill_pixelbuf_in_color(pxb, light->color.c);
	wid_d->f = &change_light_color;
	wid_d->size = pt_set(2, 1);
	if (!(b_new(wid_d, (gpointer)pxb->widget, "light color", pxb->widget)))
		return (0);
	wid_d->size = pt_set(1, 1);
	free(pxb);
	wid_d->pos = pt_set(0, 3);
	para = FALSE;
	if (light->is_para == 1)
		para = TRUE;
	if (!(switch_new(wid_d, (gpointer)group, para, &switch_parallel_light)))
		return (0);
	set_group_widget_active(group, para);
	return (1);
}

static int		construct_phase_1(t_wid_data *wid_d, t_light *light)
{
	GtkSizeGroup	*group;
	t_vec			vec;

	if (!(make_label_and_switch(wid_d, "light", TRUE, &switch_light)))
		return (0);
	wid_d->pos = pt_set(0, 2);
	if (!(l_new(wid_d, "parrallele light")))
		return (0);
	wid_d->pos = pt_set(1, 0);
	vec = light->pos;
	wid_d->f = &change_light_pos;
	if (!(add_vector_choose(wid_d, "position", vec)))
		return (0);
	wid_d->pos = pt_set(1, 2);
	wid_d->f = &change_light_angle;
	vec = light->angle;
	wid_d->min_max = ptdb_set(-180, 180);
	if (!(group = add_vector_choose(wid_d, "direction", vec)))
		return (0);
	wid_d->pos.y = 0;
	wid_d->entry_f = change_light_r;
	set_wid_data_scale(wid_d, 0.01, ptdb_set(0.0, 1.0));
	if (!(make_label_and_entry(wid_d, "radius", light->r, light)))
		return (0);
	return (construct_phase_2(wid_d, light, group));
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

int				create_light_tab(GtkWidget *tab_light, int index)
{
	GtkWidget		*l_title;
	t_wid_data		wid_d;
	char			*str;

	if (!(init_wid_data(&wid_d, 10, ptdb_set(-75000, 75000))))
		return (0);
	if (!(str = join_int("Light ", index + 1)))
		return (0);
	if (!(l_title = gtk_label_new(str)))
		return (0);
	if ((gtk_notebook_append_page(GTK_NOTEBOOK(tab_light), wid_d.grid,
			l_title)) < 0)
		return (0);
	gtk_widget_show_all(tab_light);
	while (g_ui->page_light < index)
		gtk_notebook_next_page(GTK_NOTEBOOK(tab_light));
	if (!(construct_phase_1(&wid_d, &g_data->lights[index])))
		return (0);
	ft_strdel(&str);
	return (1);
}

int				create_light_ui(GtkWidget *tab)
{
	GtkWidget		*l_title;
	GtkWidget		*box;
	int				i;

	if (!(g_ui->tab_light = gtk_notebook_new()))
		return (0);
	g_signal_connect(G_OBJECT(g_ui->tab_light), "switch-page",
			G_CALLBACK(change_page_light), NULL);
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	create_light_button(box);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(g_ui->tab_light), TRUE);
	i = -1;
	while (++i < g_data->nb_lights)
		if (!(create_light_tab(g_ui->tab_light, i)))
			return (0);
	if (!(l_title = gtk_label_new("Light")))
		return (0);
	gtk_box_pack_start(GTK_BOX(box), g_ui->tab_light, FALSE, FALSE, 0);
	if (gtk_notebook_append_page(GTK_NOTEBOOK(tab), box, l_title) < 0)
		return (0);
	return (1);
}
