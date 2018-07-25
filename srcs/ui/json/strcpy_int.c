/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:41:10 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 11:35:58 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

char	*strcpy_int(char *str, int n)
{
	size_t			size;
	size_t			cpy_size;
	unsigned int	nb;

	size = size_int(n);
	cpy_size = size;
	if (n == 0)
		str[--size] = '0';
	nb = (n < 0) ? -n : n;
	while (--size > 0 && nb)
	{
		str[size] = '0' + (nb % 10);
		nb /= 10;
	}
	str[0] = '0' + nb;
	if (n < 0)
		str[0] = '-';
	str += cpy_size;
	return (str);
}
