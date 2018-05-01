/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:31:19 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/01 20:01:28 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		find_str_index(char const *s1, char const *s2)
{
	int i;
	int j;

	i = -1;
	while (s1[++i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			++j;
			if (!s2[j])
				return (i);
		}
	}
	return (-1);
}

void	parse(t_data *data, char *file_name)
{
	char	*str;
	int		nb;

	str = get_full_read_file(file_name);
	nb = get_nb_objs(str);
	free(str);
}
