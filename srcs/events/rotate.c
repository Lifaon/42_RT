/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:52:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/07 14:53:21 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "vec.h"

void	rotate_i(t_data *data)
{
	data->cams[data->i].angle.x -= ANGLE;
	if (data->cams[data->i].angle.x <= -360.0)
		data->cams[data->i].angle.x += 360.0;
}

void	rotate_k(t_data *data)
{
	data->cams[data->i].angle.x += ANGLE;
	if (data->cams[data->i].angle.x >= 360.0)
		data->cams[data->i].angle.x -= 360.0;
}

void	rotate_j(t_data *data)
{
	data->cams[data->i].angle.y += ANGLE;
	if (data->cams[data->i].angle.y >= 360.0)
		data->cams[data->i].angle.y -= 360.0;
}

void	rotate_l(t_data *data)
{
	data->cams[data->i].angle.y -= ANGLE;
	if (data->cams[data->i].angle.y <= -360.0)
		data->cams[data->i].angle.y += 360.0;
}
