/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_widgets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:07:39 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/24 19:23:36 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

GtkWidget	*switch_new(t_wid_data *wid_d, gpointer param, gboolean state,
		void (*f)(GtkWidget*, gboolean, gpointer))
{
	GtkWidget	*sw;

	if (!(sw = gtk_switch_new()))
		return (NULL);
	gtk_switch_set_state(GTK_SWITCH(sw), state);
	if (f)
		g_signal_connect(G_OBJECT(sw), "state-set", G_CALLBACK(f),
				param);
	if (wid_d)
		gtk_grid_attach(GTK_GRID(wid_d->grid), sw, wid_d->pos.y, wid_d->pos.x,
			wid_d->size.x, wid_d->size.y);
	return (sw);
}

GtkWidget	*b_new(t_wid_data *wid_d, gpointer param, const char *txt,
		GtkWidget *img)
{
	GtkWidget	*b;
	GtkWidget	*label;
	GtkWidget	*box;

	if (!(b = gtk_button_new()))
		return (NULL);
	if (txt || img)
		if (!(box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5)))
			return (NULL);
	if (img)
		gtk_box_pack_start(GTK_BOX(box), img, TRUE, TRUE, 2);
	if (txt)
	{
		if (!(label = gtk_label_new(txt)))
			return (NULL);
		gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 2);
	}
	if (txt || img)
		gtk_container_add(GTK_CONTAINER(b), box);
	if (wid_d->f)
		g_signal_connect(G_OBJECT(b), "clicked", G_CALLBACK(wid_d->f), param);
	if (wid_d)
		gtk_grid_attach(GTK_GRID(wid_d->grid), b, wid_d->pos.y,
				wid_d->pos.x, wid_d->size.x, wid_d->size.y);
	return (b);
}

GtkWidget	*tgb_new(t_wid_data *wid_d, gpointer param, const char *txt)
{
	GtkWidget	*tgb;

	if (!(tgb = gtk_toggle_button_new_with_label(txt)))
		return (NULL);
	if (wid_d->f)
		g_signal_connect(G_OBJECT(tgb), "clicked", G_CALLBACK(wid_d->f),
				param);
	if (wid_d)
		gtk_grid_attach(GTK_GRID(wid_d->grid), tgb, wid_d->pos.y, wid_d->pos.x,
			wid_d->size.x, wid_d->size.y);
	return (tgb);
}

GtkWidget	*scale_new(t_wid_data *wid_d, gpointer param, gdouble value)
{
	GtkWidget		*scale;

	if (!(scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL,
					wid_d->min_max.x, wid_d->min_max.y, wid_d->step)))
		return (NULL);
	gtk_range_set_value(GTK_RANGE(scale), value);
	if (wid_d->f)
		g_signal_connect(G_OBJECT(scale), "value-changed",
				G_CALLBACK(wid_d->f), param);
	if (wid_d)
		gtk_grid_attach(GTK_GRID(wid_d->grid), scale, wid_d->pos.y,
				wid_d->pos.x, wid_d->size.x, wid_d->size.y);
    gtk_widget_set_can_focus(scale, FALSE);
	return (scale);
}

GtkWidget	*entry_new(t_wid_data *wid_d, gpointer param, const char *txt)
{
	GtkWidget	*entry;

	if (!(entry = gtk_entry_new()))
		return (NULL);
	if (wid_d->f)
		g_signal_connect(G_OBJECT(entry), "activate", G_CALLBACK(wid_d->f),
				param);
	if (txt)
		gtk_entry_set_text(GTK_ENTRY(entry), txt);
	if (wid_d)
		gtk_grid_attach(GTK_GRID(wid_d->grid), entry, wid_d->pos.y,
			wid_d->pos.x, wid_d->size.x, wid_d->size.y);
	return (entry);
}

GtkWidget	*l_new(t_wid_data *wid_d, const char *txt)
{
	GtkWidget	*label;

	if (!(label = gtk_label_new(txt)))
		return (NULL);
	if (wid_d)
		gtk_grid_attach(GTK_GRID(wid_d->grid), label, wid_d->pos.y,
				wid_d->pos.x, wid_d->size.x, wid_d->size.y);
	return (label);
}
