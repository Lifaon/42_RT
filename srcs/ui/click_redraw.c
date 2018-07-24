/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_redraw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:04:02 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 21:09:08 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "draw.h"

void	click_redraw(GtkWidget *widget, gpointer param)
{
	if (!widget && !param)
		param = NULL;
	put_gdk_image();
	gtk_widget_grab_focus(g_ui->ev_box);
	gtk_widget_grab_default(g_ui->ev_box);
}
