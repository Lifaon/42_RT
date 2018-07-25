/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:32:29 by pmiceli           #+#    #+#             */
/*   Updated: 2018/07/25 14:51:37 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "draw.h"

static void		configure_sin(struct sockaddr_in *sin, char *hostserver)
{
	struct hostent		*hp;

	if ((hp = gethostbyname(hostserver)) == 0)
		exit_cause("error: gethostbyname: Host not found");
	sin->sin_addr = *(struct in_addr *)(hp->h_addr_list[0]);
	sin->sin_family = AF_INET;
	sin->sin_port = htons(PORT);
}

void			init_client(char *av)
{
	struct sockaddr_in		sin;
	SOCKET					sock;
//	char					buff[2];
	fd_set					readfs;

	sock = socket(PF_INET, SOCK_STREAM, 0);
	configure_sin(&sin, av);
	if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) == SOCKET_ERROR)
		exit_cause("impossible de se connecter");
	ft_putstr("connection à : ");
	ft_putstr_color(inet_ntoa(sin.sin_addr), "yellow");
	ft_putstr(" sur le port ");
	ft_putnbr_endl(htons(sin.sin_port));
//	recv(sock, (char*)buff, sizeof(char) * 2, 0);
//	g_data->x = buff[0];
//	g_data->nb_client = buff[1];
	g_data->clust.sock = sock;
}
