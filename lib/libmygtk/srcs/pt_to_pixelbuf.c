/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_to_pixelbuf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 19:05:02 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/12 19:40:51 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mygtk.h"

void		pt_to_pixelbuf(t_point pt, t_pixelbuf *pxbuf, uint32_t color)
{
	int				to_color;

	if (!pxbuf)
		return ;
	if (pt.x >= pxbuf->size.x || pt.y >= pxbuf->size.y || pt.x < 0 || pt.y < 0)
		return ;
	to_color = (pt.x + (pt.y * pxbuf->size.x));
	pxbuf->pxl[to_color] = color;
}
