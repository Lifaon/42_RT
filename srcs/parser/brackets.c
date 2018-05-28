/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:00:32 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/23 17:29:22 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		brackets(char *str)
{
	char	*brackets;
	int		i;
	int		j;

	if (!(brackets = (char *)malloc(sizeof(char) * ft_strlen(str))))
	{
		perror("Error : ");
		return (-1);
	}
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '[' || str[i] == '{')
			brackets[j++] = (str[i] == '[') ? ']' : '}';
		else if ((str[i] == ']' || str[i] == '}') && \
			(j < 1 || (brackets[--j] != str[i])))
			break ;
	}
	if (--j)
		ft_putstr("Scene file invalid : brackets not well formated\n");
	free(brackets);
	return (j);
}
