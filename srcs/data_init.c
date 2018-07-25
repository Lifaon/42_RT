/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:35:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/25 14:59:59 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parse.h"
#include "vec.h"
#include <limits.h>

static void		init_function_ptrs(t_data *data)
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

static void		data_init2(t_data *data, char **av)
{
	char	*chr;

	init_cameras(data);
	init_function_ptrs(data);
	data->img = NULL;
	data->draw = 1;
	chr = ft_strstr(av[0], "/rt");
	data->path = ft_strsub(av[0], 2, ft_strlen(av[0]) - (ft_strlen(chr) + 1));
	data->long_path = ft_strnew(PATH_MAX);
	getcwd(data->long_path, PATH_MAX);
	data->long_path = ft_strjoin_free(data->long_path, "/");
}

t_data			*data_init(char **av)
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	data->aa = 1;
	data->px = 0;
	data->cel_shading = 0;
	data->depth_of_field = -1;
	data->dof_coeff = 0.8;
	data->filter = FILTER_NONE;
	data->depth_max = 4;
	data->i = 0;
	data->nb_objects = 0;
	data->nb_lights = 0;
	data->caustic_flag = 0;
	data->photon_map = NULL;
	data->photon_total = 5000;
	data->photon_ppx = 20;
	data->photon_size = 2.5;
	data->stereo_scale = 10;
	data_init2(data, av);
	return (data);
}
