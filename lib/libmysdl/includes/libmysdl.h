/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmysdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:29:02 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/20 14:42:36 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMYSDL_H
# define LIBMYSDL_H
# include "libpt.h"
# include "libft.h"
//# include "SDL2/SDL.h"
# include "SDL.h"
# include <stdint.h>

typedef struct		s_texture
{
	uint32_t		*tab_pxl;
	SDL_Texture		*sdl_tex;
	t_point			*size;
}					t_texture;

typedef struct		s_win
{
	SDL_Window		*ptr;
	t_point			*size;
	t_list			*texs;
	SDL_Renderer	*ren;
}					t_win;

uint32_t			get_color(uint8_t alpha, uint8_t red, uint8_t green,
		uint8_t blue);
t_win				*win_new(t_point size, char *title);
t_texture			*texture_new(t_point size, SDL_Renderer *ren);
t_texture			*lst_tex_srch(t_list *lst, int id);
t_list				*lst_tex_new(t_point size, SDL_Renderer *ren, int id);
int					add_new_tex(t_point size, SDL_Renderer *ren, t_list **src);
void				free_tex(t_texture **tex);
void				free_win(t_win **win);
void				free_all_tex(t_list **texs);
void				pt_to_tex(t_point pt, t_texture *tex, uint32_t color);
void				trace_line_tex(t_point pt1, t_point pt2, t_texture *tex,
		uint32_t color);
void				fill_tex_in_color(t_texture *tex, uint32_t color);
void				put_tex_to_win(t_texture *tex, SDL_Renderer *ren);

#endif
