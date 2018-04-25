/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:07:58 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/13 19:12:20 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[i]);
	while (i != 0)
	{
		i--;
		if (s[i] == c)
			return ((char *)&s[i]);
	}
	return (NULL);
}
