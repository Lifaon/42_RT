/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_white_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:34:53 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/01 19:44:17 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_size_without_white_spaces(char *str)
{
	int i;
	int nb;

	i = -1;
	nb = 0;
	while (str[++i])
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			++nb;
	return (i - nb);
}

char	*remove_white_spaces(char *str)
{
	int		size;
	int		i;
	int		j;
	char	*ret;

	size = get_size_without_white_spaces(str);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
	{
		perror("Error ");
		return (NULL);
	}
	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
			++j;
		ret[i] = str[j];
		++i;
		++j;
	}
	return (ret);
}
