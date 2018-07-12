/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_page.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:33:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/12 16:31:29 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

gboolean	change_page_light(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data)
{
	if (!data)
		data = NULL;
	g_ui->page_light = arg1;
	return (TRUE);
}

gboolean	change_page_cam(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data)
{
	if (!data)
		data = NULL;
	g_ui->page_cam = arg1;
	return (TRUE);
}

gboolean	change_page_obj(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data)
{
	if (!data)
		data = NULL;
	g_ui->page_obj = arg1;
	return (TRUE);
}
