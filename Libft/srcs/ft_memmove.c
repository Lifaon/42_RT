/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:52:49 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/27 15:41:06 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)((unsigned long)dst);
	p2 = (unsigned char *)((unsigned long)src);
	i = 0;
	while (i < n)
		if (&p1[i++] == p2)
			return (ft_memcpy(dst, src, n));
	while (n--)
		p1[n] = p2[n];
	return (dst);
}
