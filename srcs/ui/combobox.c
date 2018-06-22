/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combobox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:48:28 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/22 21:05:15 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

GtkWidget		*new_cb_type(t_wid_data *wid_d, gpointer param, int index)
{
	GtkWidget		*cb;
	char			*str;

	if (!(l_new(wid_d, "Type")))
		return (NULL);
	if (!(cb = gtk_combo_box_text_new()))
		return (NULL);
	gtk_combo_box_set_id_column(GTK_COMBO_BOX(cb), 0);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "sphere");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "plane");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "cone");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "cylinder");
	gtk_combo_box_set_active(GTK_COMBO_BOX(cb), 1);
	str = get_str_obj_type(g_data->objs[index].obj_type);
	ft_putendl(str);
	gtk_combo_box_set_active_id(GTK_COMBO_BOX(cb), str);
	ft_strdel(&str);
	if (wid_d->f)
		g_signal_connect(G_OBJECT(cb), "changed", G_CALLBACK(wid_d->f), param);
	wid_d->pos.y += 1;
	printf("index = %d pos.x = %d, y = %d\n", index, wid_d->pos.x, wid_d->pos.y);
	if (wid_d)
		gtk_grid_attach(GTK_GRID(wid_d->grid), cb, wid_d->pos.y, wid_d->pos.x,
			wid_d->size.x, wid_d->size.y);
	return (cb);
}
