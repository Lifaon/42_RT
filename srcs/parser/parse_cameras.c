/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cameras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:15:42 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/18 16:27:40 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	parse_camera(t_camera *cam, char *str, int *index)
{
	int i;
	int in_braces;

	i = 0;
	in_braces = 1;
	while (in_braces)
	{
		++i;
		if (str[i] == '\"' && in_braces == 1)
		{
			if (read_quotes(str + i, "\"position\"", &i))
				cam->pos = parse_vec(str + i, &i);
			else if (read_quotes(str + i, "\"angle\"", &i))
				cam->angle = parse_vec(str + i, &i);
			else if (read_quotes(str + i, "\"fov\"", &i))
				cam->fov = parse_nb(str + i, &i);
		}
		if (str[i] == '{' || str[i] == '}')
			in_braces += (str[i] == '{' ? 1 : -1);
	}
	get_vp_up_left(cam);
	*index += i;
}

void		parse_cameras(t_data *data, char *str, int *index)
{
	int cam_index;
	int in_braces;
	int i;

	i = 0;
	while (str[i] != '[')
		++i;
	in_braces = 1;
	cam_index = 0;
	while (in_braces)
	{
		++i;
		if (str[i] == '{' && cam_index < CAM_NB)
			parse_camera(&data->cams[cam_index++], str + i, &i);
		else if (str[i] == '[' || str[i] == ']')
			in_braces += (str[i] == '[' ? 1 : -1);
	}
	*index += i;
}
