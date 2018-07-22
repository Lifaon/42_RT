/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_calcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:35:56 by vtudes            #+#    #+#             */
/*   Updated: 2018/07/22 16:40:09 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

double	lerp(double t, double a, double b)
{
	return (1 - t) * a + t * b;
}

double	curve(const double t)
{
	return (t * t * (3.0 - 2.0 * t));
}

double	at3(const float *v, const double x, const double y, \
			const double z)
{
	return (v[0] * x + v[1] * y + v[2] * z);
}
