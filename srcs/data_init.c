/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:35:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/19 20:20:50 by mlantonn         ###   ########.fr       */
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
}

t_data		*data_init(int ac, char **av)
{
	t_point		size;
	t_data		*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	data->aa = 1;
	data->nb_objects = 0;
	data->nb_lights = 0;
	data->ui = NULL;
	init_cameras(data);
	init_function_ptrs(data);
	parse(data, av[1]);
	get_oc(data, data->cams[0]);
	data->img = NULL;
	data->draw = 1;
	return (data);
}
