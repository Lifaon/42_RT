/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img_in_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:11:33 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/16 19:44:30 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mygtk.h"

void	fill_img_in_color(GtkWidget *img, uint32_t color)
{
	t_pixelbuf		*pxb;

	pxb = pixelbuf_new_from_img(img);
	fill_pixelbuf_in_color(pxb, color);
	put_pixelbuf_to_widget(pxb, NULL);
	free(pxb);
}

/*
** Here we use free instead of pixelbuf_free because the widget still need 
** the pixbuf.
*/
