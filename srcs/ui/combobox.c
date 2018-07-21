/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combobox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:48:28 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/21 09:04:23 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int		get_cb_limit_value_from_obj(t_obj *obj)
{
	if (obj->tex_limit == 1)
		return (0);
	if (obj->limited == LIMIT_AXE || obj->limited == LIMIT_NONE)
		return (1);
	if (obj->obj_type == PLANE && obj->limited == LIMIT_CIRCLE)
		return (3);
	return (2);
}

GtkWidget		*make_label_and_cb(t_wid_data *wid_d, char *label,
		int set_value, char **txt)
{
	GtkWidget		*cb;
	char			*str;
	int				i;
	if (label)
		if (!(l_new(wid_d, label)))
			return (NULL);
	if (!(cb = gtk_combo_box_text_new()))
		return (NULL);
	gtk_combo_box_set_id_column(GTK_COMBO_BOX(cb), 0);
	i = -1;
	while (txt[++i])
		gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, txt[i]);
	if (set_value < i)
		gtk_combo_box_set_active(GTK_COMBO_BOX(cb), set_value);
	while (--i >= 0)
		ft_strdel(&txt[i]);
	free(txt);
	if (wid_d->f)
		g_signal_connect(G_OBJECT(cb), "changed", G_CALLBACK(wid_d->f),
				wid_d->param);
	if (label)
		wid_d->pos.y += 1;
	gtk_grid_attach(GTK_GRID(wid_d->grid), cb, wid_d->pos.y, wid_d->pos.x,
			wid_d->size.x, wid_d->size.y);
	return (cb);
}

GtkWidget		*new_cb_limited(t_wid_data *wid_d, gpointer param, t_obj *obj)
{
	GtkWidget		*cb;
	int				id;

	if (!(cb = gtk_combo_box_text_new()))
		return (NULL);
	gtk_combo_box_set_id_column(GTK_COMBO_BOX(cb), 0);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "define by texture");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "principal axe");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "revolution axe");
	if (obj->obj_type == PLANE)
		gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "circle");
	gtk_combo_box_set_active(GTK_COMBO_BOX(cb), 1);
	id = get_cb_limit_value_from_obj(obj);
	gtk_combo_box_set_active(GTK_COMBO_BOX(cb), id);
	if (wid_d->f)
		g_signal_connect(G_OBJECT(cb), "changed", G_CALLBACK(wid_d->f), param);
	gtk_grid_attach(GTK_GRID(wid_d->grid), cb, wid_d->pos.y, wid_d->pos.x,
			2, 1);
	return (cb);
}

GtkWidget		*new_cb_type(t_wid_data *wid_d, gpointer param, t_obj *obj)
{
	GtkWidget		*cb;
	char			*str;

	if (!(l_new(wid_d, "Type")))
		return (NULL);
	if (!(cb = gtk_combo_box_text_new()))
		return (NULL);
	gtk_combo_box_set_id_column(GTK_COMBO_BOX(cb), 0);
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "sphere");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "plane");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "cone");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb), NULL, "cylinder");
	gtk_combo_box_set_active(GTK_COMBO_BOX(cb), 1);
	str = get_str_obj_type(obj->obj_type);
	gtk_combo_box_set_active_id(GTK_COMBO_BOX(cb), str);
	ft_strdel(&str);
	if (wid_d->f)
		g_signal_connect(G_OBJECT(cb), "changed", G_CALLBACK(wid_d->f), param);
	wid_d->pos.y += 1;
	gtk_grid_attach(GTK_GRID(wid_d->grid), cb, wid_d->pos.y, wid_d->pos.x,
			wid_d->size.x, wid_d->size.y);
	return (cb);
}
