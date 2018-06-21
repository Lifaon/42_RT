/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:31:12 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/20 20:14:03 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

/*
** min size is because the vector is put that way : [2.0, 1.5, 0.0]
** so if we add '[' + ']' + 2' ' + 2 ',' = 6
*/

size_t		size_vec(t_vec vec)
{
	return (6 + size_double(vec.x) + size_double(vec.y) + size_double(vec.z));
}
