/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:54 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/23 14:46:29 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	if (n < 0)
		return (ft_nbrlen(-n) + 1);
	if (n >= 10)
		return (ft_nbrlen(n / 10) + 1);
	return (1);
}

char			*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	size_t	a;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen(n);
	a = 0;
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[len] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
		a = 1;
	}
	while (len-- > a)
	{
		s[len] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
