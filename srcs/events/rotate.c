/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:52:29 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/05 13:36:08 by mlantonn         ###   ########.fr       */
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
	printf(" Autours de l'axe X\n");
	printf(" Theta\t= %f\n", theta);
	axe.y = dir.y * cos(theta) - dir.z * sin(theta);
	axe.z = dir.y * sin(theta) + dir.z * cos(theta);
	printf("   Y\t= %f\n", axe.y);
	printf("   Z\t= %f\n", axe.z);
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
	printf(" Autours de l'axe Y\n");
	printf(" Theta\t= %f\n", theta);
	axe.x = dir.x * cos(theta) - dir.z * sin(theta);
	axe.z = dir.x * sin(theta) + dir.z * cos(theta);
	printf("   X\t= %f\n", axe.x);
	printf("   Z\t= %f\n", axe.z);
	data->cams[data->i].dir = axe;
}
