/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:13:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/21 19:10:58 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color	add_colors(t_color col1, t_color col2)
{
	t_color ret;

	ret.argb.r = col1.argb.r + col2.argb.r <= 255 ? \
		col1.argb.b + col2.argb.b : 255;
	ret.argb.g = col1.argb.g + col2.argb.g <= 255 ? \
		col1.argb.b + col2.argb.b : 255;
	ret.argb.b = col1.argb.b + col2.argb.b <= 255 ? \
		col1.argb.b + col2.argb.b : 255;
	return (ret);
}

t_color	col_multiply(t_color color, double nb)
{
	color.argb.r *= nb;
	color.argb.g *= nb;
	color.argb.b *= nb;
	return (color);
}

t_color	col_divide(t_color color, double nb)
{
	color.argb.r /= nb;
	color.argb.g /= nb;
	color.argb.b /= nb;
	return (color);
}
