/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_db.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:51:01 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/29 13:16:00 by fchevrey         ###   ########.fr       */
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

char			*strcpy_db(char *str, double n)
{
	long		integer;
	long		decimal;
	size_t		size;
	size_t		cpy_size;

	size = get_size(n, &integer, &decimal);
	if (n < 0)
		size++;
	cpy_size = size;
	if (decimal == 0)
		str[--size] = '0';
	size = write_long(&decimal, size, str);
	str[size] = '.';
	if (integer == 0)
		str[--size] = '0';
	size = write_long(&integer, size, str);
	str[0] = '0' + integer;
	if (n < 0)
		str[0] = '-';
	str += cpy_size ;
	return (str);
}
