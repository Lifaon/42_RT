/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:55:00 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/20 20:11:22 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

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

static size_t	set_multiply(size_t size)
{
	long		multiply;
	size_t		i;

	i = 17;
	multiply = 1;
	while (--i > size)
		multiply *= 10;
	return (multiply);
}

size_t			size_double(double n)
{
	size_t		size;
	long		multiply;
	long		integer;
	long		decimal;

	size = get_size_integer(n, &integer);
	multiply = set_multiply(size);
	if (n < 0)
		size++;
	n = (n < 0) ? (n * -1) : n;
	if (((long)(n * 10 - integer)) > 0)
	{
		decimal = (long)((n - integer) * multiply);
		while (decimal != 0 && (decimal % 10) == 0)
			decimal /= 10;
	}
	else
		decimal = 0;
	while (decimal /= 10)
		size++;
	return (size);
}
