/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:02:31 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/13 19:44:25 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		len;
	char		*new;

	i = 0;
	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	while (i < len && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (i == len)
		return (new = ft_strsub(s, i, 0));
	len--;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	return (new = ft_strsub(s, i, len - i + 1));
}
