/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 21:48:09 by pmiceli           #+#    #+#             */
/*   Updated: 2018/07/10 01:48:30 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "draw.h"

void client(t_data *data, char *ip)
{
	SOCKET				sock;
	SOCKADDR_IN			sin;
	int					sock_err;

	/* Création de la socket */
	sock = socket(AF_INET, SOCK_STREAM, 0);

	/* Configuration de la connexion */
	sin.sin_addr.s_addr = inet_addr(ip);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORT);

	/* Si le client arrive à se connecter */
	if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
		printf("Connexion à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
	else
		exit_cause("imposible de se connecter");

	char buff[3];
	sock_err = recv(sock, (char*)buff, sizeof(char) * 3, 0);
	TESTS(0);
//	printf("message recu : %s\n", buff);

	char *map_name = ft_strnew(SOCK_BUFF);
	sock_err = recv(sock, (char*)map_name, sizeof(char) * SOCK_BUFF, 0);
	TESTS(1);
//	printf("map name : %s\n", map_name);

	g_data->x = buff[0] - 48;
	g_data->nb_client = buff[2] - 48;
//	printf("x : %d	nb_client : %d\n", g_data->x, g_data->nb_client);
	if(!(g_data->img_clus = (uint32_t*)malloc(sizeof(uint32_t) * (WIN_H * WIN_W))))
		exit(1);
	parse(g_data, map_name);
	get_oc();
	draw_image();
	TEST;
	send(sock, (uint32_t*)g_data->img_clus, sizeof(uint32_t) * (WIN_H * WIN_W), 0);
	TESTS(2);
//	printf("draw finish, send results\n");

	ft_putendl_color("end", "red");
	/* On ferme la socket précédemment ouverte */
	closesocket(sock);
	exit(1);
}
