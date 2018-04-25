/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 21:35:32 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/30 21:16:17 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char *str, char c)
{
	size_t	i;
	size_t	m;

	i = 0;
	m = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			m++;
		i++;
	}
	return (m);
}

static char		**ft_malloc_words(char *str, char c, char **p)
{
	size_t	i;
	size_t	m;
	size_t	t;

	i = 0;
	m = 0;
	t = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
			{
				if (!(p[m++] = ft_strnew(sizeof(char) * (t + 1))))
					return (NULL);
				t = 0;
			}
			t++;
		}
		i++;
	}
	return (p);
}

static char		**ft_fill_words(char *str, char c, char **p)
{
	size_t	i;
	size_t	m;
	size_t	t;

	i = 0;
	m = 0;
	t = 0;
	while (str[i])
	{
		if (str[i] != c)
			p[m][t++] = str[i];
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			t = 0;
			m++;
		}
		i++;
	}
	return (p);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	**p;

	if (s == NULL)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	if (!(p = (char**)malloc(sizeof(char*) * (ft_count_words(str, c) + 1))))
		return (NULL);
	p[ft_count_words(str, c)] = NULL;
	if (!(p = ft_malloc_words(str, c, p)))
		return (NULL);
	p = ft_fill_words(str, c, p);
	free(str);
	return (p);
}
