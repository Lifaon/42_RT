/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_of_structs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:22:22 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/22 14:05:47 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		get_nb_lights(char *str)
{
	int i;
	int in_brace;
	int	nb_lights;

	i = -1;
	in_brace = 0;
	nb_lights = 0;
	while (str[++i] != ']' || in_brace)
	{
		if (str[i] == '{')
		{
			if (!in_brace)
				++nb_lights;
			++in_brace;
		}
		else if (str[i] == '}')
			--in_brace;
	}
	return (nb_lights);
}

int		get_nb_objects(char *str)
{
	int i;
	int in_braces;
	int	nb_objects;

	i = -1;
	in_braces = 1;
	nb_objects = 0;
	while (in_braces)
	{
		++i;
		if (in_braces == 1 && str[i] == '\"' && (\
			read_quotes(str + i, "\"sphere\"", &i) || \
			read_quotes(str + i, "\"plane\"", &i) || \
			read_quotes(str + i, "\"cylinder\"", &i) || \
			read_quotes(str + i, "\"cone\"", &i)))
			++nb_objects;
		if (str[i] == '{' || str[i] == '}')
			in_braces += str[i] == '{' ? 1 : -1;
	}
	return (nb_objects);
}
