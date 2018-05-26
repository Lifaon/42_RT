/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:52:46 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/26 18:12:41 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static GtkToolItem	*create_item(char *img_name, char *b_text, char *tooltip, 
 void (*f)(GtkWidget*, gpointer))
{
	GtkToolItem		*item;
	GtkWidget		*img;
	char			*str;

	str = ft_strjoin("./srcs/ui/assets/", img_name);
	if (!(img = gtk_image_new_from_file(str)))
		return (NULL);
	if (!(item = gtk_tool_button_new(img, b_text)))
		return (NULL);
	gtk_tool_item_set_tooltip_text(item, tooltip);
	g_signal_connect(G_OBJECT(item), "clicked", G_CALLBACK(f), (gpointer)g_data);
	ft_strdel(&str);
	return (item);
}

int				create_toolbar(GtkWidget *v_box)
{
	GtkWidget		*bar;
	GtkToolItem		*item[3];
	GtkWidget		*img[3];
	int				i;
	void			(*f[3])(GtkWidget*, gpointer);

	f[0] = &click_open;
	f[1] = &click_save;
	f[2] = &click_export;
	if (!(bar = gtk_toolbar_new()))
		return (0);
	if (!(item[0] = create_item("exit.png", "open", "open a file", f[0])))
		return (0);
	if (!(item[1] = create_item("save.png", "save", "save work", f[1])))
		return (0);
	if (!(item[2] = create_item("squar.png", "export", "export work", f[2])))
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
