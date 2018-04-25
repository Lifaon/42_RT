/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:12:55 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/03 17:40:31 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_atoi_tab(char **str)
{
	size_t	i;
	size_t	j;
	int		*tab;

	i = 0;
	while (str[i])
		i++;
	if (!(tab = (int*)malloc(sizeof(int) * i)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			tab[i] = ft_atoi(str[i]);
			j++;
		}
		i++;
	}
	return (tab);
}
