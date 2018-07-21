/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object_texture_ui.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:18:05 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/17 16:57:44 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int		add_checks_buttons(t_wid_data *wid_d, t_obj *obj, 
	GtkSizeGroup *gp_filetex, GtkSizeGroup *gp_check)
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
	wid_d->pos.x++;
	if (!(w = new_check_button(wid_d, "Checkboard", gp_check, gp_check)))
		return (0);
	if (obj->color_type == COLOR_CHECKERBOARD)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(w), TRUE);
	wid_d->f = &check_perlin;
	wid_d->pos.x++;
	if (!(w = new_check_button(wid_d, "Perlin", gp_check, gp_check)))
		return (0);
	//if (obj->perlin == 1)
	//	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(w), TRUE);
	g_ui->is_active = 0;
	return (1);
}

static int		phase_3(t_wid_data *wid_d, t_obj *obj, 
	GtkSizeGroup *gp_filetex, GtkSizeGroup *gp_check)
{
	GtkWidget		*w;

	wid_d->pos = pt_set(4, 2);
	wid_d->f = &change_obj_tex_scale;
	if (!(w = make_label_and_scale(wid_d, "scale",
					(double)obj->tex_scale, NULL)))
		return (0);
	gtk_size_group_add_widget(gp_filetex, w);
	wid_d->pos.x++;
	wid_d->f = &change_obj_tex_pos_x;
	if (!(w = make_label_and_entry(wid_d, "X position", (double)obj->tex_pos.x,
				NULL)))
		return (0);
	gtk_size_group_add_widget(gp_filetex, w);
	wid_d->f = &change_obj_tex_pos_y;
	wid_d->pos.x++;
	if (!(w = make_label_and_entry(wid_d, "Y position", (double)obj->tex_pos.y,
				NULL)))
		return (0);
	gtk_size_group_add_widget(gp_filetex, w);
	wid_d->pos = pt_set(4, 0);
	wid_d->f = &check_tex_file;
	if (!(w = new_check_button(wid_d, "texture from file", gp_filetex, gp_check)))
		return (0);
	if (obj->tex)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(w), TRUE);
	else
		set_group_widget_active(gp_filetex, FALSE);
	return (add_checks_buttons(wid_d, obj, gp_filetex, gp_check));
}

static int		phase_2(t_wid_data *wid_d, t_obj *obj, 
	GtkSizeGroup *gp_filetex, GtkSizeGroup *gp_check)
{
	gboolean		state;
	GtkWidget		*w;

	wid_d->pos = pt_set(5, 0);
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
	return (phase_3(wid_d, obj, gp_filetex, gp_check));
}


static int		phase_1(t_wid_data *wid_d, t_obj *obj, 
	GtkSizeGroup *gp_filetex, GtkSizeGroup *gp_check)
{
	t_pixelbuf		*pxb;
	GtkWidget		*w;

	if (!(pxb = pixelbuf_new(pt_set(30, 30), NULL)))
		return (0);
	fill_pixelbuf_in_color(pxb, obj->color2.c);
	if (!(w = b_new(wid_d, (gpointer)pxb->widget, NULL, pxb->widget)))
		return (0);
	free(pxb);
	gtk_size_group_add_widget(gp_check, w);
	if (!(pxb = pixelbuf_new(pt_set(60, 60), NULL)))
		return (0);
	if (obj->tex)
		scale_pxb(obj->tex, pxb, pxb->size, GDK_INTERP_BILINEAR);
	wid_d->f = &change_obj_tex_file;
	wid_d->pos = pt_set(3, 1);
	if (!(w = b_new(wid_d, (gpointer)pxb->widget, NULL, (GtkWidget*)pxb->widget)))
		return (0);
	wid_d->size.y = 1;
	free(pxb);
	gtk_size_group_add_widget(gp_filetex, w);
	wid_d->pos = pt_set(1, 2);
	wid_d->f = &change_color_scale;
	if (!(w = make_label_and_scale(wid_d, "color scale",
				(double)obj->color_scale, w)))
		return (0);
	gtk_size_group_add_widget(gp_check, w);
	return (phase_2(wid_d, obj, gp_filetex, gp_check));
}

int			create_object_texture_ui(t_wid_data *wid_d, t_obj *obj)
{
	gboolean		is_limited;
	GtkWidget 		*frame;
	t_wid_data		frame_d;
	GtkSizeGroup	*gp_filetex;	
	GtkSizeGroup	*gp_check;

	if (!(frame = gtk_frame_new("Textures")))
		return (0);
	if (!(gp_check = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (0);
	if (!(gp_filetex = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (0);
	init_wid_data(&frame_d, 10, ptdb_set(10, 1000));
	frame_d.pos.y = 1;
	frame_d.size = pt_set(1, 2);
	wid_d->f = &change_obj_color2;
	//gtk_grid_set_row_homogeneous(GTK_GRID(wid_d->grid), TRUE);
	if (!(phase_1(&frame_d, obj, gp_filetex, gp_check)))
		return (0);
	gtk_container_add(GTK_CONTAINER(frame), frame_d.grid);
	gtk_grid_attach(GTK_GRID(wid_d->grid), frame, 0, wid_d->pos.x, 4, 7);
	wid_d->pos.x += 7;
	return (create_limited_object_ui(wid_d, obj));
}
