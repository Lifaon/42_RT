/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:54 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/22 16:53:19 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *dst;
	char *p;

	if (s == NULL)
		return (NULL);
	if (!(dst = ft_strnew(ft_strlen(s))))
		return (NULL);
	p = dst;
	while (*s)
		*dst++ = f(*s++);
	return (p);
}
