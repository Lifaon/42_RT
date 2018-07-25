/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_host.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:32:32 by pmiceli           #+#    #+#             */
/*   Updated: 2018/07/25 15:03:28 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "clust.h"

//penser a proteger les send / recv //a

static void		print_wait(char *host)
{
	ft_putstr("Patientez pendant que le(s) client(s) se connecte(nt) sur ");
	ft_putendl_color(host, "yellow");
}

static void		print_host(void)
{
	struct ifaddrs		*ifaddr; 
	struct ifaddrs		*ifa;
	int					family;
	int					s;
	char				host[NI_MAXHOST];

	ft_putstr("La socket ");
	ft_putnbr(g_data->clust.sock);
	ft_putendl(" est maintenant ouverte en mode TCP/IP\n");
	if (getifaddrs(&ifaddr) == -1)
		perror("getifaddrs");
	ifa = ifaddr;
	while (ifa != NULL)
	{
		family = ifa->ifa_addr->sa_family;
		if (family == AF_INET)
		{
			s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), \
					host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
			if (ft_strcmp(ifa->ifa_name, "en0") == 0)
				print_wait(host);
		}
		ifa = ifa->ifa_next;
	}
	freeifaddrs(ifaddr);
}

static void		add_client_to_ll(char *map, int cpt)
{
	socklen_t		crecsize;
	char			buff[2];

	crecsize = sizeof(g_data->clust.sin);
	g_data->clust.client_l[cpt].csock = accept(g_data->clust.sock,
			(struct sockaddr *)&g_data->clust.client_l[cpt].csin, &crecsize);
	ft_putstr("un client se connecte avec la socket ");
	ft_putnbr(g_data->clust.client_l[cpt].csock);
	ft_putstr(" de ");
	ft_putstr(inet_ntoa(g_data->clust.client_l[cpt].csin.sin_addr));
	ft_putchar(':');
	ft_putnbr_endl(htons(g_data->clust.client_l[cpt].csin.sin_port));
//	g_data->clust.client_l[cpt].x = cpt + 1;
//	g_data->clust.client_l[cpt].nb_client = g_data->nb_client;
//	buff[0] = g_data->clust.client_l[cpt].x;
//	buff[1] = g_data->clust.client_l[cpt].nb_client;
//	send(g_data->clust.client_l[cpt].csock, (char*)buff, sizeof(char) * 2, 0);
	send_data(g_data->clust.client_l[cpt].csock, cpt);
}

static void		configure_sockaddr_server(struct sockaddr_in *sin)
{
	sin->sin_addr.s_addr = htonl(INADDR_ANY);
	sin->sin_family = AF_INET;
	sin->sin_port = htons(PORT);
}

void			init_host(char *map)
{
	int			on;
	socklen_t	crecsize;
	int			cpt;
	t_client	*tmp;

	crecsize = sizeof(g_data->clust.sin);
	g_data->clust.sock = socket(PF_INET, SOCK_STREAM, 0);
	print_host();
	configure_sockaddr_server(&g_data->clust.sin);
	on = 1;
	setsockopt(g_data->clust.sock, SOL_SOCKET,
			SO_REUSEADDR, (char *)&on, sizeof(int));
	bind(g_data->clust.sock, (struct sockaddr*)&g_data->clust.sin,
			sizeof(g_data->clust.sin));
	ft_putstr("Listage du port ");
	ft_putnbr_endl(PORT);
	listen(g_data->clust.sock, NB_CLIENT_MAX);
	cpt = 0;
	if (!(g_data->clust.client_l = (t_client*)malloc(sizeof(t_client) * g_data->nb_client)))
		exit_cause("malloc error");
	while (cpt < g_data->nb_client)
	{
		ft_putstr("En attente que ");
		ft_putnbr(g_data->nb_client - cpt);
		ft_putendl(" client(s) se connecte(nt)...");
		add_client_to_ll(map, cpt);
		++cpt;
	}
}
