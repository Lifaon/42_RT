/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_around_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:07:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/14 22:39:47 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	rotate_around_object(t_data *data, t_camera *cam, t_vec point)
{
	t_vec vec;

	vec = vec_substract(cam->pos, point);
	vec = yaw(vec, (t_vec){0, 90, 0});
	cam->pos = vec_add(point, vec);
	cam->angle.y += 90;
	get_vp_up_left(cam);
	get_oc(data, *cam);
}
