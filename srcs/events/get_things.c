/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 01:11:36 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/24 20:57:31 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	get_oc(void)
{
	int i;

	i = -1;
	while (++i < g_data->nb_objects)
	{
		g_data->objs[i].oc = vec_substract(\
			g_data->cam.pos, g_data->objs[i].pos);
	}
}

void	get_vp_up_left(t_camera *cam)
{
	double vp_dist;

	vp_dist = fabs(tan(cam->fov * M_PI / 360));
	if (vp_dist > 0.000001)
		vp_dist = ((double)WIN_H * 0.5) / vp_dist;
	else
		vp_dist = 1000.0;
	cam->vp_up_left.x = cam->pos.x - ((double)WIN_W * 0.5);
	cam->vp_up_left.y = cam->pos.y + ((double)WIN_H * 0.5);
	cam->vp_up_left.z = vp_dist + cam->pos.z;
}

void	get_dir(t_obj *obj)
{
	obj->dir = all_rotations((t_vec){0, 1, 0}, obj->angle);
	obj->y_dir = all_rotations((t_vec){1, 0, 0}, obj->angle);
	obj->z_dir = all_rotations((t_vec){0, 0, 1}, obj->angle);
}
