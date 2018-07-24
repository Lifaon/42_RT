/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:12:55 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/24 20:22:13 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "vec.h"

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

void	init_one_light(t_data *data, int index)
{
	data->lights[index].is_para = 0;
	data->lights[index].disabled = 0;
	data->lights[index].r = 1;
	data->lights[index].ambi = 0.3;
	data->lights[index].pos = (t_vec){0, 0, 0};
	data->lights[index].dir = (t_vec){0, 0, -1};
	data->lights[index].angle = (t_vec){0, 0, 0};
	data->lights[index].color.c = 0xFFFFFFFF;
}

int		init_lights(t_data *data, int nb)
{
	int i;

	i = -1;
	if (!(data->lights = (t_light *)malloc(sizeof(t_light) * nb)))
	{
		perror("Error : ");
		data->nb_lights = 0;
		data->nb_lights_on = 0;
		return (-1);
	}
	while (++i < nb)
		init_one_light(data, i);
	return (0);
}
