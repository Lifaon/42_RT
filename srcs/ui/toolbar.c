/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:52:46 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/21 09:01:39 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ui.h"

static GtkToolItem	*create_item(char *img_name, char *b_text, char *tooltip)
{
	GtkToolItem		*item;
	GtkWidget		*img;
	char			*str;

	if (!(str = ft_strjoin(g_data->path, "srcs/ui/assets/")))
		return (NULL);
	str = ft_strjoin_free(str, img_name);
	if (!(img = gtk_image_new_from_file(str)))
		return (NULL);
	if (!(item = gtk_tool_button_new(img, b_text)))
		return (NULL);
	gtk_tool_item_set_tooltip_text(item, tooltip);
	ft_strdel(&str);
	return (item);
}

static int			create_all_items(GtkToolItem *item[4])
{
	if (!(item[0] = create_item("folder.png", "open", "open a file")))
		return (0);
	if (!(item[1] = create_item("save2.png", "save", "save work")))
		return (0);
	if (!(item[2] = create_item("squar.png", "export", "export work")))
		return (0);
	if (!(item[3] = create_item("draw.png", "redraw", "redraw")))
		return (0);
	return (1);
}

int					create_toolbar(GtkWidget *v_box, t_ui *ui)
{
	GtkWidget		*bar;
	GtkToolItem		*item[4];
	int				i;
	void			(*f[4])(GtkWidget*, gpointer);

	f[0] = &click_open;
	f[1] = &click_save;
	f[2] = &click_export;
	f[3] = &click_redraw;
	if (!(bar = gtk_toolbar_new()))
		return (0);
	if (!(create_all_items(item)))
		return (0);
	i = -1;
	while (++i < 4)
	{
		g_signal_connect(G_OBJECT(item[i]), "clicked", G_CALLBACK(f[i]), ui);
		gtk_tool_item_set_homogeneous(item[i], TRUE);
		gtk_toolbar_insert(GTK_TOOLBAR(bar), item[i], -1);
	}
	gtk_box_pack_start(GTK_BOX(v_box), bar, FALSE, FALSE, 0);
	return (1);
}
