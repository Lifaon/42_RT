/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_entry_and_scale.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:02:47 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/16 19:15:24 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ui.h"

static GtkWidget		*make_entry(t_wid_data *wid_d, GtkSizeGroup *group,
		gdouble value)
{
	void		(*f_swap)(GtkWidget*, GdkEvent *event, gpointer);
	char		*str;
	GtkWidget	*entry;

	f_swap = wid_d->entry_f;
	wid_d->pos.y += 1;
	wid_d->entry_f = NULL;
	if (value == INFINITY)
		str = ft_strdup("inf");
	else if (value == -INFINITY)
		str = ft_strdup("-inf");
	else
		str = ft_dbtoa(value);
	if (!(entry = entry_new(wid_d, NULL, str)))
		return (NULL);
	ft_strdel(&str);
	gtk_size_group_add_widget(group, entry);
	wid_d->entry_f = f_swap;
	return (entry);
}

int					make_entry_and_scale(t_wid_data *wid_d, const char *txt,
			GtkSizeGroup *group, gdouble value)
{
	GtkWidget	*entry;
	GtkWidget	*scale;
	int			y;

	if (!(l_new(wid_d, txt)))
		return (0);
	y = wid_d->pos.y;
	if (!(entry = make_entry(wid_d, group, value)))
		return (0);
	gtk_entry_set_max_length(GTK_ENTRY(entry), 11);
	gtk_entry_set_width_chars(GTK_ENTRY(entry), 10);
	wid_d->pos = pt_set(wid_d->pos.x + 1, y);
	wid_d->size = pt_set(2, 1);
	if (!(scale = scale_new(wid_d, (void*)group, value)))
		return (0);
	gtk_size_group_add_widget(group, scale);
	g_signal_connect_after(G_OBJECT(entry), "focus-out-event",
			G_CALLBACK(entry_change_scale), (gpointer)scale);
	wid_d->size = pt_set(1, 1);
	wid_d->pos = pt_set(wid_d->pos.x + 1, y);
	return (1);
}

GtkWidget			*make_label_and_entry(t_wid_data *wid_d, const char *txt,
			gdouble value, gpointer param)
{
	GtkWidget	*entry;
	char		*str;

	check_ui_active(0);
	if (!(l_new(wid_d, txt)))
		return (NULL);
	wid_d->pos.y += 1;
	if (value == INFINITY)
		str = ft_strdup("inf");
	else if (value == -INFINITY)
		str = ft_strdup("-inf");
	else
		str = ft_dbtoa(value);
	if (!(entry = entry_new(wid_d, param, str)))
		return (NULL);
	gtk_entry_set_width_chars(GTK_ENTRY(entry), 10);
	ft_strdel(&str);
	return (entry);
}

GtkWidget			*make_label_and_scale(t_wid_data *wid_d, const char *txt,
			gdouble value, gpointer param)
{
	GtkWidget	*scale;

	if (!(l_new(wid_d, txt)))
		return (NULL);
	wid_d->pos.y += 1;
	if (!(scale = scale_new(wid_d, param, value)))
		return (0);
	return (scale);
}

GtkWidget			*make_label_and_switch(t_wid_data *wid_d, const char *txt,
			gboolean value, void (*f)(GtkWidget*, gboolean, gpointer))
{
	GtkWidget 	*sw;

	if (!(l_new(wid_d, txt)))
		return (NULL);
	wid_d->pos.y += 1;
	if (!(sw = switch_new(wid_d, wid_d, value, f)))
		return (NULL);
	return (sw);
}
