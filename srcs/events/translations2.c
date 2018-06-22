/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:41:36 by vtudes            #+#    #+#             */
/*   Updated: 2018/06/20 20:17:17 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	translate_q(t_data *data)
{
	data->cam.pos.z -= TRANSLATION;
	get_vp_up_left(&data->cam);
	get_oc();
	data->cams[data->i] = data->cam;
}

void	translate_e(t_data *data)
{
	data->cam.pos.z += TRANSLATION;
	get_vp_up_left(&data->cam);
	get_oc();
	data->cams[data->i] = data->cam;
}
