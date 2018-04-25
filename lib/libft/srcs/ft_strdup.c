/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:37:35 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/13 22:40:46 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*src2;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(src2 = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (i == 0)
	{
		src2[0] = '\0';
		return (src2);
	}
	ft_strcpy(src2, src);
	src2[i] = '\0';
	return (src2);
}
