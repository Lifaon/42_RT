/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:32:26 by pmiceli           #+#    #+#             */
/*   Updated: 2018/07/25 15:22:45 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "clust.h"

void			*recv_work(void *arg)
{
	t_client		*client;
	uint32_t		*buff;
	t_point			crd;
	int				xmax;

	if (!(buff = (uint32_t*)ft_memalloc(sizeof(uint32_t) * (WIN_W * WIN_H))))
		exit_cause("malloc errror");
	client = (t_client *)arg;
	ft_putendl_color("en attente de la reception des infos", "orange");
	int ret = 0;
	while (ret < WIN_W * WIN_H * sizeof(int))
		ret += recv(client->csock, ((unsigned char *)buff) + ret, 1000, 0);
	ft_putendl_color("reception des infos", "green");
	crd.y = -1;
	xmax = (WIN_W / (g_data->nb_client + 1)) * (client->x + 1) + 0.5;
	while (++crd.y < WIN_H)
	{
		crd.x = (WIN_W / (client->nb_client + 1)) * client->x;
		while (crd.x < xmax)
		{
			pt_to_pixelbuf(crd, g_data->img, buff[crd.x + (crd.y * WIN_W)]);
			crd.x++;
		}
	}
	free(buff);
	return (arg);
}

void			*host_draw(void *arg)
{
	if (g_data->px > 1)
		draw_pixelated_image(g_data);
	else if (g_data->cel_shading)
		cel_shading();
	else if (g_data->depth_of_field >= 0 \
			&& g_data->depth_of_field < g_data->nb_objects)
		depth_of_field();
	else
		draw_image();
	if (g_data->filter == FILTER_BNW)
		black_and_white(g_data);
	else if (g_data->filter == FILTER_SEPIA)
		sepia(g_data);
	else if (g_data->filter == FILTER_STEREO)
		get_stereo();
	return (arg);
}

void			host_work(int send)
{
	pthread_t		thread;
	int				i;
	int				ret;

	i = -1;
	if (send == 1)
		ret = send_data_to_client();
	if (g_data->filter != FILTER_STEREO)
	{
		if (pthread_create(&thread, NULL, host_draw, g_data))
			exit_cause("error: pthread_create(): Failed");
	}
	else
		get_stereo();
	while (++i < g_data->nb_client)
		if (pthread_create(&g_data->clust.client_l[i].thread, NULL, recv_work, \
					&g_data->clust.client_l[i]))
			exit_cause("error: pthread_create(): Failed");
	i = -1;
	while (++i < g_data->nb_client)
		if (pthread_join(g_data->clust.client_l[i].thread, NULL))
			exit_cause("error: pthread_join(): Failed");
	if (g_data->filter != FILTER_STEREO)
		if (pthread_join(thread, NULL))
			exit_cause("error: pthread_join(): Failed");
	put_pixelbuf_to_widget(g_data->img, NULL);
	gtk_widget_show_all(g_data->win);
}
