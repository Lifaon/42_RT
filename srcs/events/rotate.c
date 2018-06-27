/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:52:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/27 01:59:57 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "vec.h"

void	rotate_up(t_data *data)
{
	if (data->cam.angle.x <= -90.0)
		return ;
	data->cam.angle.x -= ANGLE;
	if (data->cam.angle.x <= -90.0)
		data->cam.angle.x = -90.0;
	data->cams[data->i] = data->cam;
}

void	rotate_down(t_data *data)
{
	if (data->cam.angle.x >= 90.0)
		return ;
	data->cam.angle.x += ANGLE;
	if (data->cam.angle.x >= 90.0)
		data->cam.angle.x = 90.0;
	data->cams[data->i] = data->cam;
}

void	rotate_left(t_data *data)
{
	data->cam.angle.y += ANGLE;
	if (data->cam.angle.y >= 360.0)
		data->cam.angle.y -= 360.0;
	data->cams[data->i] = data->cam;
}

void	rotate_right(t_data *data)
{
	data->cam.angle.y -= ANGLE;
	if (data->cam.angle.y <= -360.0)
		data->cam.angle.y += 360.0;
	data->cams[data->i] = data->cam;
}
