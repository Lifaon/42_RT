/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:08:07 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/12 16:37:19 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void	exit_all(t_data *data)
{
	if (data->nb_objects)
	{
		while (data->nb_objects--)
			if (data->objs[data->nb_objects].tex)
				free(data->objs[data->nb_objects].tex);
		free(data->objs);
	}
	if (data->nb_lights)
		free(data->lights);
	if (g_ui)
	{
		ft_strdel(&g_ui->path);
		free(g_ui);
		g_ui = NULL;
	}
	exit(EXIT_SUCCESS);
}
