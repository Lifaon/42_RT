/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 04:26:11 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/30 05:06:31 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_texture(t_obj *obj, char *file_name)
{
	t_pixelbuf	*pxbuf;
	uint8_t		*tmp;
	int			i;

	if (!(pxbuf = pixelbuf_new_from_file(file_name)))
		return ;
	if (!(obj->tex = (t_color *)malloc(32 * pxbuf->size.x * pxbuf->size.y)))
	{
		pixelbuf_free(&pxbuf);
		return ;
	}
	obj->tex_size.x = pxbuf->size.x;
	obj->tex_size.y = pxbuf->size.y;
	i = -1;
	if (gdk_pixbuf_get_has_alpha(pxbuf->buf))
		while (++i < pxbuf->size.x * pxbuf->size.y)
			obj->tex[i].c = pxbuf->pxl[i];
	else
	{
		tmp = (uint8_t *)pxbuf->pxl;
		while (++i < pxbuf->size.x * pxbuf->size.y)
		{
			obj->tex[i].argb.a = 255;
			obj->tex[i].argb.r = tmp[i * 3];
			obj->tex[i].argb.g = tmp[(i * 3) + 1];
			obj->tex[i].argb.b = tmp[(i * 3) + 2];
		}
	}
	pixelbuf_free(&pxbuf);
}
