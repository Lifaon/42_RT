/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:04:50 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/10 19:04:57 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static long long	val(const char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a')
		return (10 + c - 'a');
	return (10 + c - 'A');
}

long long			ft_atoi_base(char const *s, int b)
{
	long long nb;
	long long index;
	long long sign;

	if (b < 1 || b > 36)
		return (0);
	nb = 0;
	index = 0;
	sign = 1;
	while (*s && ((*s >= 9 && *s <= 13) || *s == ' '))
		++s;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	while ((*s >= '0' && *s <= '0' + b && *s <= '9') ||
		(*s >= 'A' && *s <= 'A' + b - 10) || (*s >= 'a' && *s <= 'a' + b - 10))
		nb += (long long)ft_pow(b, index++) * val(*s++);
	return ((long long)(nb * sign));
}
