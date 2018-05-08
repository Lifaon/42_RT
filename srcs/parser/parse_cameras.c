/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cameras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:15:42 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/08 20:02:42 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		get_vp_up_left(t_camera *cam)
{
	double vp_dist;

	vp_dist = (WIN_H / 2) / tan(cam->fov * M_PI / 180);
	cam->vp_up_left.x = -(double)WIN_W / 2;
	cam->vp_up_left.y = (double)WIN_H / 2;
	cam->vp_up_left.z = vp_dist + cam->pos.z;
}

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
				cam->dir = vec_normalize(parse_vec(str + i, &i));
			else if (read_quotes(str + i, "\"fov\"", &i))
				cam->fov = parse_nb(str + i, &i);
		}
	get_vp_up_left(cam);
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
