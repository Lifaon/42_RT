/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_redraw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:04:02 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/24 19:33:34 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "draw.h"

void	click_redraw(GtkWidget *widget, gpointer param)
{
	if (!widget && !param)
		param = NULL;
	ft_putstr("click_redraw\n");
	g_data->draw = 1;
	put_gdk_image();
	//gtk_widget_grab_focus(g_data->img->widget);
	gtk_widget_grab_focus(g_data->ui->ev_box);
	gtk_widget_grab_default(g_data->ui->ev_box);
	//gtk_widget_set_focus_on_click(g_data->img->widget, TRUE);
	//gtk_widget_set_focus_on_click(g_data->img->widget, TRUE);
}
