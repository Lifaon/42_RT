/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:13:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/14 18:43:50 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_color	add_colors(t_color col1, t_color col2)
{
	t_color		ret;
	t_vector	added;

	ret.argb.a = 255;
	added.x = col1.argb.r + col2.argb.r;
	added.y = col1.argb.g + col2.argb.g;
	added.z = col1.argb.b + col2.argb.b;
	ret.argb.r = added.x <= 255 ? added.x : 255;
	ret.argb.g = added.y <= 255 ? added.y : 255;
	ret.argb.b = added.z <= 255 ? added.z : 255;
	return (ret);
}

t_color	blend_colors(t_color col1, t_color col2)
{
	t_color		ret;
	t_added		added;

	added.r = col1.argb.r + col2.argb.r;
	added.g = col1.argb.g + col2.argb.g;
	added.b = col1.argb.b + col2.argb.b;
	added.a = col1.argb.a + col2.argb.a;
	ret.argb.r = added.r / 2;
	ret.argb.g = added.g / 2;
	ret.argb.b = added.b / 2;
	ret.argb.a = added.a / 2;
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
