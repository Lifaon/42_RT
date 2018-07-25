/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:49:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/25 23:37:49 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ui.h"

static void	check_argv(int argc, char **argv, t_data *data, char* map)
{
	int		i;

	g_data->clust_i = CLUST_NONE;
	i = 0;
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "-host") == 0)
		{
			printf("server\n");
			if (g_data->clust_i != CLUST_NONE)
				exit_cause("cannot have -host and -client running as the same time");
			g_data->clust_i = CLUST_HOST;
			if (!(argv[++i]))
				exit_cause("nomber of client undefined\nUsage : -host 'nb client'");
			g_data->nb_client = ft_atoi(argv[i]);
			g_data->clust.nb_client_for_free = g_data->nb_client;
			if (g_data->nb_client <= 0)
				exit_cause("cannot have a null or negative nomber of client");
			g_data->x = 0;
			parse(g_data, map);
			init_host(map);
		}
		if (ft_strcmp(argv[i], "-client") == 0)
		{
			printf("client\n");
			if (g_data->clust_i != CLUST_NONE)
				exit_cause("cannot have -host and -client running as the same time");
			g_data->clust_i = CLUST_CLIENT;
			if (!(argv[++i]))
				exit_cause("no ip address found\nUsage : -client 'ip_addr'\n");
			if (inet_addr(argv[i]) == INADDR_NONE)
				exit_cause("ip address not well formatted\nUsage : -client 'ip_addr'\n");
			init_client(argv[i]);
			client_work();
		}
	}
	if (g_data->clust_i == CLUST_NONE)
	{
		g_data->x = 0;
		g_data->nb_client = 0;
	}
}

static int ft_exit(void)
{
	ft_putendl("Usage : ./rt 'file_name' -host 'nb clients' -client 'IP host'");
	ft_putendl("        -host must have the nomber of clients");
	ft_putendl("        -client must have the IP of the host");
	ft_putendl("        -host and -client can't be actived at the same time");
	return (0);
}

int			main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 1)
		return (ft_exit());
	g_data = data_init(av);
	gtk_init(&ac, &av);
	if (create_ui() == 0)
		exit_all(g_data);
	while(++i < ac)
	{
		if (ft_strstr(av[i], ".json"))
			break;
	}
	check_argv(ac, av, g_data, av[i]);
	if (g_data->clust_i == CLUST_NONE)
		parse(g_data, av[i]);
	if (g_data->clust_i != CLUST_CLIENT)
	{
		get_oc();
		if (g_data->clust_i == CLUST_HOST)
			host_work(0);
		else
			put_gdk_image();
		ft_event(g_data);
	}
	return (0);
}
