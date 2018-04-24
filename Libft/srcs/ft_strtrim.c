/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:54 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/27 16:16:48 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*cpy;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
		j--;
	if (i > j)
		return (ft_strdup(""));
	if (!(cpy = ft_strnew(j - i)))
		return (NULL);
	if (j == 0 && i == 0)
		return ((char *)((unsigned long)s));
	while (i < j)
		cpy[k++] = (char)s[i++];
	cpy[k] = '\0';
	return (cpy);
}
