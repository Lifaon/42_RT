/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:49:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/04 16:23:24 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_data	data;

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		ft_putstr("SDL_Init error : ");
		ft_putendl(SDL_GetError());
		return (0);
	}
	data_init(&data, ac, av);
	draw_image(&data);
	ft_event(&data);
	return (0);
}
