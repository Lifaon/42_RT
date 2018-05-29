/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:35:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/29 19:58:16 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "parse.h"

void		choose_cam(t_data *data, int index)
{
	int i;

	data->i = index;
	i = -1;
	while (++i < data->nb_objects)
		data->objs[i].oc = vec_substract(\
			data->cams[index].pos, data->objs[i].pos);
}

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

	if (ac != 2)
	{
		ft_putendl("Usage : ./rt \'file_name\'");
		exit(-1);
	}
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	data->nb_objects = 0;
	data->nb_lights = 0;
	data->tex = NULL;
	data->win = NULL;
	init_cameras(data);
	init_function_ptrs(data);
	parse(data, av[1]);
	choose_cam(data, 0);
	size = pt_set(WIN_W, WIN_H);
	if (!(data->win = win_new(size, "RT")))
		exit_all(data);
	data->win->ren = SDL_CreateRenderer(data->win->ptr, 0, 0);
	data->tex = texture_new(size, data->win->ren);
	data->draw = 1;
	return (data);
}
