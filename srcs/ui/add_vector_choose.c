/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector_choose.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:48:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 19:41:19 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

GtkSizeGroup	*add_vector_choose(t_wid_data *w_d, char *label, t_vec vec)
{
	GtkSizeGroup	*group;
	t_wid_data		frame_d;
	GtkWidget		*frame;

	if (!(group = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (NULL);
	if (!(frame = gtk_frame_new(label)))
		return (NULL);
	init_wid_data(&frame_d, w_d->step, w_d->min_max);
	frame_d.f = w_d->f;
	gtk_container_set_border_width(GTK_CONTAINER(frame_d.grid), 10);
	frame_d.pos.y = w_d->pos.y;
	if (make_entry_and_scale(&frame_d, "x", group, vec.x) < 1)
		return (NULL);
	if (make_entry_and_scale(&frame_d, "y", group, vec.y) < 1)
		return (NULL);
	if (make_entry_and_scale(&frame_d, "z", group, vec.z) < 1)
		return (NULL);
	gtk_container_add(GTK_CONTAINER(frame), frame_d.grid);
	gtk_grid_attach(GTK_GRID(w_d->grid), frame, w_d->pos.y, w_d->pos.x, 2, 7);
	w_d->pos.x += 7;
	return (group);
}

GtkWidget	*make_label_and_entry_group(t_wid_data *wid_d, const char *txt,
			gdouble value, GtkSizeGroup *group)
{
	GtkWidget	*entry;

	if (!(entry = make_label_and_entry(wid_d, txt, value, (gpointer)group)))
		return (NULL);
	wid_d->pos.x += 1;
	gtk_size_group_add_widget(group, entry);
	return (entry);

}

GtkSizeGroup	*add_vector_choose_no_scale(t_wid_data *w_d, char *label,
		t_vec vec)
{
	GtkSizeGroup	*group;
	t_wid_data		frame_d;
	GtkWidget		*frame;

	if (!(group = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (NULL);
	if (!(frame = gtk_frame_new(label)))
		return (NULL);
	init_wid_data(&frame_d, w_d->step, w_d->min_max);
	frame_d.entry_f = w_d->entry_f;
	gtk_container_set_border_width(GTK_CONTAINER(frame_d.grid), 10);
	frame_d.pos.y = w_d->pos.y;
	if (!(make_label_and_entry_group(&frame_d, "x", vec.x, group)))
		return (NULL);
	if (!(make_label_and_entry_group(&frame_d, "y", vec.y, group)))
		return (NULL);
	if (!(make_label_and_entry_group(&frame_d, "z", vec.z, group)))
		return (NULL);
	gtk_container_add(GTK_CONTAINER(frame), frame_d.grid);
	gtk_grid_attach(GTK_GRID(w_d->grid), frame, w_d->pos.y, w_d->pos.x, 2, 7);
	w_d->pos.x += 4;
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
