/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object_texture_ui.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:18:05 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/17 13:59:32 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int	phase_3(t_wid_data *wid_d, t_obj *obj, GtkWidget *cb,
		gpointer button)
{
	GtkWidget		*w;

	wid_d->pos = pt_set(wid_d->pos.x - 2, 2);
	wid_d->f = &change_obj_tex_pos_x;
	if (!(w = make_label_and_entry(wid_d, "X position", (double)obj->tex_pos.x,
					NULL)))
		return (0);
	gtk_size_group_add_widget(g_ui->gp_obj_tex, w);
	wid_d->f = &change_obj_tex_pos_y;
	if (!(w = make_label_and_entry(wid_d, "Y position", (double)obj->tex_pos.y,
					NULL)))
		return (0);
	gtk_size_group_add_widget(g_ui->gp_obj_tex, w);
	g_ui->is_active = 1;
	change_obj_tex(cb, button);
	g_ui->is_active = 0;
	return (1);
}

static int	phase_2(t_wid_data *wid_d, t_obj *obj, GtkWidget *cb,
		gpointer button)
{
	gboolean		repeat;
	gboolean		tex_trans;
	GtkWidget		*w;

	wid_d->f = &change_obj_tex_scale;
	set_wid_data_scale(wid_d, 10, ptdb_set(10, 1000));
	if (!(w = make_label_and_scale(wid_d, "scale",
					(double)obj->tex_scale, NULL)))
		return (0);
	wid_d->pos.y = 0;
	gtk_size_group_add_widget(g_ui->gp_obj_tex, w);
	repeat = (obj->tex_repeat == 1) ? TRUE : FALSE;
	if (!(w = make_label_and_switch(wid_d, "repeat", repeat,
					&switch_obj_tex_repeat)))
		return (0);
	gtk_size_group_add_widget(g_ui->gp_obj_tex, w);
	tex_trans = (obj->tex_trans == 1) ? TRUE : FALSE;
	if (!(w = make_label_and_switch(wid_d,
			"transparency define\nby the texture", tex_trans,
			&switch_obj_tex_trans)))
		return (0);
	gtk_size_group_add_widget(g_ui->gp_obj_tex, w);
	return (phase_3(wid_d, obj, cb, button));
}

int			get_cb_tex_value(t_obj *obj)
{
	if (obj->tex)
		return (3);
	return (0);
}

static int	phase_1(t_wid_data *wid_d, t_obj *obj)
{
	t_pixelbuf		*pxb;
	char			**txt;
	int				tex_value;
	GtkWidget		*w;

	tex_value = get_cb_tex_value(obj);
	if (!(pxb = pixelbuf_new(pt_set(60, 60), NULL)))
		return (0);
	if (obj->tex)
		scale_pxb(obj->tex, pxb, pxb->size, GDK_INTERP_BILINEAR);
	if (!(w = b_new(wid_d, (gpointer)pxb->widget, NULL, (GtkWidget*)pxb->widget)))
		return (0);
	gtk_size_group_add_widget(g_ui->gp_obj_tex, w);
	txt = ft_strsplit("-- None --\fcheckboar\frainbow\ffrom file ->", '\f');
	wid_d->f = &change_obj_tex;
	wid_d->param = (gpointer)w;
	wid_d->size = pt_set(1, 1);
	wid_d->pos.y = 0;
	if (!(w = make_label_and_cb(wid_d, NULL, tex_value, txt)))
		return (0);
	wid_d->pos = pt_set(wid_d->pos.x + 1, 2);
	return (phase_2(wid_d, obj, w, wid_d->param));
	return (1);
}

int		create_object_texture_ui(t_wid_data *wid_d, t_obj *obj)
{
	gboolean		is_limited;
	GtkWidget 		*frame;
	t_wid_data		frame_d;
	t_point			crd;
	GtkWidget 		*sw;

	if (!(frame = gtk_frame_new("Textures")))
		return (0);
	init_wid_data(&frame_d, wid_d->step, wid_d->min_max);
	frame_d.pos.y = 1;
	frame_d.size = pt_set(1, 2);
	frame_d.f = &change_obj_tex_file;
	if (!(phase_1(&frame_d, obj)))
		return (0);
	gtk_container_add(GTK_CONTAINER(frame), frame_d.grid);
	gtk_grid_attach(GTK_GRID(wid_d->grid), frame, 0, wid_d->pos.x, 4, 7);
	wid_d->pos.x += 7;
	return (create_limited_object_ui(wid_d, obj));
}
