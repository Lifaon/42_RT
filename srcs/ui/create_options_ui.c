/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_options_ui.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:57:43 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 22:42:30 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int		construct_phase_2(t_wid_data *wid_d)
{
	gboolean	state;

	wid_d->param = NULL;
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	wid_d->f = &change_depth_max;
	if (!(make_label_and_scale(wid_d, "max number\nof reflexion",
			(double)g_data->depth_max, &g_data->depth_max)))
		return (0);
	set_wid_data_scale(wid_d, 0.1, ptdb_set(0.1, 3));
	wid_d->f = &change_dof_coeff;
	wid_d->pos = pt_set(wid_d->pos.x + 1, 0);
	if (!(make_label_and_scale(wid_d, "Depth of field \nintensity",
			(double)g_data->dof_coeff, &g_data->dof_coeff)))
		return (0);
	state = (g_data->cel_shading == 1) ? TRUE : FALSE;
	wid_d->pos = pt_set(1, 0);
	if (!(make_label_and_switch(wid_d, "cel shading", state,
					&switch_cel_shading)))
		return (0);
	wid_d->pos = pt_set(0, 2);
	wid_d->f = &change_aa;
	wid_d->min_max = ptdb_set(1, 16);
	if (!(make_label_and_scale(wid_d, "Anti-aliasing", (double)g_data->aa,
					&g_data->aa)))
		return (0);
	return (1);
}

static int		construct_phase_1(t_wid_data *wid_d)
{
	char			**txt;
	GtkWidget		*scale;

	wid_d->f = &change_px;
	if (!(make_label_and_scale(wid_d, "Pixelisation", (double)g_data->px,
					&g_data->px)))
		return (0);
	wid_d->pos = pt_set(2, 2);
	wid_d->f = &change_stereo_scale;
	set_wid_data_scale(wid_d, 1, ptdb_set(1, 100));
	if (!(scale = make_label_and_scale(wid_d, "stereoscopy scale",
			(double)g_data->stereo_scale, &g_data->depth_max)))
		return (0);
	if (g_data->filter != FILTER_STEREO)
		gtk_widget_set_sensitive(scale, FALSE);
	wid_d->f = &change_filter;
	wid_d->param = (gpointer)scale;
	wid_d->pos = pt_set(1, 2);
	txt = ft_strsplit("-- None --\fBlack & white\fSepia\fstereoscopy", '\f');
	if (!(make_label_and_cb(wid_d, "filters", g_data->filter, txt)))
		return (0);
	return (construct_phase_2(wid_d));
}

int				create_options_ui(GtkWidget *tab)
{
	t_wid_data		wid_d;
	GtkWidget		*l_title;

	if (!(init_wid_data(&wid_d, 1, ptdb_set(0, 5))))
		return (0);
	set_wid_data_scale(&wid_d, 1, ptdb_set(0, 5));
	if (!(construct_phase_1(&wid_d)))
		return (0);
	l_title = gtk_label_new("Options");
	if ((gtk_notebook_append_page(GTK_NOTEBOOK(tab), wid_d.grid, l_title) < 0))
		return (0);
	return (1);
}
