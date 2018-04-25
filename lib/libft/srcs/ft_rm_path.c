/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 21:28:57 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/19 21:42:15 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rm_path(char *str)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			j = i;
		i++;
	}
	j++;
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(str) - j + 1))))
		exit(1);
	i = 0;
	while (str[j])
		result[i++] = str[j++];
	result[j] = '\0';
	return (result);
}
