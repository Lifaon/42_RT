/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:56:23 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/13 17:59:12 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	ft_event(t_data *data)
{
	SDL_Thread	*thread;
	SDL_Event	event;
	int			quit;
	char		*str;
	int			ret;

	quit = 0;
	gtk_widget_set_events(g_data->win_gtk, GDK_KEY_PRESS);
	//gtk_widget_add_events(par->win, GDK_MOTION_NOTIFY);
	//gtk_widget_add_events(par->win, GDK_SCROLL);
	g_signal_connect(G_OBJECT(g_data->win_gtk), "key_press_event",
				G_CALLBACK(ft_keyboard), data);
	gtk_main();
	/*g_signal_connect(G_OBJECT(par->win), "motion_notify_event",
				G_CALLBACK(mouse2), param);
	g_signal_connect(G_OBJECT(par->win), "scroll_event",
				G_CALLBACK(wheel), param);*/
	exit_all(data);
}
