/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:41:36 by vtudes            #+#    #+#             */
/*   Updated: 2018/06/07 14:48:26 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	translate_q(t_data *data)
{
	data->cams[data->i].pos.z -= TRANSLATION;
	get_vp_up_left(&data->cams[data->i]);
	choose_cam(data, data->i);
}

void	translate_e(t_data *data)
{
	data->cams[data->i].pos.z += TRANSLATION;
	get_vp_up_left(&data->cams[data->i]);
	choose_cam(data, data->i);
}
