/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixelbuf_in_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 18:57:03 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/24 19:16:24 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mygtk.h"

void	fill_pixelbuf_in_color(t_pixelbuf *pxlbuf, uint32_t color)
{
	int				i;
	int				max;

	if (pxlbuf->size.x == 0)
		max = pxlbuf->size.y;
	else if (pxlbuf->size.y == 0)
		max = pxlbuf->size.x;
	else
		max = pxlbuf->size.x * pxlbuf->size.y;
	i = 0;
	while (i < max)
	{
		pxlbuf->pxl[i] = color;
		i++;
	}
}
