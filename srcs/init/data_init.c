/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:35:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/08 14:01:38 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	choose_cam(t_data *data, int index)
{
	int i;

	data->i = index;
	i = -1;
	while (++i < data->nb_objects)
		data->objs[i].oc = vec_substract(\
			data->cams[index].pos, data->objs[i].pos);
}

void	data_init(t_data *data, int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl("Usage : ./rt \'file_name\'");
		exit(-1);
	}
	data->nb_objects = 0;
	data->nb_lights = 0;
	parse(data, av[1]);
	choose_cam(data, 0);
	t_mlx_init(&data->mlx);
}
