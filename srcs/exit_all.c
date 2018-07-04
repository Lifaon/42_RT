/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:08:07 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/27 19:55:25 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void	exit_all(t_data *data)
{
	if (data->nb_objects)
	{
		while (data->nb_objects--)
			pixelbuf_free(&data->objs[data->nb_objects].tex);
		free(data->objs);
	}
	if (data->nb_lights)
		free(data->lights);
	if (data->ui)
	{
		ft_strdel(&data->ui->path);
		free(data->ui);
	}
	exit(EXIT_SUCCESS);
}
