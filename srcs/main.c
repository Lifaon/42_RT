/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:49:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/29 15:44:46 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		ft_putstr("SDL_Init error :");
		ft_putendl(SDL_GetError());
		return (0);
	}
	g_data = data_init(ac, av);
	gtk_init(&ac, &av);
	if (create_ui() == 0)
		return (0);
	draw_image(g_data);
	//print_parsed_data(data);*/
	ft_event(g_data);
	return (0);
}
