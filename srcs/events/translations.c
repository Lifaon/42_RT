/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:41:36 by vtudes            #+#    #+#             */
/*   Updated: 2018/06/20 20:17:12 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void		translate_w(t_data *data)
{
	data->cam.pos.y += TRANSLATION;
	get_vp_up_left(&data->cam);
	get_oc();
	data->cams[data->i] = data->cam;
}

void		translate_a(t_data *data)
{
	data->cam.pos.x -= TRANSLATION;
	get_vp_up_left(&data->cam);
	get_oc();
	data->cams[data->i] = data->cam;
}

void		translate_s(t_data *data)
{
	data->cam.pos.y -= TRANSLATION;
	get_vp_up_left(&data->cam);
	get_oc();
	data->cams[data->i] = data->cam;
}

void		translate_d(t_data *data)
{
	data->cam.pos.x += TRANSLATION;
	get_vp_up_left(&data->cam);
	get_oc();
	data->cams[data->i] = data->cam;
}
