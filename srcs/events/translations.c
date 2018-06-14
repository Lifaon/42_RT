/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:41:36 by vtudes            #+#    #+#             */
/*   Updated: 2018/06/14 19:11:23 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void		translate_w(t_data *data)
{
	data->cams[data->i].pos.y += TRANSLATION;
	get_vp_up_left(&data->cams[data->i]);
	get_oc(data, data->cams[data->i]);
}

void		translate_a(t_data *data)
{
	data->cams[data->i].pos.x -= TRANSLATION;
	get_vp_up_left(&data->cams[data->i]);
	get_oc(data, data->cams[data->i]);
}

void		translate_s(t_data *data)
{
	data->cams[data->i].pos.y -= TRANSLATION;
	get_vp_up_left(&data->cams[data->i]);
	get_oc(data, data->cams[data->i]);
}

void		translate_d(t_data *data)
{
	data->cams[data->i].pos.x += TRANSLATION;
	get_vp_up_left(&data->cams[data->i]);
	get_oc(data, data->cams[data->i]);
}
