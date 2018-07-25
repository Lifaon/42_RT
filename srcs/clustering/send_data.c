/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:41:00 by pmiceli           #+#    #+#             */
/*   Updated: 2018/07/25 19:36:30 by pmiceli          ###   ########.fr       */
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

static char		*itoa_spe(int nb)
{
	int		i;
	char	*s;

	i = 10;
	if (!(s = (char*)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	s = (char*)ft_memset(s, 'c', 10);
	s[i] = '\0';
	if (nb == 0)
	{
		s[0] = 48;
		return (s);
	}
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		s[--i] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (s);
}

static int	send_int(int socket, int n, int flags)
{
	char		data[4];
	int			i;

	i = -1;
	while (++i < 4)
		data[i] = (n >> ((4 - (i + 1)) * 8)) & 0xFF;
	return (send(socket, data, sizeof(char) * 4, flags));
}

int		send_data(int sock, int i)
{
	ft_putendl_color("send data", "yellow");
	char		*json;
	size_t		size_json;
	int			ret;
	char		buf2;

	size_json = size_of_str_json();
	json = fill_str_json(size_json);
	size_json = ft_strlen(json);
	buf2 = 'a';
	if (send(sock, &buf2, sizeof(char) * 1, 0) < 0)
		exit_cause("send fail");
	if (recv(sock, &buf2, sizeof(char) * 1, 0) < 0)
		exit_cause("recv error");
	printf("--%c--\n", buf2);
	if (buf2 != 'A')
	{
		g_data->nb_client = 0;
		return (0);
	}
	printf("i : %d\tnb_client : %d\n", i+1, g_data->nb_client);
	if (send_int(sock, size_json, 0) < 0)
		exit_cause("send fail");
	if (send(sock, (char*)json, sizeof(char) * size_json, 0) < 0)
		exit_cause("send fail");
	free(json);
	return (g_data->nb_client);
}

int		send_data_to_client(void)
{
	int			i;

	i = 0;
	while (i < g_data->nb_client)
	{
		send_data(g_data->clust.client_l[i].csock, i);
		i++;
	}
	return (g_data->nb_client);
}
