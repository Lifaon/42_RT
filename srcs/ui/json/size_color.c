/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:04:35 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/20 20:11:56 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** the color is put that way : [r, g, b, a]
** minus color = [0, 0, 0, 0] = 12 char
*/

size_t		size_color(t_color color)
{
	size_t		size;

	size = 12;
	if (color.argb.a >= 100)
		size += 2;
	else if (color.argb.a >= 10)
		size += 1;
	if (color.argb.r >= 100)
		size += 2;
	else if (color.argb.r >= 10)
		size += 1;
	if (color.argb.g >= 100)
		size += 2;
	else if (color.argb.g >= 10)
		size += 1;
	if (color.argb.b >= 100)
		size += 2;
	else if (color.argb.b >= 10)
		size += 1;
	return (size);
}
