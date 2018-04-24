/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:52:49 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/27 15:39:55 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)((unsigned long)s1);
	p2 = (unsigned char *)((unsigned long)s2);
	i = 0;
	if (n == 0)
		return (0);
	while (p1[i] == p2[i] && i < n - 1)
		i++;
	if (!p1[i] && p1[i] == p2[i])
		return (0);
	else
		return (p1[i] - p2[i]);
}
