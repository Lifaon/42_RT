/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:55:00 by fchevrey          #+#    #+#             */
/*   Updated: 2017/11/28 14:53:24 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	size_t			size;
	unsigned int	nb;
	char			*dst;

	size = 1;
	if (n < 0)
		size++;
	nb = (n < 0) ? -n : n;
	while (nb /= 10)
		size++;
	dst = ft_strnew(size);
	if (dst == NULL)
		return (NULL);
	nb = (n < 0) ? -n : n;
	while (--size > 0)
	{
		dst[size] = '0' + (nb % 10);
		nb /= 10;
	}
	dst[0] = '0' + nb;
	if (n < 0)
		dst[0] = '-';
	return (dst);
}
