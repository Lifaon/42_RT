/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:57:12 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/13 18:37:20 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mygtk.h"

t_pixelbuf		*pixelbuf_new(t_point size, GtkWidget *image)
{
	t_pixelbuf	*pxbuf;

	ft_putstr("ppouuuuuuuuic\n");
	ft_putnbr(size.x);
	ft_putstr(" y = \n");
	ft_putnbr(size.y);
	if (!(pxbuf = (t_pixelbuf*)malloc(sizeof(t_pixelbuf))))
		return (NULL);
	ft_putstr("\nbla\n");
	pxbuf->size = size;
	if (!(pxbuf->buf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, size.x,
					size.y)))
		return (NULL);
	ft_putstr("menfin\n");
	pxbuf->pxl = (uint32_t*)gdk_pixbuf_get_pixels(pxbuf->buf);
	if (!image)
	{
		ft_putstr("what's wrong\n");
		if (!(pxbuf->widget = gtk_image_new_from_pixbuf(pxbuf->buf)))
			return (NULL);
		ft_putchar('n');
		ft_putstr("s pourquouuuaaaaaaan\n");
	}
	else
		pxbuf->widget = image;
	return (pxbuf);
}
