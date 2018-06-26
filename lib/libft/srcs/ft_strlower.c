/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:47:38 by fchevrey          #+#    #+#             */
/*   Updated: 2017/11/26 19:51:28 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlower(char *src)
{
	int		i;
	char	*dest;

	i = -1;
	dest = ft_strdup(src);
	while (src[++i])
		dest[i] = (char)ft_tolower((int)src[i]);
	return (dest);
}
