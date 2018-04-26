/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 20:31:41 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:36:53 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

void		pt_swap(t_point *pt1, t_point *pt2)
{
	t_point		swap;

	if (!pt1 || !pt2)
		return ;
	swap.x = pt1->x;
	swap.y = pt1->y;
	pt1->x = pt2->x;
	pt1->y = pt2->y;
	pt2->x = swap.x;
	pt2->y = swap.y;
}
