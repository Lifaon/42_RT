/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:52:49 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/20 19:21:23 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t i;
	size_t j;
	size_t src_len;

	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	if (dst[i] == '\0' && i < size)
	{
		while (*src && i + j < size - 1)
			dst[i + j++] = *src++;
		dst[i + j] = '\0';
	}
	return (src_len + i);
}
