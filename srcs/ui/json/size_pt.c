/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_pt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:53:34 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 13:53:36 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

/*
** min size is because the vector is put that way : [2, 5]
** so if we add '[' + ']' + ' ' +  ',' = 4
*/

size_t		size_pt(t_point pt)
{
	return (4 + size_int(pt.x) + size_double(pt.y));
}
