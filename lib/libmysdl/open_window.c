/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:02:46 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 19:41:42 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL2/SDL.h"
#include <unistd.h>
#include "../includes/libft.h"

//la lib se trouve dans /Users/fchevrey/.brew/Cellar/sdl2/2.0.8/lib/:w

int		main(int ac, char **av)
{
	char			*name;
	SDL_Window		*fen;
	SDL_Renderer	*ren;

	name = ft_strdup("vide\n");
	if (ac > 1)
	{
		ft_strdel(&name);
		name = ft_strdup(av[1]);
	}
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putstr("BUG\n");
		SDL_Quit();
		return (-1);
	}
	fen = NULL;
	fen = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	//fen = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	//fen = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
	ft_putstr(name);
	if (fen != NULL)
	{
		ren = SDL_CreateRenderer(fen, 0, 0);
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);
		SDL_RenderPresent(ren);
		ft_putstr("we are here");
		SDL_Delay(1000);
		//SDL_SetWindowFullscreen(fen, 0);
		SDL_HideWindow(fen);
		SDL_Delay(1000);
		SDL_ShowWindow(fen);
		SDL_Delay(1000);
		ft_strdel(&name);
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(fen);
	}
	SDL_Quit();
	return (0);
}
