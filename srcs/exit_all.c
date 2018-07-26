/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:08:07 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/26 09:23:59 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		exit_data(t_data *data)
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

void			exit_all(t_data *data)
{
	int		i;

	i = -1;
	if (data->clust_i == CLUST_HOST)
	{
		closesocket(data->clust.sock);
		while (++i < data->clust.nb_client_for_free)
			closesocket(data->clust.client_l[i].csock);
	}
	else if (data->clust_i == CLUST_CLIENT)
	{
		closesocket(data->clust.sock);
		free(data->cimg);
	}
	if (data)
		exit_data(data);
	if (g_ui)
	{
		g_object_unref(g_ui->app);
		free(g_ui);
		g_ui = NULL;
	}
	exit(EXIT_SUCCESS);
}
