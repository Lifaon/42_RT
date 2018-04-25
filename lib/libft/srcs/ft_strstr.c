/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:39:48 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/09 23:16:29 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *src, char const *to_find)
{
	int i;

	if ((!*src) && (!*to_find))
		return ((char *)src);
	if (!*src)
		return (NULL);
	i = -1;
	while (to_find[++i])
		if (to_find[i] != src[i])
			return (ft_strstr(src + 1, to_find));
	return ((char *)src);
}
