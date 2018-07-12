/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_widget2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:58:04 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/12 16:23:39 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

GtkWidget	*check_box_new(t_wid_data *wid_d, char *txt, gpointer param)
{
	GtkWidget	*checkb;

	if (!txt)
		checkb = gtk_check_button_new();
	else
		checkb = gtk_check_button_new_with_label(txt);
	if (wid_d->f)
		g_signal_connect(G_OBJECT(b), "toggled", G_CALLBACK(wid_d->f), param);
	gtk_grid_attach(GTK_GRID(wid_d->grid), b, wid_d->pos.y,
				wid_d->pos.x, wid_d->size.x, wid_d->size.y);
	return (checkb);
}
