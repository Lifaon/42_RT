/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:08:29 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/29 14:45:04 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmysdl.h"

void		free_win(t_win **win)
{
	if (!win || !*win)
		return ;
	free_all_tex(&(*win)->texs);
	(*win)->texs = NULL;
	if ((*win)->ren != NULL)
		SDL_DestroyRenderer((*win)->ren);
	SDL_DestroyWindow((*win)->ptr);
	free((*win)->size);
	(*win)->size = NULL;
	free(*win);
	*win = NULL;
}
