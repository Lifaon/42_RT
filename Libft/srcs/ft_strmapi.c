/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:54 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/27 15:59:37 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;
	char			*p;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(dst = ft_strnew(ft_strlen(s))))
		return (NULL);
	p = dst;
	while (s[i])
	{
		*dst++ = f(i, s[i]);
		i++;
	}
	return (p);
}
