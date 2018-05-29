/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_redraw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:04:02 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/29 20:05:53 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	click_redraw(GtkWidget *widget, gpointer param)
{
	if (!widget && !param)
		param = NULL;
	draw_image(g_data);
}
