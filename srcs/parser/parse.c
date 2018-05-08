/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:31:19 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/08 19:54:33 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parse.h"

/*
**	Functions for degrees and radians conversions. Unsure if they will be used.
**
**	double		degrees_to_radians(double degrees)
**	{
**		return (degrees * M_PI / 180);
**	}
**
**	double		radians_to_degrees(double radians)
**	{
**		return (radians * 180 / M_PI);
**	}
*/

static void	init_cameras(t_data *data, int nb)
{
	int i;

	i = -1;
	while (++i < nb)
	{
		data->cams[i].pos = (t_vec){0, 0, 0};
		data->cams[i].dir = (t_vec){0, 0, 1};
		data->cams[i].fov = 20;
		get_vp_up_left(&data->cams[i]);
	}
}

void	parse(t_data *data, char *file_name)
{
	char	*str;
	int		i;

	if (!(str = get_full_read_file(file_name)))
		exit_all(data);
	//remove_white_spaces(&str);
	/*if (check_error(str))
		exit_all(data);*/
	i = -1;
	init_cameras(data, 4);
	while (str[++i])
		if (str[i] == '\"')
		{
			if (read_quotes(str + i, "\"cameras\"", &i))
				parse_cameras(data, str + i, &i);
			else if (read_quotes(str + i, "\"lights\"", &i))
				parse_lights(data, str + i, &i);
			else if (read_quotes(str + i, "\"objects\"", &i))
				parse_objects(data, str + i, &i);
		}
	free(str);
}
