/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:35:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/23 18:28:15 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		choose_cam(t_data *data, int index)
{
	int i;

	data->i = index;
	i = -1;
	while (++i < data->nb_objects)
		data->objs[i].oc = vec_substract(\
			data->cams[index].pos, data->objs[i].pos);
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
	parse(data, av[1]);
	choose_cam(data, 0);
	size = pt_set(WIN_W, WIN_H);
	if (!(data->win = win_new(size, "RT")))
		exit_all(data);
	data->win->ren = SDL_CreateRenderer(data->win->ptr, 0, 0);
	data->tex = texture_new(size, data->win->ren);
	return (data);
}
