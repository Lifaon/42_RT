/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:22:52 by pmiceli           #+#    #+#             */
/*   Updated: 2018/05/10 00:13:01 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*dest;

	source = (char*)src;
	dest = (char*)dst;
	len--;
	if (src > dst)
		return (ft_memcpy(dst, src, len + 1));
	while ((int)len >= 0)
	{
		dest[len] = source[len];
		len--;
	}
	return (dst);
}
