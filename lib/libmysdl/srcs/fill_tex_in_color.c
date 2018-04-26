/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img_in_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:35:44 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 19:42:27 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

void	fill_tex_in_color(t_texture *tex, uint32_t color)
{
	int				i;
	int				max;

	if (tex->size->x == 0)
		max = tex->size->y;
	else if (tex->size->y == 0)
		max = tex->size->x;
	else 
		max = tex->size->x * tex->size->y;
	i = 0;
	while (i < max)
	{
		tex->tab_pxl[i] = color;
		i++;
	}
}
