/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_around_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:07:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/20 00:02:59 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	rotate_around_point(t_data *data, t_vec pt, t_vec angle)
{
	t_vec vec;

	vec = vec_substract(data->cam.pos, pt);
	vec = yaw(vec, angle);
	vec = pitch(vec, angle);
	data->cam.pos = vec_add(pt, vec);
	data->cam.angle.x += angle.x;
	data->cam.angle.y += angle.y;
	get_vp_up_left(&data->cam);
	get_oc();
}
