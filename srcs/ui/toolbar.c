/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:30:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/21 21:21:18 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static GtkWidget	*create_item(char *img, char *b_text, char *tooltip)
{
	GtkToolItem		*item;
	GtkWidget		*img;

	if (!(img = gtk_image_new_from_file(img)))
		return (NULL);
	if (!(item = gtk_tool_button_new(img, b_text)))
			return (NULL);
	gtk_tool_item_set_tooltip_text(item, tooltip);
	return (item);
}

int				create_toolbar(t_data *data, GtkWidget *v_box)
{
	GtkWidget		*bar;
	GtkToolItem		*item[3];
	GtkWidget		*img[3];
	int				i;

	if (!(bar = gtk_toolbar_new()))
		return (0);
	if (!(item[0] = create_item("./assets/exit.png", "", "open a file")))
		return (0);
	if (!(item[1] = create_item("./assets/save.png", "", "save work")))
		return (0);
	if (!(item[2] = create_item("./assets/squar.png", "", "export work")))
		return (0);
	i = -1;
	while (++i < 3)
	{
		gtk_tool_item_set_homogeneous(item[i], TRUE);
		gtk_toolbar_insert(GTK_TOOLBAR(bar), item[i], -1);
	}
	gtk_box_pack_start(GTK_BOX(v_box), bar, FALSE, FALSE, 0);
	return (1);
}
