/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:49:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/20 19:27:22 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <time.h>
#include "libft.h"

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

static int ft_exit(void)
{
	ft_putendl("Usage : ./rt \'file_name\'");
	return (0);
}

void		draw_image_sdl(t_data *data);

int		main(int ac, char **av)
{
	if (ac != 2 || ft_strlen(av[1]) < 1)
		return (ft_exit());
	g_data = data_init(ac, av);
	get_oc();
	gtk_init(&ac, &av);
	if (create_ui() == 0)
		return (0);
	//g_data->aa = 4;
	//g_data->px = 0;
	put_gdk_image();
	//print_parsed_data(data);*/
	ft_event(g_data);
	return (0);
}
