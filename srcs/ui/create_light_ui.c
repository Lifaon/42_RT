/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light_ui.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:50:23 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 21:12:39 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int		construct_phase_2(t_wid_data *wid_d, t_light *light,
		GtkSizeGroup *group)
{
	t_pixelbuf		*pxb;
	gboolean		para;

	wid_d->pos.y += 2;
	wid_d->f = &change_light_ambi;
	set_wid_data_scale(wid_d, 1, ptdb_set(0, 100));
	if (!(make_label_and_scale(wid_d, "ambiante", light->ambi, light)))
		return (0);
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
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
	GtkWidget 		*w;

	if (!(w = make_label_and_switch(wid_d, "light", TRUE, &switch_light)))
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

static int		create_light_button(GtkWidget *box, GtkSizeGroup *gp)
{
	GtkWidget		*w;
	t_wid_data		wid_d;

	if (!(init_wid_data(&wid_d, 1, ptdb_set(1, 200))))
		return (0);
	wid_d.size.x = 2;
	wid_d.f = &add_one_light;
	if (!(w = b_new(&wid_d, NULL, "add new light", NULL)))
		return (0);	
	wid_d.size.x = 1;
	wid_d.pos.y += 2;
	//if (!(w = gtk_button_new_with_label("add new light")))
		//return (0);
	//gtk_box_pack_start(GTK_BOX(box), w, FALSE, FALSE, 10);
	//g_signal_connect(G_OBJECT(w), "clicked",
	//		G_CALLBACK(add_one_light), NULL);
	wid_d.f = check_caustic;
	if (!(new_check_button(&wid_d, "caustic", gp, NULL)))
		return (0);
	wid_d.f = change_photon_size;
	wid_d.pos = pt_set(wid_d.pos.x + 1, 0);
	if (!(w = make_label_and_scale(&wid_d, "photon size",
				(double)g_data->photon_size, gp)))
		return (0);
	wid_d.f = change_photon_intensity;
	wid_d.pos.y += 2;
	gtk_size_group_add_widget(gp, w);
	if (!(w = make_label_and_scale(&wid_d, "photon intensity",
				(double)g_data->photon_ppx, gp)))
		return (0);
	gtk_size_group_add_widget(gp, w);
	gtk_box_pack_start(GTK_BOX(box), wid_d.grid, FALSE, FALSE, 10);
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
	GtkSizeGroup	*gp_caustic;

	if (!(g_ui->tab_light = gtk_notebook_new()))
		return (0);
	if (!(gp_caustic = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (0);
	g_signal_connect(G_OBJECT(g_ui->tab_light), "switch-page",
			G_CALLBACK(change_page_light), NULL);
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	if (!(create_light_button(box, gp_caustic)))
		return (0);
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
