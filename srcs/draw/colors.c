/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:13:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/04 15:58:51 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_color	add_colors(t_color col1, t_color col2)
{
	t_color		ret;
	t_vector	added;

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
	t_vector	added;

	added.x = col1.argb.r + col2.argb.r;
	added.y = col1.argb.g + col2.argb.g;
	added.z = col1.argb.b + col2.argb.b;
	ret.argb.r = added.x / 2;
	ret.argb.g = added.y / 2;
	ret.argb.b = added.z / 2;
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
