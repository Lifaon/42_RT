/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:32:22 by pmiceli           #+#    #+#             */
/*   Updated: 2018/07/24 18:06:32 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "draw.h"

static int			buf_to_int(char *buf)
{
	int				i;
	int				n;

	n = 0;
	i = -1;
	while (++i < 4)
	{
		n <<= 8;
		n |= buf[i] & 0xFF;
	}
	return n;
}

static void			recv_data(int sock)
{
	char	*json;
	int		size_json;
	char	tmp[4];
	char	buf2;
	char	buff[5];

	if (recv(sock, &buf2, sizeof(char) * 1, 0) < 0)
		exit_cause("recv fail");
	if (buf2 != 'a')
		exit_all(g_data);
	if (recv(sock, (char*)tmp, sizeof(char) * 4, 0) < 0)
		exit_cause("recv fail");
	size_json = buf_to_int(tmp);
	printf("--%d--\n", size_json);
	if (!(json = (char*)malloc(sizeof(char) * size_json)))
		exit_cause("malloc error");
	if (recv(sock, (char*)json, sizeof(char) * size_json, 0) < 0)
		exit_cause("recv fail");
	ft_putendl(json);
	parse_for_client(g_data, json);
	if (recv(sock, (char*)buff, sizeof(char) * 5, 0) < 0)
		exit_cause("recv fail");
	g_data->aa = buff[0];
	g_data->cel_shading = buff[1];
	g_data->px = buff[2];
	g_data->filter = buff[3];
	g_data->depth_of_field = buff[4];
}

static void		chose_draw(void)
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
}

void			client_work(void)
{
	int			ret;
	int			size;

	size = WIN_W * (WIN_H);
	if(!(g_data->cimg = (uint32_t*)ft_memalloc(sizeof(uint32_t) * size)))
		exit_cause("malloc error");
	while (1)
	{
		recv_data(g_data->clust.sock);
		get_oc();
		chose_draw();
		ret = 0;
		ft_putendl_color("sending", "orange");
		while (ret < WIN_H * WIN_W * sizeof(int))
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
