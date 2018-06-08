/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:55:00 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/26 16:48:52 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static size_t	get_size_integer(double n, long *integer)
{
	size_t		size;
	long		cpy_integer;

	size = 3;
	*integer = (n < 0) ? (long)(n * -1) : (long)n;
	cpy_integer = *integer;
	while (cpy_integer /= 10)
		size++;
	return (size);
}

static size_t	get_size(double n, long *integer, long *decimal)
{
	size_t		size;
	long		cpy_decimal;
	long		multiply;
	size_t			i;
	double		cpy;

	i = 17;
	multiply = 1;
	size = get_size_integer(n, integer);
	cpy = (n < 0) ? (n * -1) : n;
	while (--i > size)
		multiply *= 10;
	if (((long)(cpy * 10 - *integer)) > 0)
	{
		*decimal = (long)((cpy - *integer) * multiply);
		while (*decimal != 0 && (*decimal % 10) == 0)
			*decimal /= 10;
	}
	else
		*decimal = 0;
	cpy_decimal = *decimal;
	while (cpy_decimal /= 10)
		size++;
	return (size);
}

static size_t	write_long(long *nb, size_t size, char *str)
{
	while (--size > 0 && *nb)
	{
		str[size] = '0' + (*nb % 10);
		*nb /= 10;
	}
	return (size);
}

char			*ft_dbtoa(double n)
{
	long		integer;
	long		decimal;
	char		*dst;
	size_t		size;

	size = get_size(n, &integer, &decimal);
	if (n < 0)
		size++;
	if (!(dst = ft_strnew(size)))
		return (NULL);
	if (decimal == 0)
		dst[--size] = '0';
	size = write_long(&decimal, size, dst);
	dst[size] = '.';
	if (integer == 0)
		dst[--size] = '0';
	size = write_long(&integer, size, dst);
	dst[0] = '0' + integer;
	if (n < 0)
		dst[0] = '-';
	return (dst);
}
