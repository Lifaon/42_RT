/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:08:07 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/24 16:39:59 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void	exit_all(t_data *data)
{
	int		i;

	i = -1;
	if (data->clust_i == CLUST_HOST)
	{
		closesocket(data->clust.sock);
		while (++i < data->nb_client)
			closesocket(data->clust.client_l[i].csock);
	}
	else if (data->clust_i == CLUST_CLIENT)
	{
		closesocket(data->clust.sock);
		free(data->cimg);
	}
	if (data->nb_objects)
	{
		while (data->nb_objects--)
			if (data->objs[data->nb_objects].tex)
				free(data->objs[data->nb_objects].tex);
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
