/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:35:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/05 03:22:52 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parse.h"
#include "vec.h"

void	init_function_ptrs(t_data *data)
{
	data->intersect[0] = intersect_sphere;
	data->intersect[1] = intersect_plane;
	data->intersect[2] = intersect_cylinder;
	data->intersect[3] = intersect_cone;
	data->get_normal[0] = get_sphere_normal;
	data->get_normal[1] = get_plane_normal;
	data->get_normal[2] = get_cylinder_normal;
	data->get_normal[3] = get_cone_normal;
	data->limit[0] = &limit_axe;
	data->limit[1] = &limit_sphere;
	data->limit[2] = &limit_rectangle;
	data->limit[3] = &limit_circle;
	data->limit[4] = &limit_cyl;
	data->limit[5] = &limit_cone;
}

t_data		*data_init(int ac, char **av)
{
	t_point		size;
	t_data		*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	data->aa = 1;
	data->px = 0;
	data->cel_shading = 0;
	data->depth_of_field = -1;
	data->filter = FILTER_NONE;
	data->i = 0;
	data->nb_objects = 0;
	data->nb_lights = 0;
	data->ui = NULL;
	init_cameras(data);
	init_function_ptrs(data);
	data->img = NULL;
	data->draw = 1;
	return (data);
}
