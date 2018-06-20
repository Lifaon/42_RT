/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object_ui.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:00:25 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/23 18:42:14 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				create_object_ui(GtkWidget *tab)
{
	GtkWidget		*l_title;
	GtkWidget		*en_1;
	GtkWidget		*box;

	l_title = gtk_label_new("Object");
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	en_1 = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(box), en_1, FALSE, FALSE, 0);
	if ((gtk_notebook_append_page(GTK_NOTEBOOK(tab), box, l_title) < 0))
		return (0);
	return (1);
}