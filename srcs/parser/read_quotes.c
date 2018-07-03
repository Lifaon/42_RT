/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 02:37:17 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/03 02:37:25 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		read_quotes(char *str, char *word, int *index)
{
	int i;

	i = 0;
	while (str[i] && word[i])
	{
		if (str[i] != word[i])
			return (0);
		++i;
	}
	*index += i;
	return (1);
}
