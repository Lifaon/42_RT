/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object_ui.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:00:25 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/21 09:00:32 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"


static int		construct_phase_1(t_wid_data *wid_d, t_obj *obj)
{
	t_pixelbuf		*pxb;

	if (!(switch_new(wid_d, wid_d, TRUE, &switch_obj)))
		return (0);
	wid_d->pos = pt_set(0, 1);
	wid_d->f = &modify_obj_type;
	if (!(new_cb_type(wid_d, wid_d, obj)))
		return (0);
	wid_d->pos = pt_set(0, 3);
	if (!(pxb = pixelbuf_new(pt_set(30, 30), NULL)))
		return (0);
	fill_pixelbuf_in_color(pxb, obj->color.c);
	wid_d->f = &change_obj_color;
	if (!(b_new(wid_d, (gpointer)pxb->widget, NULL, pxb->widget)))
		return (0);
	free(pxb);
	wid_d->pos = pt_set(3, 0);
	set_wid_data_scale(wid_d, 1, ptdb_set(0, 100));
	wid_d->f = &change_obj_spec;
	if (!(make_label_and_scale(wid_d, "specular", obj->spec * 100, obj)))
		return (0);
	wid_d->pos = pt_set(3, 2);
	wid_d->f = change_obj_alpha;
	wid_d->min_max = ptdb_set(1, 200);
	return (obj_construct_phase_2(wid_d, obj));
}

static GtkWidget 	*create_scrollable(GtkWidget *child)
{
	GtkAdjustment	*v_adj;
	GtkAdjustment	*h_adj;
	GtkWidget 		*sbar;

	if (!(v_adj = gtk_adjustment_new(0, 0, 1020, 10, 100, 20)))
		return (NULL);
	if (!(h_adj = gtk_adjustment_new(0, 0, 0, 0, 0, 0)))
		return (NULL);
	if (!(sbar = gtk_scrolled_window_new(NULL, v_adj)))
		return (NULL);
	gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(sbar),
			g_data->img->size.y - 200);
	gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(sbar), FALSE);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(sbar),
                                GTK_POLICY_NEVER,
                                GTK_POLICY_AUTOMATIC);
	gtk_container_add(GTK_CONTAINER(sbar), child);
	return (sbar);
}

int				create_object_tab(GtkWidget *tab_obj, int index)
{
	GtkWidget		*l_title;
	t_wid_data		wid_d;
	char			*str;
	GtkWidget 		*sbar;

	if (!(init_wid_data(&wid_d, 1, ptdb_set(-180, 180))))
		return (0);
	if (!(str = join_int("Object ", index + 1)))
		return (0);
	if (!(l_title = gtk_label_new(str)))
		return (0);
	if (!(sbar = create_scrollable(wid_d.grid)))
		return (0);
	if ((gtk_notebook_append_page(GTK_NOTEBOOK(tab_obj), sbar,
			l_title)) < 0)
		return (0);
	gtk_widget_show_all(tab_obj);
	while (g_ui->page_obj < index)
		gtk_notebook_next_page(GTK_NOTEBOOK(tab_obj));
	gtk_widget_show_all(tab_obj);
	if (!(construct_phase_1(&wid_d, &g_data->objs[index])))
		return (0);
	ft_strdel(&str);
	return (1);
}

int				create_object_ui(GtkWidget *tab)
{
	GtkWidget		*l_title;
	GtkWidget		*box;
	GtkWidget		*but;
	int				i;

	if (!(g_ui->tab_objs = gtk_notebook_new()))
		return (0);
	g_signal_connect(G_OBJECT(g_ui->tab_objs), "switch-page",
			G_CALLBACK(change_page_obj), NULL);
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	if (!(but = gtk_button_new_with_label("add object")))
		return (0);
	gtk_box_pack_start(GTK_BOX(box), but, FALSE, FALSE, 10);
	g_signal_connect(G_OBJECT(but), "clicked", G_CALLBACK(add_one_obj), box);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(g_ui->tab_objs), TRUE);
	i = -1;
	while (++i < g_data->nb_objects)
		if (!(create_object_tab(g_ui->tab_objs, i)))
			return (0);
	if (!(l_title = gtk_label_new("Object")))
		return (0);
	gtk_box_pack_start(GTK_BOX(box), g_ui->tab_objs, FALSE, FALSE, 0);
	if (gtk_notebook_append_page(GTK_NOTEBOOK(tab), box, l_title) < 0)
		return (0);
	return (1);
}
