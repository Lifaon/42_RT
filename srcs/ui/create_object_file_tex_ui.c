/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object_file_tex_ui.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 21:40:43 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 19:03:15 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int		phase_3(t_wid_data *wid_d, t_obj *obj,
	GtkSizeGroup *gp_filetex)
{
	GtkWidget		*w;

	wid_d->pos.x++;
	wid_d->entry_f = &change_obj_tex_pos_x;
	if (!(w = make_label_and_entry(wid_d, "X position", (double)obj->tex_pos.x,
				NULL)))
		return (0);
	gtk_size_group_add_widget(gp_filetex, w);
	wid_d->entry_f = &change_obj_tex_pos_y;
	wid_d->pos.x++;
	if (!(w = make_label_and_entry(wid_d, "Y position", (double)obj->tex_pos.y,
				NULL)))
		return (0);
	gtk_size_group_add_widget(gp_filetex, w);
	wid_d->pos = pt_set(6, 0);
	wid_d->f = &check_tex_file;
	if (!(w = new_check_button(wid_d, "texture from\nfile", gp_filetex, NULL)))
		return (0);
	if (obj->tex)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(w), TRUE);
	else
		set_group_widget_active(gp_filetex, FALSE);
	return (1);
}

static int		phase_2(t_wid_data *wid_d, t_obj *obj,
	GtkSizeGroup *gp_filetex)
{
	gboolean		state;
	GtkWidget		*w;

	wid_d->pos = pt_set(8, 0);
	state = (obj->tex_repeat == 1) ? TRUE : FALSE;
	if (!(w = make_label_and_switch(wid_d, "repeat", state,
					&switch_obj_tex_repeat)))
		return (0);
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	gtk_size_group_add_widget(gp_filetex, w);
	state = (obj->tex_trans == 1) ? TRUE : FALSE;
	if (!(w = make_label_and_switch(wid_d,
			"transparency define\nby the texture", state,
			&switch_obj_tex_trans)))
		return (0);
	gtk_size_group_add_widget(gp_filetex, w);
	wid_d->pos = pt_set(6, 2);
	wid_d->f = &change_obj_tex_scale;
	set_wid_data_scale(wid_d, 10, ptdb_set(10, 1000));
	if (!(w = make_label_and_scale(wid_d, "scale",
					(double)obj->tex_scale, NULL)))
		return (0);
	gtk_size_group_add_widget(gp_filetex, w);
	return (phase_3(wid_d, obj, gp_filetex));
}

int				create_object_file_tex_ui(t_wid_data *wid_d, t_obj *obj)
{
	t_pixelbuf		*pxb;
	GtkWidget		*w;
	GtkSizeGroup	*gp_filetex;

	if (!(gp_filetex = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (0);
	if (!(pxb = pixelbuf_new(pt_set(60, 60), NULL)))
		return (0);
	if (obj->tex)
		scale_pxb(obj->tex, pxb, pxb->size, GDK_INTERP_BILINEAR);
	wid_d->f = &change_obj_tex_file;
	wid_d->size.y = 2;
	wid_d->pos = pt_set(6, 1);
	if (!(w = b_new(wid_d, (gpointer)pxb->widget, NULL,
					(GtkWidget*)pxb->widget)))
		return (0);
	wid_d->size.y = 1;
	free(pxb);
	gtk_size_group_add_widget(gp_filetex, w);
	return (phase_2(wid_d, obj, gp_filetex));
}
