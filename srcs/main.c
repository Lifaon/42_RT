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

static int	ft_exit(void)
{
	ft_putendl("Usage : ./rt \'file_name\'");
	return (0);
}

int			main(int ac, char **av)
{
	if (ac != 2 || ft_strlen(av[1]) < 1)
		return (ft_exit());
	g_data = data_init(av);
	gtk_init(&ac, &av);
	parse(g_data, av[1]);
	get_oc();
	if (create_ui() == 0)
		return (0);
	put_gdk_image();
	ft_event(g_data);
	return (0);
}
