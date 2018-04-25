/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_ypluseg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:40:15 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:36:43 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

t_point			pt_ypluseg(t_point src, int ymin, int ymax)
{
	src.y++;
	if (src.y >= ymax)
	{
		src.y = ymin;
		src.x++;
	}
	return (src);
}
