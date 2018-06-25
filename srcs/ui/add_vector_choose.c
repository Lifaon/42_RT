/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector_choose.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:48:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/25 12:54:50 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

GtkSizeGroup	*add_vector_choose(t_wid_data *wid_d, char *label, t_vec vec)
{
	char			*str;
	//char			s[3];
	GtkSizeGroup	*group;
	t_wid_data		fram_d;
	GtkWidget		*frame;

	if (!(group = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (NULL);
	frame = gtk_frame_new(label);
	//ft_strcpy(s, "x ");
	init_wid_data(&frame_d, wid_d->step, wid_d->min_max);
	/*	while (s[0] <= 'z')
	{*/
	//	str = ft_strjoin(s, label);
	//	if (s[0] == 'x')
			if (make_entry_and_scale(wid_d, "x", group, vec.x) < 1)
				return (NULL);
	//	if (s[0] == 'y')
			if (make_entry_and_scale(wid_d, "y", group, vec.y) < 1)
				return (NULL);
	//	if (s[0] == 'z')
			if (make_entry_and_scale(wid_d, "z", group, vec.z) < 1)
				return (NULL);
	gtk_container_add(GTK_CONTAINER(frame), fram_d.grid);
	//	ft_strdel(&str);
	//	s[0] = s[0] + 1;
//	}
	return (group);
}

GtkSizeGroup	*add_color_choose(t_wid_data *wid_d, t_color color)
{
	GtkSizeGroup	*group;

	if (!(group = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
		return (NULL);
	if (make_entry_and_scale(wid_d, "red", group, color.argb.r) < 1)
		return (NULL);
	if (make_entry_and_scale(wid_d, "green", group, color.argb.g) < 1)
		return (NULL);
	if (make_entry_and_scale(wid_d, "blue", group, color.argb.b) < 1)
		return (NULL);
	return (group);
}
