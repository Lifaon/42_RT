/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_entry_and_scale.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:02:47 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/07 13:47:39 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		make_entry_and_scale(t_wid_data *wid_d, const char *txt,
			GtkSizeGroup *group, gdouble value)
{
	GtkWidget	*entry;
	GtkWidget	*scale;
	void		(*f_swap)(GtkWidget*, gpointer);

	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	if (!(l_new(wid_d, txt)))
		return (0);
	wid_d->pos.y = 1;
	f_swap = wid_d->f;
	wid_d->f = NULL;
	if (!(entry = entry_new(wid_d, NULL, "")))
		return (0);
	gtk_size_group_add_widget(group, entry);
	wid_d->f = f_swap;
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	wid_d->size = pt_set(2, 1);
	if (!(scale = scale_new(wid_d, (void*)group, ptdb_set(-9000, 9000), 10)))
		return (0);
	gtk_size_group_add_widget(group, scale);
	gtk_range_set_value(GTK_RANGE(scale), value);
	g_signal_connect(G_OBJECT(entry), "activate",
			G_CALLBACK(entry_change_scale), (gpointer)scale);
	wid_d->size = pt_set(1, 1);
	return (1);
}
