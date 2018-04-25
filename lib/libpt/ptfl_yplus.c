/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptfl_yplus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:50:37 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:36:04 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

t_ptfl			ptfl_yplus(t_ptfl src, t_ptfl incr, float ymin, float ymax)
{
	src.y = src.y + incr.y;
	if (src.y > ymax)
	{
		src.y = ymin;
		src.x = src.x + incr.x;
	}
	return (src);
}
