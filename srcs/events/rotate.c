/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:52:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/05 18:26:25 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "vec.h"
#define ANGLE 5.0

void	rotate_i(t_data *data)
{
	t_vec	axe;
	t_vec	dir;
	double	theta;

	dir = vec_normalize(data->cams[data->i].dir);
	axe = (t_vec) {dir.x, 0, 0};
	theta = (-ANGLE / 180.0) * M_PI;
	axe.y = (dir.y * cos(theta) - dir.z * sin(theta));
	axe.z = (dir.y * sin(theta) + dir.z * cos(theta));
	data->cams[data->i].dir = axe;
}

void	rotate_k(t_data *data)
{
	t_vec	axe;
	t_vec	dir;
	double	theta;

	dir = vec_normalize(data->cams[data->i].dir);
	axe = (t_vec) {dir.x, 0, 0};
	theta = (ANGLE / 180.0) * M_PI;
	axe.y = dir.y * cos(theta) - dir.z * sin(theta);
	axe.z = dir.y * sin(theta) + dir.z * cos(theta);
	data->cams[data->i].dir = axe;
}

void	rotate_j(t_data *data)
{
	t_vec	axe;
	t_vec	dir;
	double	theta;

	dir = vec_normalize(data->cams[data->i].dir);
	axe = (t_vec) { 0, dir.y, 0};
	theta = (ANGLE / 180.0) * M_PI;
	axe.x = dir.x * cos(theta) - dir.z * sin(theta);
	axe.z = dir.x * sin(theta) + dir.z * cos(theta);
	data->cams[data->i].dir = axe;
}

void	rotate_l(t_data *data)
{
	t_vec	axe;
	t_vec	dir;
	double	theta;

	dir = vec_normalize(data->cams[data->i].dir);
	axe = (t_vec) {0, dir.y, 0};
	theta = (-ANGLE / 180.0) * M_PI;
	axe.x = dir.x * cos(theta) - dir.z * sin(theta);
	axe.z = dir.x * sin(theta) + dir.z * cos(theta);
	data->cams[data->i].dir = axe;
}
