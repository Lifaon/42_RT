/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_page.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:33:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/20 20:13:27 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

gboolean	change_page_light(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data)
{
	if (!data)
		data = NULL;
	g_data->ui->page_light = arg1;
	return (TRUE);
}
