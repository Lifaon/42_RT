/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object_texture_ui.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:18:05 by fchevrey          #+#    #+#             */
/*   Updated: 2018/08/15 08:10:55 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int		add_bump(t_wid_data *wid_d, t_obj *obj,
	GtkSizeGroup *gp_bump)
{
	GtkWidget		*w;

	wid_d->f = check_bump;
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	if (!(w = new_check_button(wid_d, "Bump\nmapping", gp_bump, NULL)))
		return (0);
	set_wid_data_scale(wid_d, 1, ptdb_set(0, 100));
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	wid_d->f = change_bump_noise;
	if (!(w = make_label_and_scale(wid_d, "noise",
				obj->bump_intensity * 100, w)))
		return (0);
	wid_d->pos.y += 2;
	wid_d->f = change_bump_scale;
	gtk_size_group_add_widget(gp_bump, w);
	wid_d->min_max = ptdb_set(10, 1000);
	if (!(w = make_label_and_scale(wid_d, "bump scale",
				obj->bump_scale, w)))
		return (0);
	gtk_size_group_add_widget(gp_bump, w);
	if (obj->bump_flag)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(w), TRUE);
	else
		set_group_widget_active(gp_bump, FALSE);
	return (1);
}

static int		add_checks_buttons(t_wid_data *wid_d, t_obj *obj,
	GtkSizeGroup *gp_perlin, GtkSizeGroup *gp_check)
{
	t_pixelbuf		*pxb;
	GtkWidget		*w;

	g_ui->is_active = 1;
	wid_d->pos = pt_set(0, 0);
	wid_d->f = &check_rainbow;
	if (!(w = new_check_button(wid_d, "Rainbow", gp_check, gp_check)))
		return (0);
	wid_d->pos.x++;
	if (obj->color_type == COLOR_RAINBOW)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(w), TRUE);
	wid_d->f = &check_checkboard;
	if (!(w = new_check_button(wid_d, "Checkboard", gp_check, gp_check)))
		return (0);
	if (obj->color_type == COLOR_CHECKERBOARD)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(w), TRUE);
	wid_d->f = &check_perlin;
	wid_d->pos.x++;
	if (!(w = new_check_button(wid_d, "Perlin", gp_perlin, gp_check)))
		return (0);
	g_ui->is_active = 0;
	if (obj->perl_type != PERLIN_NONE)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(w), TRUE);
	else
		set_group_widget_active(gp_perlin, FALSE);
	return (1);
}

static int		phase_2(t_wid_data *wid_d, t_obj *obj,
	GtkSizeGroup *gp_perlin, GtkSizeGroup *gp_check)
{
	GtkWidget		*w;
	t_point			pos;
	GtkSizeGroup	*gp_bump;

	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	wid_d->f = &change_perlin_scale;
	if (!(w = make_label_and_scale(wid_d, "perlin scale",
				(double)obj->perl_scale, w)))
		return (0);
	gtk_size_group_add_widget(gp_perlin, w);
	wid_d->f = &change_perlin_opacity;
	wid_d->pos.y += 2;
	set_wid_data_scale(wid_d, 0.05, ptdb_set(0.0, 1.0));
	if (!(w = make_label_and_scale(wid_d, "perlin opacity",
				obj->perl_opacity, w)))
		return (0);
	gtk_size_group_add_widget(gp_perlin, w);
	wid_d->pos.y = 0;
	pos = wid_d->pos;
	if (!(add_checks_buttons(wid_d, obj, gp_perlin, gp_check)))
		return (0);
	wid_d->pos = pos;
	if (!(gp_bump = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (0);
	return (add_bump(wid_d, obj, gp_bump));
}

static int		phase_1(t_wid_data *wid_d, t_obj *obj,
	GtkSizeGroup *gp_perlin, GtkSizeGroup *gp_check)
{
	t_pixelbuf		*pxb;
	GtkWidget		*w;

	if (!(pxb = pixelbuf_new(pt_set(30, 30), NULL)))
		return (0);
	fill_pixelbuf_in_color(pxb, obj->color2.c);
	wid_d->f = &change_obj_color2;
	if (!(w = b_new(wid_d, (gpointer)pxb->widget, NULL, pxb->widget)))
		return (0);
	gtk_widget_set_sensitive(w, FALSE);
	free(pxb);
	wid_d->size.y = 1;
	gtk_size_group_add_widget(gp_check, w);
	wid_d->pos = pt_set(1, 2);
	wid_d->f = &change_color_scale;
	if (!(w = make_label_and_scale(wid_d, "color scale",
				(double)obj->color_scale, w)))
		return (0);
	gtk_widget_set_sensitive(w, FALSE);
	gtk_size_group_add_widget(gp_check, w);
	wid_d->pos = pt_set(2, 2);
	wid_d->f = &check_perlin_cosine;
	wid_d->pos.y = 1;
	if (!(w = new_check_button(wid_d, "Cosine", gp_perlin, gp_perlin)))
		return (0);
	gtk_size_group_add_widget(gp_perlin, w);
	return (phase_2(wid_d, obj, gp_perlin, gp_check));
}

int			create_object_texture_ui(t_wid_data *wid_d, t_obj *obj)
{
	gboolean		is_limited;
	GtkWidget 		*frame;
	t_wid_data		frame_d;
	GtkSizeGroup	*gp_perlin;
	GtkSizeGroup	*gp_check;

	if (!(frame = gtk_frame_new("Textures")))
		return (0);
	if (!(gp_check = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (0);
	if (!(gp_perlin = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (0);
	init_wid_data(&frame_d, 10, ptdb_set(10, 1000));
	frame_d.pos = pt_set(0, 1);
	frame_d.size = pt_set(1, 2);
	//gtk_grid_set_row_homogeneous(GTK_GRID(wid_d->grid), TRUE);
	if (!(phase_1(&frame_d, obj, gp_perlin, gp_check)))
		return (0);
	if (!(create_object_file_tex_ui(&frame_d, obj)))
		return (0);
	gtk_container_add(GTK_CONTAINER(frame), frame_d.grid);
	gtk_grid_attach(GTK_GRID(wid_d->grid), frame, 0, wid_d->pos.x, 4, 7);
	wid_d->pos.x += 7;
	return (create_limited_object_ui(wid_d, obj));
}
