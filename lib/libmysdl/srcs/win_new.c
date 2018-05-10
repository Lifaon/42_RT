/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:15:47 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/10 03:17:24 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmysdl.h"

t_win		*win_new(t_point size, char *title)
{
	t_win		*info;

	if (!(info = (t_win*)malloc(sizeof(t_win))))
		return (NULL);
	if (!(info->ptr = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, size.x, size.y, 0)))
	{
		ft_putstr("SDL_CreateWindow error : ");
		ft_putendl(SDL_GetError());
		free(info);
		return (NULL);
	}
	SDL_MaximizeWindow(info->ptr);
	SDL_RestoreWindow(info->ptr);
	if (!(info->size = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	info->texs = NULL;
	info->ren = NULL;
	info->size->x = size.x;
	info->size->y = size.y;
	return (info);
}
