/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:55:00 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/29 17:09:59 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static size_t	get_size(int n)
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

static void		add_int(char *dst, int n, size_t size, size_t i)
{
	unsigned int	nb;

	nb = (n < 0) ? -n : n;
	while (--size > i)
	{
		dst[size] = '0' + (nb % 10);
		nb /= 10;
	}
	dst[size] = '0' + nb;
	if (n < 0)
		dst[size] = '-';
}

char			*join_int(char const *s1, int n)
{
	char		*dst;
	size_t		size;
	size_t		i;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + get_size(n);
	if (!(dst = ft_strnew(size)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	add_int(dst, n, size, i);
	return (dst);
}
