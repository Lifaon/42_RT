/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:09:54 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/27 16:28:43 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_tab_len(char const *s, char c)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	if (s == NULL)
		return (1);
	while (s[i])
	{
		if (i == 0)
			while (s[i] == c && *s)
				i++;
		while (s[i] != c && s[i])
			i++;
		len++;
		while (s[i] == c && s[i])
			i++;
	}
	return (len);
}

static size_t	ft_small_len(char const *s, char c)
{
	size_t len;
	size_t i;

	len = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i + len] && s[i + len] != c)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**tab;

	i = 0;
	len = ft_tab_len(s, c);
	if (!(tab = (char **)malloc(sizeof(tab) * (len + 1))))
		return (NULL);
	tab[len] = NULL;
	tab[0] = NULL;
	if ((len == 1 && ft_small_len(s, c) == 0))
		return (tab);
	while (i < len && *s && !(j = 0))
	{
		while (*s == c && *s)
			s++;
		if (!(tab[i] = ft_strnew(ft_small_len(s, c))))
			return (NULL);
		while (*s != c && *s)
			tab[i][j++] = *s++;
		tab[i++][j] = '\0';
	}
	return (tab);
}
