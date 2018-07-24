/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:49:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/24 17:08:05 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ui.h"
#include <time.h>

void						get_time(void)
{
	static int				time;
	static struct timespec	last;
	struct timespec			tmptime;

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

static int					ft_exit(void)
{
	ft_putendl("Usage : ./rt \'file_name\'");
	return (0);
}

int							main(int ac, char **av)
{
	if (ac != 2 || ft_strlen(av[1]) < 1)
		return (ft_exit());
	g_data = data_init(ac, av);
	gtk_init(&ac, &av);
	parse(g_data, av[1]);
	get_oc();
	if (create_ui() == 0)
		return (0);
	put_gdk_image();
	ft_event(g_data);
	return (0);
}
