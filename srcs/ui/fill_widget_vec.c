/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_widget_vec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:23:08 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/30 20:02:31 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		fill_widget_vec(t_widget_vec *dst, GtkSizeGroup *group, t_vec *vec)
{
	if (group != NULL)
		dst->group = group;
	else
		if (!(dst->group = gtk_size_group_new(GTK_SIZE_GROUP_NONE)))
			return (0);
	if (!vec)
		return (0);
	dst->vec = vec;
	return (1);
}
