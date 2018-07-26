/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:32:22 by pmiceli           #+#    #+#             */
/*   Updated: 2018/07/26 01:56:29 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "draw.h"

static void		free_data(void)
{
	if (g_data && g_data->nb_objects)
		free(g_data->objs);
	if (g_data && g_data->nb_lights)
		free(g_data->lights);
	g_data->nb_objects = 0;
	g_data->nb_lights = 0;
}

static void		recv_data(int sock)
{
	char	*json;
	int		size_json;
	char	tmp[4];
	char	buf2;

	free_data();
	if (recv(sock, &buf2, sizeof(char) * 1, 0) < 0)
		exit_cause("recv fail");
	if (buf2 != 'a')
		exit_all(g_data);
	buf2 = 'A';
	if (send(sock, &buf2, sizeof(char) * 1, 0) < 0)
		exit_cause("send fail");
	if (recv(sock, (char*)tmp, sizeof(char) * 4, 0) < 0)
		exit_cause("recv fail");
	size_json = buf_to_int(tmp);
	if (!(json = (char*)ft_memalloc(sizeof(char) * (size_json + 1))))
		exit_cause("malloc error");
	json[size_json] = '\0';
	if ((recv(sock, (char*)json, size_json, 0)) < 0)
		exit_cause("recv fail");
	parse_for_client(g_data, json);
}

static void		chose_draw(void)
{
	if (g_data->caustic_flag && !g_data->photon_map)
		get_photon_map();
	else if (!g_data->caustic_flag && g_data->photon_map)
	{
		free(g_data->photon_map);
		g_data->photon_map = NULL;
	}
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
}

static void		check_host_status(int sock)
{
	char		buf;

	buf = '0';
	printf("in check_host_status\n");
	if (recv(sock, &buf, sizeof(char), 0) < 0)
		exit_cause("recv error");
	printf("--%c--\n", buf);
	if (buf != 'a')
		exit_all(g_data);
	printf("out check_host_status\n");
}

void			client_work(void)
{
	int			ret;
	int			size;

	size = WIN_W * (WIN_H) + 1;
	if (!(g_data->cimg = (uint32_t*)ft_memalloc(sizeof(uint32_t) * size)))
		exit_cause("malloc error");
	while (1)
	{
		recv_data(g_data->clust.sock);
		check_host_status(g_data->clust.sock);
		get_oc();
		chose_draw();
		ret = 0;
		ft_putendl_color("sending", "orange");
		while (ret < (int)(WIN_H * WIN_W * sizeof(int)))
		{
			ret += send(g_data->clust.sock, ((unsigned char *)g_data->cimg) \
					+ ret, size * sizeof(int) - ret < 1000 ? \
					size * sizeof(int) - ret : 1000, 0);
			if (ret < 0)
				exit_cause("send fail");
		}
		ft_putendl_color("send over", "green");
	}
	free(g_data->cimg);
}
