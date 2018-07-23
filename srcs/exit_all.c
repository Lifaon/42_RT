/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:08:07 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/21 08:57:15 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void	exit_all(t_data *data)
{
	if (data)
	{
		if (data && data->nb_objects)
		{
			while (data->nb_objects--)
				if (data->objs[data->nb_objects].tex)
					pixelbuf_free(&data->objs[data->nb_objects].tex);
			free(data->objs);
		}
		if (data && data->nb_lights)
			free(data->lights);
		if (data->photon_map)
			free(data->photon_map);
		ft_strdel(&g_data->path);
		ft_strdel(&g_data->long_path);
		free(data);
	}
	if (g_ui)
	{
		free(g_ui);
		g_ui = NULL;
	}
	exit(EXIT_SUCCESS);
}
