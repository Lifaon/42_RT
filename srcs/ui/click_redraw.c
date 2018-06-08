/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_redraw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:04:02 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/30 13:11:07 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	click_redraw(GtkWidget *widget, gpointer param)
{
	if (!widget && !param)
		param = NULL;
	ft_putstr("click_redraw\n");
	draw_image(g_data);
}
