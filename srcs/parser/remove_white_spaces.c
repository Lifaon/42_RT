/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_white_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:34:53 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/02 15:40:58 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	get_size_without_ws(char *str)
{
	int i;
	int nb;
	int in_quotes;

	i = -1;
	nb = 0;
	in_quotes = 0;
	while (str[++i])
	{
		if (str[i] == '\"')
			in_quotes = (in_quotes ? 0 : 1);
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && !in_quotes)
			++nb;
	}
	return (i + 1 - nb);
}

static void	fill_new_str(char **new, char *str)
{
	int	i;
	int	j;
	int	in_quotes;

	i = -1;
	j = -1;
	in_quotes = 0;
	while (str[++j])
	{
		if (str[j] == '\"')
			in_quotes = (in_quotes ? 0 : 1);
		if ((str[j] == ' ' || str[j] == '\t' || str[j] == '\n') \
			&& !in_quotes)
			continue ;
		(*new)[++i] = str[j];
	}
	(*new)[i] = '\0';
}

void		remove_white_spaces(char **str)
{
	char *new;

	if (!(new = (char *)malloc(sizeof(char) * get_size_without_ws(*str))))
	{
		perror("Error ");
		return ;
	}
	fill_new_str(&new, *str);
	free(*str);
	*str = new;
}
