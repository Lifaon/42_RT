/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:52:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/13 00:09:04 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "vec.h"

void	rotate_up(t_data *data)
{
	data->cams[data->i].angle.x -= ANGLE;
	if (data->cams[data->i].angle.x <= -360.0)
		data->cams[data->i].angle.x += 360.0;
}

void	rotate_down(t_data *data)
{
	data->cams[data->i].angle.x += ANGLE;
	if (data->cams[data->i].angle.x >= 360.0)
		data->cams[data->i].angle.x -= 360.0;
}

void	rotate_left(t_data *data)
{
	data->cams[data->i].angle.y += ANGLE;
	if (data->cams[data->i].angle.y >= 360.0)
		data->cams[data->i].angle.y -= 360.0;
}

void	rotate_right(t_data *data)
{
	data->cams[data->i].angle.y -= ANGLE;
	if (data->cams[data->i].angle.y <= -360.0)
		data->cams[data->i].angle.y += 360.0;
}
