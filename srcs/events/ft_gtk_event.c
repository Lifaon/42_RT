/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gtk_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:27:24 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 16:56:15 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

gboolean			mouse2(GtkWidget *widget,
							GdkEventMotion *event, gpointer param)
{
	t_param			*par;
	GdkEventKey		key_event;

	key_event.keyval = 2;
	if (!widget && !event && !param)
		param = NULL;
	par = (t_param*)param;
	if (par->lock == 0)
	{
		par->mouse.x = event->x;
		par->mouse.y = event->y;
		if (par->fractal == JULIA)
			keyboard(widget, &key_event, param);
	}
	return (0);
}

gboolean			wheel(GtkWidget *widget,
							GdkEventScroll *event, gpointer param)
{
	if (!widget && !event && !param)
		param = NULL;
	ft_putstr("mouse wheel\n");
	return (0);
}

void				ft_event(void *param)
{
	int				quit;
	t_param			*par;

	par = (t_param*)param;
	quit = 0;
	g_signal_connect(G_OBJECT(par->win), "delete-event",
				G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_set_events(par->win, GDK_KEY_PRESS);
	gtk_widget_add_events(par->win, GDK_MOTION_NOTIFY);
	gtk_widget_add_events(par->win, GDK_SCROLL);
	g_signal_connect(G_OBJECT(par->win), "key_press_event",
				G_CALLBACK(keyboard), param);
	g_signal_connect(G_OBJECT(par->win), "motion_notify_event",
				G_CALLBACK(mouse2), param);
	g_signal_connect(G_OBJECT(par->win), "scroll_event",
				G_CALLBACK(wheel), param);
	gtk_main();
	ft_exit(&par);
}
