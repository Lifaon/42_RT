/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera_ui.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:00:39 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/27 18:49:39 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

int				create_camera_ui(GtkWidget *tab)
{
	GtkWidget		*l_title;
	GtkWidget		*en_1;
	GtkWidget		*box;
	t_pixelbuf		*pxb;
	GtkWidget		*img;

	l_title = gtk_label_new("Camera");
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	en_1 = gtk_entry_new();
	img = gtk_image_new_from_file("./srcs/ui/assets/exit.png");
	pxb = pixelbuf_new_from_img(img);
	fill_pixelbuf_in_color(pxb, get_color_gtk(255, 255, 0, 0));
	gtk_box_pack_start(GTK_BOX(box), img, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), en_1, FALSE, FALSE, 0);
	if ((gtk_notebook_append_page(GTK_NOTEBOOK(tab), box, l_title) < 0))
		return (0);
	return (1);
}
