/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:13:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/22 16:49:50 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_color	add_colors(t_color col1, t_color col2)
{
	t_color		ret;
	t_added		added;

	added.r = col1.argb.r + col2.argb.r;
	added.g = col1.argb.g + col2.argb.g;
	added.b = col1.argb.b + col2.argb.b;
	ret.argb.r = added.r <= 255 ? added.r : 255;
	ret.argb.g = added.g <= 255 ? added.g : 255;
	ret.argb.b = added.b <= 255 ? added.b : 255;
	ret.argb.a = 255;
	return (ret);
}

t_color	substract_colors(t_color col1, t_color col2)
{
	t_color		ret;
	t_added		added;

	added.r = col1.argb.r - col2.argb.r;
	added.g = col1.argb.g - col2.argb.g;
	added.b = col1.argb.b - col2.argb.b;
	ret.argb.r = added.r >= 0 ? added.r : 0;
	ret.argb.g = added.g >= 0 ? added.g : 0;
	ret.argb.b = added.b >= 0 ? added.b : 0;
	ret.argb.a = 255;
	return (ret);
}

t_color	blend_colors(t_color col1, t_color col2)
{
	t_color		ret;
	t_added		added;

	added.r = col1.argb.r + col2.argb.r;
	added.g = col1.argb.g + col2.argb.g;
	added.b = col1.argb.b + col2.argb.b;
	ret.argb.r = added.r / 2;
	ret.argb.g = added.g / 2;
	ret.argb.b = added.b / 2;
	ret.argb.a = 255;
	return (ret);
}

t_color	col_multiply(t_color color, double nb)
{
	t_color		ret;
	t_added		added;

	added.r = color.argb.r * nb;
	added.g = color.argb.g * nb;
	added.b = color.argb.b * nb;
	ret.argb.r = added.r <= 255 ? added.r : 255;
	ret.argb.g = added.g <= 255 ? added.g : 255;
	ret.argb.b = added.b <= 255 ? added.b : 255;
	ret.argb.a = 255;
	return (ret);
}

t_color	col_divide(t_color color, double nb)
{
	t_color		ret;
	t_added		added;

	added.r = color.argb.r / nb;
	added.g = color.argb.g / nb;
	added.b = color.argb.b / nb;
	ret.argb.r = added.r >= 0 ? added.r : 0;
	ret.argb.g = added.g >= 0 ? added.g : 0;
	ret.argb.b = added.b >= 0 ? added.b : 0;
	ret.argb.a = 255;
	return (ret);
}
