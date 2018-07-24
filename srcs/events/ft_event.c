/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:56:23 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 16:51:19 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	ft_event(t_data *data)
{
	//gtk_widget_add_events(g_data->img->widget, GDK_KEY_PRESS);
	//g_signal_connect(G_OBJECT(g_data->win), "key_press_event",
	//			G_CALLBACK(ft_keyboard), data);
	gtk_widget_grab_focus(g_ui->ev_box);
	gtk_widget_grab_default(g_ui->ev_box);
	gtk_main();
	exit_all(data);
}
