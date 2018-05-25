/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:55:00 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/25 20:30:41 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <limits.h>

size_t		get_size_integer(double n, long *integer)
{
	size_t		size;
	long		cpy_integer;

	size = 1;
	if (n < 0)
		size++;
	*integer = (n < 0) ? (long)(n * -1) : (long)n;
	cpy_integer = *integer;
	while (cpy_integer /= 10)
		size++;
	return (size);
}

size_t		get_size(double n, long *integer, long *decimal)
{
	size_t		size;
	long		cpy_decimal;
	long		multiply;
	int			i;

	i = 17;
	multiply = 1;
	size = get_size_integer(n, integer);
	while (--i > size)
		multiply *= 10;
	if (((long)(n * 10 - *integer)) > 0)
	{
		size++;
		*decimal = (long)((n - *integer) * multiply);
		while (*decimal != 0 && (*decimal % 10) == 0)
			*decimal /= 10;
	}
	else
		*decimal = 0;
	cpy_decimal = *decimal;
	while (cpy_decimal > 0)
	{
		cpy_decimal /= 10;
		size++;
	}
	return (size);
}

char		*ft_dbtoa(double n)
{
	long		integer;
	long		decimal;
	char		*dst;
	size_t		size;

	size = get_size(n, &integer, &decimal);
	printf("size = %lu  integer = %ld  decimal = %ld\n", size, integer, decimal);
	if (!(dst = ft_strnew(size)))
		return (NULL);
	while (--size > 0 && decimal)
	{
		dst[size] = '0' + (decimal % 10);
		decimal /= 10;
	}
	dst[size] = '.';
	if (integer == 0)
		dst[--size] = '0';
	while (--size > 0 && integer)
	{
		dst[size] = '0' + (integer % 10);
		integer /= 10;
	}
	dst[0] = '0' + integer;
	if (n < 0)
		dst[0] = '-';
	return (dst);
}

int		main(void)
{
	double		n;
	n = 127000.2711111111;
	printf("n = %lF dbitoa = %s\n", n, ft_dbtoa(n));
	n = 444.1234567894444444;
	printf("n = %lF dbitoa = %s\n", n, ft_dbtoa(n));
	n = 1999999991999991;
	printf("n = %lF dbitoa = %s\n", n, ft_dbtoa(n));
	n = 0.123456789123456;
	printf("n = %lF dbitoa = %s\n", n, ft_dbtoa(n));
	n += 0.00000001;
	printf("n = %lF dbitoa = %s\n", n, ft_dbtoa(n));
	return (0);
}
