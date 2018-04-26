/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptfl_ypluseg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:41:00 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:36:00 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

t_ptfl			ptfl_ypluseg(t_ptfl src, t_ptfl incr, float ymin, float ymax)
{
	src.y = src.y + incr.y;
	if (src.y >= ymax)
	{
		src.y = ymin;
		src.x = src.x + incr.x;
	}
	return (src);
}
