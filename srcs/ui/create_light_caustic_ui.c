/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light_caustic_ui.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 22:19:17 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 17:51:38 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int		phase_2(t_wid_data *wid_d, GtkSizeGroup *gp, GtkWidget *check)
{
	GtkWidget		*w;

	wid_d->f = change_photon_size;
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	set_wid_data_scale(wid_d, 1, ptdb_set(1, 20));
	if (!(w = make_label_and_scale(wid_d, "photon size",
				(double)g_data->photon_size, gp)))
		return (0);
	gtk_size_group_add_widget(gp, w);
	wid_d->f = &change_photon_intensity;
	wid_d->pos.y += 2;
	set_wid_data_scale(wid_d, 1, ptdb_set(1, 200));
	if (!(w = make_label_and_scale(wid_d, "photon intensity",
				(double)g_data->photon_ppx, gp)))
		return (0);
	gtk_size_group_add_widget(gp, w);
	g_ui->is_active = 1;
	if (!g_data->caustic_flag)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check), FALSE);
	g_ui->is_active = 0;
	return (1);
}

static int		phase_1(t_wid_data *wid_d, GtkSizeGroup *gp)
{
	GtkWidget		*w;
	GtkWidget		*check;

	wid_d->pos.y = 1;
	if (!(w = b_new(wid_d, NULL, "add new light", NULL)))
		return (0);
	wid_d->size.x = 1;
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	wid_d->f = &check_caustic;
	if (!(check = new_check_button(wid_d, "caustic", gp, NULL)))
		return (0);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check), TRUE);
	wid_d->pos.y += 1;
	wid_d->f = change_total_photon;
	set_wid_data_scale(wid_d, 1, ptdb_set(1, 100));
	if (!(w = make_label_and_scale(wid_d, "total photons\n(x5000)",
				(double)g_data->photon_total / 5000, gp)))
		return (0);
	gtk_size_group_add_widget(gp, w);
	return (phase_2(wid_d, gp, check));
}

int				create_light_caustic_ui(GtkWidget *box)
{
	t_wid_data		wid_d;
	GtkSizeGroup	*gp_caustic;

	if (!(gp_caustic = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (0);
	if (!(init_wid_data(&wid_d, 1, ptdb_set(1, 200))))
		return (0);
	wid_d.size.x = 2;
	wid_d.f = &add_one_light;
	if (!(phase_1(&wid_d, gp_caustic)))
		return (0);
	gtk_box_pack_start(GTK_BOX(box), wid_d.grid, FALSE, FALSE, 10);
	return (1);
}
