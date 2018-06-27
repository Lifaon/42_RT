/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:41:36 by vtudes            #+#    #+#             */
/*   Updated: 2018/06/27 02:13:25 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	translate_q(t_data *data)
{
	t_vec	mvm;

	mvm = (t_vec){0, -TRANSLATION, 0};
	mvm = pitch(mvm, data->cam.angle);
	mvm = yaw(mvm, data->cam.angle);
	data->cam.pos = vec_add(data->cam.pos, mvm);
	get_vp_up_left(&data->cam);
	get_oc();
	data->cams[data->i] = data->cam;
}

void	translate_e(t_data *data)
{
	t_vec	mvm;

	mvm = (t_vec){0, TRANSLATION, 0};
	mvm = pitch(mvm, data->cam.angle);
	mvm = yaw(mvm, data->cam.angle);
	data->cam.pos = vec_add(data->cam.pos, mvm);
	get_vp_up_left(&data->cam);
	get_oc();
	data->cams[data->i] = data->cam;
}
