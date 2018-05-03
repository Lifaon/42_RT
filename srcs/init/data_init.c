/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:35:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/03 18:17:03 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	data_init(t_data *data)
{
	t_point		size;

	data->vpd = VP_DIST;
	data->vp00.x = -((double)WIN_W / 2);
	data->vp00.y = (double)WIN_H / 2;
	data->vp00.z = VP_DIST;
	data->ray.o.x = 0;
	data->ray.o.y = 0;
	data->ray.o.z = 0;
	size = pt_set(WIN_W, WIN_H);
	data->win = win_new(size, "RT");
	data->win->ren = SDL_CreateRenderer(data->win->ptr, 0, 0);
	data->tex = texture_new(size, data->win->ren);
	//t_mlx_init(&data->mlx);
}
