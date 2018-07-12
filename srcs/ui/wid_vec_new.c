/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wid_vec_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 18:38:19 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/12 16:31:20 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ui.h"

t_widget_vec	*wid_vec_new(GtkSizeGroup *group, t_vec *vec)
{
	t_widget_vec	*wid_vec;
	t_list			*chain;

	if (!vec)
		return (NULL);
	wid_vec = (t_widget_vec*)malloc(sizeof(t_widget_vec));
	if (!group)
		wid_vec->group = gtk_size_group_new(GTK_SIZE_GROUP_NONE);
	else
		wid_vec->group = group;
	wid_vec->vec = vec;
	chain = ft_lstnew(wid_vec, 0);
	if (!g_ui->to_free)
		g_ui->to_free = chain;
	else
		ft_lstadd(&g_ui->to_free, chain);
	return (wid_vec);
}
