/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:13:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/14 17:57:46 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color	col_multiply(t_color color, double nb)
{
	color.argb.r *= nb;
	color.argb.g *= nb;
	color.argb.b *= nb;
	return (color);
}

t_color col_divide(t_color color, double nb)
{
	color.argb.r /= nb;
	color.argb.g /= nb;
	color.argb.b /= nb;
	return (color);
}
