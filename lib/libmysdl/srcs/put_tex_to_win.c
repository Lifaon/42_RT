/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tex_to_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:34:17 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/20 14:10:09 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

void	put_tex_to_win(t_texture *tex, SDL_Renderer *ren)
{
	SDL_UpdateTexture(tex->sdl_tex, NULL, tex->tab_pxl,
			tex->size->x * sizeof(uint32_t));
	SDL_RenderCopy(ren, tex->sdl_tex, NULL, NULL);
	SDL_RenderPresent(ren);
}
