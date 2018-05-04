/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cameras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:15:42 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/04 16:38:34 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	parse_camera(t_camera *cam, char *str, int *index)
{
	int i;

	i = -1;
	while (str[++i] != '}')
		if (str[i] == '\"')
		{
			if (read_quotes(str + i, "\"position\"", &i))
				cam->pos = parse_vec(str + i, &i);
			else if (read_quotes(str + i, "\"direction\"", &i))
				cam->dir = parse_vec(str + i, &i);
			else if (read_quotes(str + i, "\"fov\"", &i))
				cam->fov = parse_nb(str + i, &i);
		}
	*index += i;
}

void		parse_cameras(t_data *data, char *str, int *index)
{
	int cam_nb;
	int i;

	i = 0;
	while (str[i] != '[')
		++i;
	cam_nb = 0;
	while (str[++i] != ']')
		if (str[i] == '{' && cam_nb < 4)
			parse_camera(&data->cams[cam_nb++], str + i, &i);
	*index += i;
}
