/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 04:26:11 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/02 02:22:47 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int		add_alpha(t_obj * obj, t_pixelbuf **pxbuf)
{
	uint8_t		*tmp;
	GtkWidget	*img;
	t_point		size;
	t_color		color;
	int			i;

	if (!(tmp = (uint8_t*)malloc(3 * (*pxbuf)->size.x * (*pxbuf)->size.y)))
		return (-1);
	tmp = memcpy(tmp, (*pxbuf)->pxl, 3 * (*pxbuf)->size.x * (*pxbuf)->size.y);
	img = (*pxbuf)->widget;
	size = (*pxbuf)->size;
	pixelbuf_free(pxbuf);
	*pxbuf = pixelbuf_new(size, img);
	obj->tex = *pxbuf;
	i = -1;
	while (++i < (*pxbuf)->size.x * (*pxbuf)->size.y)
	{
		color.argb.a = 255;
		color.argb.r = tmp[i * 3];
		color.argb.g = tmp[(i * 3) + 1];
		color.argb.b = tmp[(i * 3) + 2];
		(*pxbuf)->pxl[i] = color.c;
	}
	free(tmp);
	return (0);
}

void	parse_texture(t_obj *obj, char *file_name)
{
	t_pixelbuf	*pxbuf;

	if (!(pxbuf = pixelbuf_new_from_file(file_name)))
		return ;
	obj->tex = pxbuf;
	if (gdk_pixbuf_get_has_alpha(pxbuf->buf) == FALSE \
		&& add_alpha(obj, &pxbuf))
			pixelbuf_free(&obj->tex);
}
