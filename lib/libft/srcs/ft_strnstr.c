/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:37:40 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/13 22:06:23 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *src, char const *to_find, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!*to_find)
		return ((char *)src);
	while (src[i] && i < len)
	{
		while (to_find[j] == src[i + j] && to_find[j] && i + j < len)
			j++;
		if (j == ft_strlen(to_find))
			return ((char *)(src + i));
		i++;
		j = 0;
	}
	return (NULL);
}
