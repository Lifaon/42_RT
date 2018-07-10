/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 21:48:13 by pmiceli           #+#    #+#             */
/*   Updated: 2018/07/10 02:19:00 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "draw.h"

static void		print_host(void)
{
	struct ifaddrs		*ifaddr; 
	struct ifaddrs		*ifa;
	int					family;
	int					s;
	char				host[NI_MAXHOST];

	if (getifaddrs(&ifaddr) == -1)
		perror("getifaddrs");
	ifa = ifaddr;
	while (ifa != NULL)
	{
		family = ifa->ifa_addr->sa_family;
		if (family == AF_INET)
		{
			s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
			if (s != 0)
				printf("getnameinfo() failed: %s\n", gai_strerror(s));
			if (ft_strcmp(ifa->ifa_name, "en0") == 0)
			{
				ft_putstr("Patientez pendant que le client se connecte sur ");
				ft_putendl_color(host, "yellow");
			}
		}
		ifa = ifa->ifa_next;
	}
	freeifaddrs(ifaddr);
}

void		init_host(t_data *data, char* map)
{
	SOCKADDR_IN			sin;
	SOCKET				sock;
	socklen_t			recsize;
	SOCKADDR_IN			csin;
	SOCKET				csock;
	socklen_t			crecsize;
	fd_set				readfs;
	int					sock_err;
	static int	d = 0;

	recsize = sizeof(sin);
	crecsize = sizeof(csin);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock != INVALID_SOCKET)
	{
		printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);
		sin.sin_addr.s_addr = htonl(INADDR_ANY);
		sin.sin_family = AF_INET;
		sin.sin_port = htons(PORT);
		sock_err = bind(sock, (SOCKADDR*)&sin, recsize);
		if(sock_err != SOCKET_ERROR)
		{
			sock_err = listen(sock, 5);
			printf("Listage du port %d...\n", PORT);
			if(sock_err != SOCKET_ERROR)
			{
				print_host();
				/* creation de l'ensemble de lecture */
		//		while (1)
		//		{
		//			FD_ZERO(&readfs);
		//			FD_SET(sock, &readfs);
					if (select(sock + 1, &readfs, NULL, NULL, NULL) < 0)
						exit_cause("error in select");
					/* on check si le scoket a recu des infos */
		//			if (FD_ISSET(sock, &readfs))
		//			{
						// je pense que je dois faire un tableau de client -> a voir //
					//	if (d == 0)
					//	{
							d = 1;
							csock = accept(sock, (SOCKADDR*)&csin, &crecsize); //bloquant
							printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
							char to_send[3];
							to_send[0] = 48 + 1; //1 va etre le client au quel on envoit l'info //
							to_send[1] = '-';
							to_send[2] = 48 + 2; //2 va etre le nombre de clients //
							sock_err = send(csock, (char*)to_send, sizeof(char) * 3, 0);
							printf("message envoye !\n");
							sock_err = send(csock, (char*)map, sizeof(char*) *ft_strlen(map), 0);
							printf("map_name envoye !\n");
							g_data->x = 0;
							g_data->nb_client = 2; //pour l'instant je le fais avec que un client //
							if (!(g_data->img_clus = (uint32_t*)malloc(sizeof(uint32_t) * (WIN_H * WIN_W))))
								exit(0);
							draw_image();
					//	}
						//	/*
				//			FD_SET(csock, &readfs);
				//		if (FD_ISSET(csock, &readfs))
				//		{
				//		// JE PENSE QUE J'AI FAIS M'IMPORTE QUOI CAR JE SUIS CREVE !!!!! //
							uint32_t *tmp;
							if (!(tmp = (uint32_t*)malloc(sizeof(uint32_t) * ((WIN_H * WIN_W) / g_data->nb_client))))
								exit(0);
							sock_err = recv(csock, (uint32_t*)tmp, sizeof(uint32_t) * ((WIN_H * WIN_W) / g_data->nb_client), 0);
								printf("result recui : %d\n", sock_err);
							int i = 0;
							while (i < (WIN_W * WIN_H) / g_data->nb_client )
							{
								g_data->img_clus[((WIN_W * WIN_H) / 2 + i)] = tmp[i];
								i++;
							}
							i =0;
							while (i < (WIN_H * WIN_W))
							{
								if (g_data->img_clus[i] != 0)
								printf("test de l'espoir sinon dodo : %X\n", g_data->img_clus[i]);
								i++;
							}
				//		}
						//	*/
						//						ft_putendl_color("end", "red");
						//						exit(1);
						if (sock_err != SOCKET_ERROR)
							shutdown(sock, 2);
		//			}
		//		}
			}
			else
				exit_cause("listen");
		}
		else
			exit_cause("bind");

		/* Fermeture de la socket client et de la socket serveur */
		//	printf("Fermeture de la socket client\n");
		//	closesocket(csock);
		/*
		   free(data->img);
		   printf("Fermeture de la socket serveur\n");
		   closesocket(sock);
		   printf("Fermeture du serveur terminée\n");
		   */
	}
}
