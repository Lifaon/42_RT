/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_widgets_in_new_win.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:17:02 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/12 19:40:56 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mygtk.h"

void	put_widgets_in_new_win(GtkWidget *wid, gint x, gint y)
{
	GtkWidget	*win;

	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
	if (x > 0 && y > 0)
		gtk_window_set_default_size(GTK_WINDOW(win), x, y);
	if (wid)
		gtk_container_add(GTK_CONTAINER(win), wid);
	gtk_widget_show_all(win);
}
