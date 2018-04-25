/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:28:46 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/13 11:12:25 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t nb)
{
	size_t		i;
	size_t		end;

	i = 0;
	if (nb == 0)
		return (ft_strlen(src));
	while (dest[i] && i < nb)
		i++;
	end = i;
	while (src[i - end] && i < nb - 1)
	{
		dest[i] = src[i - end];
		i++;
	}
	if (end < nb)
		dest[i] = '\0';
	return (end + ft_strlen(src));
}
