/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:52:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/05 14:04:49 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "vec.h"

void		rotate_x(t_data *data)
{
	t_vec	axe;
	t_vec	dir;
	double	theta;

	axe = (t_vec) { 0, 0, 0 };
	dir = vec_normalize(data->cams[data->i].dir);
	theta = (10.0 / 180.0) * M_PI;
	axe.y = dir.y * cos(theta) - dir.z * sin(theta);
	axe.z = dir.y * sin(theta) + dir.z * cos(theta);
	data->cams[data->i].dir = axe;
}

void	rotate_y(t_data *data)
{
	t_vec	axe;
	t_vec	dir;
	double	theta;

	axe = (t_vec) { 0, 0, 0 };
	dir = vec_normalize(data->cams[data->i].dir);
	theta = (10.0 / 180.0) * M_PI;
	axe.x = dir.x * cos(theta) - dir.z * sin(theta);
	axe.z = dir.x * sin(theta) + dir.z * cos(theta);
	data->cams[data->i].dir = axe;
}
