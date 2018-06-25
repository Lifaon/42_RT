/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wid_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:59:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/25 12:20:13 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ui.h"

int		init_wid_data(t_wid_data *wid_d, double step, t_ptdb min_max)
{
	if (!(wid_d->grid = gtk_grid_new()))
		return (0);
	wid_d->pos = pt_set(0, 0);
	wid_d->size = pt_set(1, 1);
	wid_d->f = NULL;
	wid_d->step = step;
	wid_d->min_max = min_max;
	gtk_grid_set_row_spacing(GTK_GRID(wid_d->grid), 5);
	gtk_grid_set_column_spacing(GTK_GRID(wid_d->grid), 5);
	gtk_grid_set_row_homogeneous(GTK_GRID(wid_d->grid), FALSE);
	gtk_grid_set_column_homogeneous(GTK_GRID(wid_d->grid), FALSE);
	return (1);
}

void	set_wid_data(t_wid_data *wid_d, t_point pos, t_point size,
	void (*f)(GtkWidget*, gpointer))
{
	wid_d->pos = pos;
	wid_d->size = size;
	wid_d->f = f;
}

void	set_wid_data_scale(t_wid_data *wid_d, double step, t_ptdb min_max)
{
	wid_d->step = step;
	wid_d->min_max = min_max;
}
