/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:20:42 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/20 20:11:16 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		size_int(int n)
{
	size_t			size;
	unsigned int	nb;

	size = 1;
	if (n < 0)
		size++;
	nb = (n < 0) ? -n : n;
	while (nb /= 10)
		size++;
	return (size);
}
