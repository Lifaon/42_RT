/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:41:36 by vtudes            #+#    #+#             */
/*   Updated: 2018/06/07 14:48:17 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void		translate_w(t_data *data)
{
	data->cams[data->i].pos.y -= TRANSLATION;
	choose_cam(data, data->i);
}

void		translate_a(t_data *data)
{
	data->cams[data->i].pos.x += TRANSLATION;
	choose_cam(data, data->i);
}

void		translate_s(t_data *data)
{
	data->cams[data->i].pos.y += TRANSLATION;
	choose_cam(data, data->i);
}

void		translate_d(t_data *data)
{
	data->cams[data->i].pos.x -= TRANSLATION;
	choose_cam(data, data->i);
}
