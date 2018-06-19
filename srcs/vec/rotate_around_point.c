/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_around_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:07:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/18 17:48:37 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	rotate_around_point(t_data *data, t_camera *cam, t_vec pt, t_vec angle)
{
	t_vec vec;

	vec = vec_substract(cam->pos, pt);
	vec = yaw(vec, angle);
	vec = pitch(vec, angle);
	cam->pos = vec_add(pt, vec);
	cam->angle.x += angle.x;
	cam->angle.y += angle.y;
	get_vp_up_left(cam);
	get_oc(data, *cam);
}
