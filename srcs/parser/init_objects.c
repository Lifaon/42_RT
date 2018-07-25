/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 20:22:18 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/25 14:03:26 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	init_one_object2(t_data *data, int index)
{
	data->objs[index].pos = (t_vec){0, 0, 1500};
	data->objs[index].dir = (t_vec){0, 1, 0};
	data->objs[index].angle = (t_vec){0, 0, 0};
	data->objs[index].y_dir = (t_vec){1, 0, 0};
	data->objs[index].z_dir = (t_vec){0, 0, 1};
	data->objs[index].min = (t_vec){-INFINITY, -INFINITY, -INFINITY};
	data->objs[index].max = (t_vec){INFINITY, INFINITY, INFINITY};
	data->objs[index].tex = NULL;
	data->objs[index].tex_filename = NULL;
	data->objs[index].tex_pos = (t_point){0, 0};
	data->objs[index].tex_scale = 100;
	data->objs[index].tex_repeat = 0;
	data->objs[index].tex_limit = 1;
	data->objs[index].tex_trans = 0;
	data->objs[index].intersect = data->intersect[SPHERE];
	data->objs[index].get_normal = data->get_normal[SPHERE];
	data->objs[index].limit = data->limit[LIMIT_AXE];
}

void	init_one_object(t_data *data, int index)
{
	data->objs[index].obj_type = SPHERE;
	data->objs[index].limited = LIMIT_NONE;
	data->objs[index].enabled = 1;
	data->objs[index].r = 100;
	data->objs[index].spec = 1;
	data->objs[index].alpha = 100;
	data->objs[index].shiny = 0.;
	data->objs[index].trans = 0.;
	data->objs[index].ior = 1.;
	data->objs[index].color.c = 0xFFA600A6;
	data->objs[index].color2.c = 0xFFFFFFFF;
	data->objs[index].color_type = 0;
	data->objs[index].color_scale = 100;
	data->objs[index].perl_scale = 100;
	data->objs[index].perl_type = 0;
	data->objs[index].perl_opacity = 0.4;
	data->objs[index].bump_flag = 0;
	data->objs[index].bump_intensity = 0.2;
	data->objs[index].bump_scale = 100;
	init_one_object2(data, index);
}

int		init_objects(t_data *data, int nb)
{
	int i;

	i = -1;
	if (!(data->objs = (t_obj *)malloc(sizeof(t_obj) * nb)))
	{
		perror("Error : ");
		return (-1);
	}
	while (++i < nb)
		init_one_object(data, i);
	return (0);
}
