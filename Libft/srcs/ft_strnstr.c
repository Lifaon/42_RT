/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:52:49 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/27 16:00:35 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t len)
{
	size_t i;

	if (s1 == s2 || *s2 == '\0')
		return ((char *)((unsigned long)s1));
	while (*s1 != '\0' && len != 0)
	{
		i = 0;
		while (s1[i] == s2[i] && len - i != 0)
		{
			i++;
			if (s2[i] == '\0')
				return ((char *)((unsigned long)s1));
		}
		s1++;
		len--;
	}
	return (NULL);
}
