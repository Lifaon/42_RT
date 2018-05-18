/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:12:55 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/18 16:14:17 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "rtv1.h"

void	get_vp_up_left(t_camera *cam)
{
	double vp_dist;

	vp_dist = (WIN_H / 2) / tan(cam->fov * M_PI / 180);
	cam->vp_up_left.x = -(double)WIN_W / 2;
	cam->vp_up_left.y = (double)WIN_H / 2;
	cam->vp_up_left.z = vp_dist + cam->pos.z;
}

void	init_cameras(t_data *data, int nb)
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
		data->objs[i].color.c = 0xA600A6;
		data->objs[i].pos = (t_vec){0, 0, 1500};
		data->objs[i].dir = (t_vec){1, 1, 0};
		data->objs[i].normal = (t_vec){1, 1, 0.001};
		data->objs[i].intersect = intersect_sphere;
		data->objs[i].get_normal = get_sphere_normal;
	}
	return (0);
}

void	init_function_ptrs(t_obj *object, int value)
{
	int		(*intersect[4])(struct s_obj, t_vec, t_inter *);
	t_vec	(*get_normal[4])(struct s_obj, t_inter);

	intersect[0] = intersect_sphere;
	intersect[1] = intersect_plane;
	intersect[2] = intersect_cylinder;
	intersect[3] = intersect_cone;
	object->intersect = intersect[value];
	get_normal[0] = get_sphere_normal;
	get_normal[1] = get_plane_normal;
	get_normal[2] = get_cylinder_normal;
	get_normal[3] = get_cone_normal;
	object->get_normal = get_normal[value];
}
