/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera_ui.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:00:39 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/27 19:58:26 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

int 			phase_1(t_wid_data *wid_d)
{
	wid_d->f = NULL;
	wid_d->pos = pt_set(1, 0);
	if (!(g_data->ui->sc_fov = make_label_and_scale(wid_d, 
		"Field Of Vision", g_data->cams[0].fov, NULL)))
		return (0);
	wid_d->min_max = ptdb_set(-50000, 50000);
	if (!(g_data->ui->gp_campos = add_vector_choose(wid_d, 
		"position", g_data->cams[0].pos, NULL)))
		return (0);
	return (1);
}

int				create_camera_ui(GtkWidget *tab)
{
	GtkWidget		*l_title;
	GtkWidget		*l_value;
	t_wid_data		wid_d;
	int				i;


	if (!(init_wid_data(&wid_d, 10, ptdb_set(0, 1000))))
		return (0);
	//gtk_notebook_set_scrollable(GTK_NOTEBOOK(g_data->ui->tab_cam), TRUE);
	if (!(l_title = gtk_label_new("Camera")))
		return (0);
	l_new(&wid_d, "Select camera");
	wid_d.pos.y = 2;
	if (!(l_value = l_new(&wid_d, "0")))
		return (0);
	wid_d.pos.y = 1;
	wid_d.f = &change_left_cam;
	if (!(b_new(&wid_d, l_value, "<", NULL)))
		return (0);
	wid_d.pos.y = 3;
	wid_d.f = &change_right_cam;
	if (!(b_new(&wid_d, l_value, ">", NULL)))
		return (0);
	if (!(phase_1(&wid_d)))
		return(0);
	if (gtk_notebook_append_page(GTK_NOTEBOOK(tab), wid_d.grid, l_title) < 0)
		return (0);
	return (1);
}
