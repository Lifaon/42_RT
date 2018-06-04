/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:27:24 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/04 16:13:40 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	ft_event(t_data *data)
{
	SDL_Event	event;
	int			quit;

	quit = 0;
	while (!quit)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			quit = 1;
		else if (event.type == SDL_KEYDOWN)
			ft_keyboard(event.key.keysym.sym, data);
		else if (event.type == SDL_MOUSEMOTION)
			ft_mouse(event.motion.x, event.motion.y, data);
		else if (event.type == SDL_MOUSEWHEEL)
			ft_mouse_wheel(event.wheel.y, data);
	}
	exit_all(data);
}
