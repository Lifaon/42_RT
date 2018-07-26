/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:41:00 by pmiceli           #+#    #+#             */
/*   Updated: 2018/07/26 02:34:01 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:32:36 by pmiceli           #+#    #+#             */
/*   Updated: 2018/07/25 14:40:56 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "draw.h"
#include "ui.h"

static int	send_int(int socket, int n, int flags)
{
	char		data[4];
	int			i;

	i = -1;
	while (++i < 4)
		data[i] = (n >> ((4 - (i + 1)) * 8)) & 0xFF;
	return (send(socket, data, sizeof(char) * 4, flags));
}

int			send_data(int sock, int i)
{
	char		*json;
	size_t		size_json;
	char		buf2;

	size_json = size_of_str_json();
	json = fill_str_json(size_json);
	size_json = ft_strlen(json);
	buf2 = 'a';
	if (send(sock, &buf2, sizeof(char) * 1, 0) < 0)
		exit_cause("send fail");
	if (recv(sock, &buf2, sizeof(char) * 1, 0) < 0)
		exit_cause("recv error");
	if (buf2 != 'A')
	{
//		g_data->nb_client = 0;
		return (i);
	}
	if (send_int(sock, size_json, 0) < 0)
		exit_cause("send fail");
	if ((send(sock, (char*)json, size_json, 0)) < 0)
		exit_cause("send error");
	free(json);
	return (-1);
}

static void	send_status(int ret)
{
	int			i;
	char		status;

	i = -1;
	status = ret == -1 ? 'a' : 'd';
	printf("in send_status : %c\n", status);
	while (++i < g_data->nb_client)
	{
		printf("i : %d\tret : %d\n", i, ret);
		if (i != ret)
		{
			printf("send\n");
			if (send(g_data->clust.client_l[i].csock, &status, \
						sizeof(char), 0) < 0)
				exit_cause("send error");
		}
	}
	if (status == 'd')
		g_data->nb_client = 0;
	printf("out send_status : %c\n", status);
}

int			send_data_to_client(void)
{
	int			i;
	int			ret;

	i = 0;
	while (i < g_data->nb_client)
	{
		ret = send_data(g_data->clust.client_l[i].csock, i);
		i++;
	}
	send_status(ret);
	return (g_data->nb_client);
}
