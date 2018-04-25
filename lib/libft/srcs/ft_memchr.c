/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 23:32:52 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/13 11:39:40 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*k;

	k = (unsigned char*)s;
	i = 0;
	while (i < n && k[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((unsigned char *)&s[i]);
}
