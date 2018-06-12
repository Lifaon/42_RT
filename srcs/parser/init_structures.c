/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:12:55 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/12 16:50:08 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "vec.h"

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

void	init_cameras(t_data *data)
{
	int i;

	i = -1;
	while (++i < CAM_NB)
	{
		data->cams[i].pos = (t_vec){0, 0, 0};
		data->cams[i].angle = (t_vec){0, 0, 0};
		data->cams[i].fov = 70;
		get_vp_up_left(&data->cams[i]);
	}
}

int		init_lights(t_data *data, int nb)
{
	int i;

	i = -1;
	if (!(data->lights = (t_light *)malloc(sizeof(t_light) * nb)))
		return (-1);
	while (++i < nb)
	{
		data->lights[i].is_para = 0;
		data->lights[i].r = 1;
		data->lights[i].ambi = 0.3;
		data->lights[i].pos = (t_vec){0.0, 0.0, 0.0};
		data->lights[i].dir = (t_vec){0.0, 0.0, 0.0};
		data->lights[i].color.c = 0xFFFFFF;
	}
	return (0);
}

int		init_objects(t_data *data, int nb)
{
	int i;

	i = -1;
	if (!(data->objs = (t_obj *)malloc(sizeof(t_obj) * nb)))
		return (-1);
	while (++i < nb)
	{
		data->objs[i].r = 100;
		data->objs[i].spec = 1;
		data->objs[i].alpha = 100;
		data->objs[i].color.c = 0xA600A6;
		data->objs[i].pos = (t_vec){0, 0, 1500};
		data->objs[i].dir = (t_vec){1, 1, 0};
		data->objs[i].normal = (t_vec){1, 1, 0.001};
		data->objs[i].intersect = intersect_sphere;
		data->objs[i].get_normal = get_sphere_normal;
	}
	return (0);
}
