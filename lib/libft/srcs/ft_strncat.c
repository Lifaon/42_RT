/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:46:27 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/09 10:53:00 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char const *src, size_t nb)
{
	int			i;
	size_t		j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	if (dest[i] == '\0')
	{
		dest[i] = src[j];
		while (src[j] != '\0' && j < nb)
		{
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	if (j == nb)
		dest[i] = '\0';
	if (src[j] == '\0')
		dest[i] = '\0';
	return (dest);
}
