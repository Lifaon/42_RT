/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:31:19 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/03 02:09:33 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parse.h"

void	parse(t_data *data, char *file_name)
{
	char	*str;
	int		i;

	if (!(str = get_full_read_file(file_name)))
		exit_all(data);
	remove_white_spaces(&str);
	check_error(data, str);
	i = -1;
	while (str[++i])
		if (str[i] == '\"')
		{
			if (read_quotes(str + i, "\"cameras\"", &i))
				parse_cameras(data, str + i, &i);
			else if (read_quotes(str + i, "\"lights\"", &i) && \
				!data->nb_lights)
				parse_lights(data, str + i, &i);
			else if (read_quotes(str + i, "\"objects\"", &i) && \
				!data->nb_objects)
				parse_objects(data, str + i, &i);
		}
	data->cam = data->cams[data->i];
	free(str);
}
