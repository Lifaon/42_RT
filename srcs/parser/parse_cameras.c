/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cameras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:15:42 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/19 20:20:44 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_oc(t_data *data, t_camera cam)
{
	int i;

	i = -1;
	while (++i < data->nb_objects)
		data->objs[i].oc = vec_substract(cam.pos, data->objs[i].pos);
}

void	get_vp_up_left(t_camera *cam)
{
	double vp_dist;

	vp_dist = fabs(tan(cam->fov * M_PI / 360));
	if (vp_dist > 0.000001)
		vp_dist = (WIN_H / 2) / vp_dist;
	else
		vp_dist = 1000.0;
	cam->vp_up_left.x = cam->pos.x - (WIN_W * 0.5);
	cam->vp_up_left.y = cam->pos.y + (WIN_H * 0.5);
	cam->vp_up_left.z = vp_dist + cam->pos.z;
}

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
