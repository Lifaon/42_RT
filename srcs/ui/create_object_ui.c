/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object_ui.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:00:25 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/24 20:03:20 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int		construct_phase_2(t_wid_data *wid_d, int index)
{
	GtkSizeGroup	*group;
	t_vec			vec;

	wid_d->pos = pt_set(3, 0);
	wid_d->f = &change_obj_dir;
	vec = g_data->objs[index].angle;
	if (!(group = add_vector_choose(wid_d, "direction", vec)))
		return (0);
	vec = g_data->objs[index].pos;
	wid_d->f = &change_obj_pos;
	set_wid_data_scale(wid_d, 10, ptdb_set(-10000, 10000));
	if (!(add_vector_choose(wid_d, "position", vec)))
		return (0);
	return (1);
}

static int		construct_phase_1(t_wid_data *wid_d, int index)
{
	t_pixelbuf		*pxb;

	if (!(l_new(wid_d, "Object")))
		return (0);
	wid_d->pos = pt_set(0, 1);
	if (!(switch_new(wid_d, wid_d, TRUE, &switch_obj)))
		return (0);
	wid_d->pos = pt_set(1, 0);
	wid_d->f = &modify_obj_type;
	if (!(new_cb_type(wid_d, wid_d, index)))
		return (0);
	wid_d->pos = pt_set(2, 0);
	pxb = pixelbuf_new(pt_set(50, 50), NULL);
	fill_pixelbuf_in_color(pxb, g_data->objs[index].color.c);
	wid_d->f = &chose_color;
	if (!(b_new(wid_d, (gpointer)pxb->widget, NULL, pxb->widget)))
		return (0);
	pixelbuf_free(&pxb);
	return (construct_phase_2(wid_d, index));
}

static int		create_new_obj_button(GtkWidget *box)
{
	GtkWidget		*button;

	if (!(button = gtk_button_new_with_label("add object")))
		return (0);
	gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 10);
	g_signal_connect(G_OBJECT(button), "clicked",
			G_CALLBACK(add_one_obj), NULL);
	return (1);
}

int				create_object_tab(GtkWidget *tab_obj, int index)
{
	GtkWidget		*l_title;
	t_wid_data		wid_d;
	char			*str;

	if (!(init_wid_data(&wid_d, 1, ptdb_set(-180, 180))))
		return (0);
	if (!(str = join_int("Object ", index + 1)))
		return (0);
	if (!(l_title = gtk_label_new(str)))
		return (0);
	if ((gtk_notebook_append_page(GTK_NOTEBOOK(tab_obj), wid_d.grid,
			l_title)) < 0)
		return (0);
	gtk_widget_show_all(tab_obj);
	while (g_data->ui->page_obj < index)
		gtk_notebook_next_page(GTK_NOTEBOOK(tab_obj));
	if (!(construct_phase_1(&wid_d, index)))
		return (0);
	ft_strdel(&str);
	return (1);
}

int				create_object_ui(GtkWidget *tab)
{
	GtkWidget		*l_title;
	GtkWidget		*box;
	int				i;

	if (!(g_data->ui->tab_objs = gtk_notebook_new()))
		return (0);
	g_signal_connect(G_OBJECT(g_data->ui->tab_objs), "switch-page",
			G_CALLBACK(change_page_obj), NULL);
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	create_new_obj_button(box);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(g_data->ui->tab_objs), TRUE);
	i = -1;
	while (++i < g_data->nb_objects)
		if (!(create_object_tab(g_data->ui->tab_objs, i)))
			return (0);
	if (!(l_title = gtk_label_new("Object")))
		return (0);
	gtk_box_pack_start(GTK_BOX(box), g_data->ui->tab_objs, FALSE, FALSE, 0);
	if (gtk_notebook_append_page(GTK_NOTEBOOK(tab), box, l_title) < 0)
		return (0);
	return (1);
}
