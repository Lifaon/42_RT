/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_options2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:23:53 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 11:23:55 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	change_depth_max(GtkWidget *widget, gpointer param)
{
	int			value;

	if (g_ui->is_active == 0 || (!param && !widget))
		return ;
	value = (int)gtk_range_get_value(GTK_RANGE(widget));
	g_data->depth_max = value;
}
