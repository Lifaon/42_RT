/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:43:21 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/26 19:55:45 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static uint32_t		*change_sdl_to_gtk(uint32_t *gtk, uint32_t *sdl,
		t_point size)
{
	t_point				crd;
	int					i;
	t_color				color;

	i = 0;
	crd = pt_set(0, 0);
	while (crd.x < size.x)
	{
		color.c = sdl[i];
		gtk[i] = get_color_gtk(255, color.argb.r, color.argb.g,
				color.argb.b);
		crd = pt_ypluseg(crd, 0, size.y);
		i++;
	}
	return (gtk);
}

void	click_export(GtkWidget *widget, gpointer data)
{
	static GdkPixbuf	*pixbuf = NULL;
	static uint32_t		*pxl = NULL;
	t_point				size;
	GError				*error;

	if (!widget && !data)
		return ;
	error = NULL;
	size = *g_data->win->size;
	if (!pixbuf)
	{
		pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, size.x, size.y);
		pxl = (uint32_t*)gdk_pixbuf_get_pixels(pixbuf);
	}
	pxl = change_sdl_to_gtk(pxl, g_data->tex->tab_pxl, size);
	gdk_pixbuf_save(pixbuf, "RT.png", "png", &error, NULL);
	if (error && error->message)
		ft_putstr(error->message);
}
