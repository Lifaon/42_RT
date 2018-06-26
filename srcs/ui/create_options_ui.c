/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_options_ui.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:57:43 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/26 19:29:57 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

GtkWidget		*cb_quality_draw(t_wid_data *wid_d)
{
	GtkWidget		*cb;
	char			*str;

	if (!(l_new(wid_d, "anti aliasing")) || !wid_d ||
			!(cb = gtk_combo_box_text_new()))
		return (NULL);
	gtk_combo_box_set_id_column(GTK_COMBO_BOX(cb), 0);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "disabled");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "x2");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "x4");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "x8");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "x16");
	gtk_combo_box_set_active(GTK_COMBO_BOX(cb), 1);
	if (g_data->aa == 1)
		str = ft_strdup("disabled");
	else
		str = join_int("x", g_data->aa);
	gtk_combo_box_set_active_id(GTK_COMBO_BOX(cb), str);
	ft_strdel(&str);
	if (wid_d->f)
		g_signal_connect(G_OBJECT(cb), "changed", G_CALLBACK(wid_d->f), wid_d);
	wid_d->pos.y += 1;
	gtk_grid_attach(GTK_GRID(wid_d->grid), cb, wid_d->pos.y, wid_d->pos.x,
			wid_d->size.x, wid_d->size.y);
	return (cb);
}


static int		construct_phase_1(t_wid_data *wid_d)
{
	t_pixelbuf		*pxb;

	if (!(make_label_and_scale(wid_d, "Pixelisation", (double)g_data->px)))
		return (0);
	wid_d->pos.y = 2;
	cb_quality_draw(wid_d);
	wid_d->pos = pt_set(1, 0);
	/*if (!(switch_new(wid_d, wid_d, TRUE, &switch_obj)))
		return (0);
	wid_d->pos = pt_set(0, 1);
	wid_d->f = &modify_obj_type;
	if (!(new_cb_type(wid_d, wid_d, obj)))
		return (0);
	wid_d->pos = pt_set(0, 3);
	pxb = pixelbuf_new(pt_set(30, 30), NULL);
	fill_pixelbuf_in_color(pxb, obj->color.c);
	wid_d->f = &chose_color;
	if (!(b_new(wid_d, (gpointer)pxb->widget, NULL, pxb->widget)))
		return (0);
	pixelbuf_free(&pxb);
	wid_d->pos = pt_set(3, 0);
	set_wid_data_scale(wid_d, 1, ptdb_set(0, 100));
	wid_d->f = &change_obj_spec;
	if (!(make_label_and_scale(wid_d, "specular", obj->spec * 100)))
		return (0);
	wid_d->pos = pt_set(3, 2);
	wid_d->f = change_obj_alpha;
	if (!(make_label_and_scale(wid_d, "Alpha", obj->r * 100)))
		return (0);
	return (construct_phase_2(wid_d, obj));*/
	return (1);
}

int				create_options_ui(GtkWidget *tab)
{
	t_wid_data		wid_d;
	GtkWidget		*l_title;

	if (!(init_wid_data(&wid_d, 1, ptdb_set(0, 5))))
		return (0);
	if (!(construct_phase_1(&wid_d)))
		return (0);
	l_title = gtk_label_new("Options");
	if ((gtk_notebook_append_page(GTK_NOTEBOOK(tab), wid_d.grid, l_title) < 0))
		return (0);
	return (1);
}
