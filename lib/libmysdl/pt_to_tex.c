/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_to_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:10:54 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 20:41:30 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

void		pt_to_tex(t_point pt, t_texture *tex, uint32_t color)
{
	int				to_color;

	if (!tex)
		return ;
	if (pt.x >= tex->size->x || pt.y >= tex->size->y || pt.x < 0 || pt.y < 0)
		return ;
	to_color = (pt.x + (pt.y * tex->size->x));
	tex->tab_pxl[to_color] = color;
}
