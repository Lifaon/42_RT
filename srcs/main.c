/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:49:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/02 21:51:30 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ui.h"
#include <time.h>//

void			get_time(void)
{
	static int						time;
	static struct timespec			last;
	struct timespec					tmptime;

	if (!last.tv_nsec)
		clock_gettime(CLOCK_MONOTONIC_RAW, &last);

	clock_gettime(CLOCK_MONOTONIC_RAW, &tmptime);
	if (time != 0)
	{
		printf("temps de calcul : %f seconde\n", \
				((tmptime.tv_sec - last.tv_sec) * 1000000000 + \
				 (tmptime.tv_nsec - last.tv_nsec)) * pow(10, -9));
	}
	time++;
}

static void		check_argv(int argc, char **argv, t_data *data)
{
	int		i;
	int		cluster;

	cluster = 0;
	i = 0;
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "-host") == 0)
		{
			printf("server\n");
			if (cluster == 1)
				exit_cause("cannot have -host and -client running as the same time");
			cluster = 1;
			init_host(data);
		}
		if (ft_strcmp(argv[i], "-client") == 0)
		{
			printf("client\n");
			if (cluster == 1)
				exit_cause("cannot have -host and -client running as the same time");
			cluster = 1;
			if (!(argv[++i]))
				exit_cause("no ip address found\nUsage : -client -ip_addr\n");
			if (inet_addr(argv[i]) == INADDR_NONE)
				exit_cause("ip address not well formatted\nUsage : [...] -client -ip_addr\n");
			client(data, argv[i]);
		}
	}
}

static int ft_exit(void)
{
	ft_putendl("Usage : ./rt \'file_name\'");
	return (0);
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 1)
		return (ft_exit());
	g_data = data_init(ac, av);
	while(++i < ac)
	{
		if (ft_strstr(av[i], ".json"))
			break;
	}
	parse(g_data, av[i]);
	check_argv(ac, av, g_data);
	gtk_init(&ac, &av);
	get_oc();
	if (create_ui(av[0]) == 0)
		return (0);
	put_gdk_image();
	ft_event(g_data);
	return (0);
}
