/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector_choose.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:48:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/25 21:44:01 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

GtkSizeGroup	*add_vector_choose(t_wid_data *wid_d, char *label, t_vec vec)
{
	GtkSizeGroup	*group;
	t_wid_data		frame_d;
	GtkWidget		*frame;

	if (!(group = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (NULL);
	if (!(frame = gtk_frame_new(label)))
		return (NULL);
	//gtk_widget_set_margin_start(frame, 20);
	init_wid_data(&frame_d, wid_d->step, wid_d->min_max);
	gtk_container_set_border_width(GTK_CONTAINER(frame_d.grid), 10);
//	gtk_grid_set_column_spacing(GTK_GRID(frame_d.grid), 10);
//	gtk_grid_set_row_spacing(GTK_GRID(frame_d.grid), 10);
	frame_d.pos.y = wid_d->pos.y;
	if (make_entry_and_scale(&frame_d, "x", group, vec.x) < 1)
		return (NULL);
	if (make_entry_and_scale(&frame_d, "y", group, vec.y) < 1)
		return (NULL);
	if (make_entry_and_scale(&frame_d, "z", group, vec.z) < 1)
		return (NULL);
	gtk_container_add(GTK_CONTAINER(frame), frame_d.grid);
	gtk_grid_attach(GTK_GRID(wid_d->grid), frame, wid_d->pos.y, wid_d->pos.x,
			2, 7);
	wid_d->pos.x += 7;
	return (group);
}

GtkSizeGroup	*add_color_choose(t_wid_data *wid_d, t_color color)
{
	GtkSizeGroup	*group;

	if (!(group = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (NULL);
	if (make_entry_and_scale(wid_d, "red", group, color.argb.r) < 1)
		return (NULL);
	if (make_entry_and_scale(wid_d, "green", group, color.argb.g) < 1)
		return (NULL);
	if (make_entry_and_scale(wid_d, "blue", group, color.argb.b) < 1)
		return (NULL);
	return (group);
}
