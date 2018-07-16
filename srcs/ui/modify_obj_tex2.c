/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_obj_tex2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:21:55 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/16 18:25:28 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void		switch_obj_tex_repeat(GtkWidget *widget, gboolean state,
		gpointer param)
{
	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	if (state == FALSE)
		g_data->objs[g_ui->page_obj].tex_repeat = 0;
	if (state == TRUE)
		g_data->objs[g_ui->page_obj].tex_repeat = 1;
}

void		switch_obj_tex_trans(GtkWidget *widget, gboolean state,
		gpointer param)
{
	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	if (state == FALSE)
		g_data->objs[g_ui->page_obj].tex_trans = 0;
	if (state == TRUE)
		g_data->objs[g_ui->page_obj].tex_trans = 1;
}
