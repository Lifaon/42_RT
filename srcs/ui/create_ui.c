/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:30:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/21 20:58:40 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		create_ui(t_data *data)
{
	GtkWidget		*win;
	GtkWidget		*v_box;

	if (!(win = gtk_window_new(GTK_WINDOW_TOPLEVEL))
			return (0);
	gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(win), 200, 200);
	v_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	if (!(create_toolbar(data, v_box)))
		return (0);
	//if (!(create_light_ui(data, v_box)))
	//	return(0);
	//if (!(create_cam_ui(data, v_box)))
	//	return(0);
	//if(!(create_obj_ui(data, v_box)))
	//	return(0);
	gtk_container_add(GTK_CONTAINER(main_win), v_box);
	gtk_widget_show_all(win);
	g_signal_connect(G_OBJECT(win), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	return (1);
}
