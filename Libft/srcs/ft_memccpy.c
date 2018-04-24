/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:52:49 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/22 14:56:45 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	unsigned char		*p1;
	unsigned char const	*p2;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char const *)src;
	while (n--)
	{
		*p1++ = *p2;
		if (*p2 == (unsigned char)c)
			return (p1);
		else
			p2++;
	}
	return (NULL);
}
