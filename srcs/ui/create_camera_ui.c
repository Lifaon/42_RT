/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera_ui.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:00:39 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 21:39:48 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int		phase_2(t_wid_data *wid_d)
{
	int		x;

	wid_d->f = change_cam_fov;
	wid_d->pos = pt_set(1, 0);
	if (!(g_ui->sc_fov = make_label_and_scale(wid_d,
		"Field Of Vision", g_data->cams[0].fov, NULL)))
		return (0);
	wid_d->f = change_cam_pos;
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	x = wid_d->pos.x;
	wid_d->min_max = ptdb_set(-50000, 50000);
	if (!(g_ui->gp_cam_pos = add_vector_choose(wid_d,
		"position", g_data->cams[0].pos)))
		return (0);
	wid_d->pos = pt_set(x, 2);
	wid_d->min_max = ptdb_set(-180, 180);
	wid_d->f = change_cam_angle;
	if (!(g_ui->gp_cam_angle = add_vector_choose(wid_d,
		"angle", g_data->cams[0].angle)))
		return (0);
	return (1);
}

static int		phase_1(t_wid_data *wid_d)
{
	GtkWidget		*l_value;

	l_new(wid_d, "Select camera");
	wid_d->pos.y = 2;
	if (!(l_value = l_new(wid_d, "1")))
		return (0);
	wid_d->pos.y = 1;
	wid_d->f = &change_left_cam;
	if (!(b_new(wid_d, l_value, "<", NULL)))
		return (0);
	wid_d->pos.y = 3;
	wid_d->f = &change_right_cam;
	if (!(b_new(wid_d, l_value, ">", NULL)))
		return (0);
	return (phase_2(wid_d));
}

int				create_camera_ui(GtkWidget *tab)
{
	GtkWidget		*l_title;
	t_wid_data		wid_d;

	if (!(init_wid_data(&wid_d, 10, ptdb_set(1, 180))))
		return (0);
	if (!(l_title = gtk_label_new("Camera")))
		return (0);
	if (!(phase_1(&wid_d)))
		return (0);
	if (gtk_notebook_append_page(GTK_NOTEBOOK(tab), wid_d.grid, l_title) < 0)
		return (0);
	return (1);
}
