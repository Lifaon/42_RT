/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:52:49 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/27 16:12:15 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	size_t i;

	if (s1 == s2 || !*s2)
		return ((char *)((unsigned long)s1));
	while (*s1)
	{
		i = 0;
		while (s1[i] == s2[i])
		{
			i++;
			if (!s2[i])
				return ((char *)(unsigned long)s1);
		}
		s1++;
	}
	return (NULL);
}
