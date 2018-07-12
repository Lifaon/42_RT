/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_options_ui.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:57:43 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/12 16:32:25 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int		construct_phase_1(t_wid_data *wid_d)
{
	t_pixelbuf		*pxb;
	char			**txt;

	wid_d->f = &change_px;
	if (!(make_label_and_scale(wid_d, "Pixelisation", (double)g_data->px,
					&g_data->px)))
		return (0);
	wid_d->pos = pt_set(0, 2);
	wid_d->f = &change_aa;
	wid_d->min_max = ptdb_set(1, 16);
	if (!(make_label_and_scale(wid_d, "Anti-aliasing", (double)g_data->aa,
					&g_data->aa)))
		return (0);
	wid_d->pos = pt_set(1, 0);
	if (!(make_label_and_switch(wid_d, "cel shading", FALSE, &switch_cel_shading)))
		return (0);
	wid_d->f = &change_filter;
	wid_d->param = pxb;
	wid_d->pos = pt_set(1, 2);
	txt = ft_strsplit("-- None --\fBlack & white\fSepia", '\f');
	if (!(make_label_and_cb(wid_d, "filters", 0, txt)))
		return (0);
	return (1);
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
