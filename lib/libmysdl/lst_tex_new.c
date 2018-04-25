/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tex_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:22:26 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/20 14:22:31 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

t_list		*lst_tex_new(t_point size, SDL_Renderer *ren, int id)
{
	t_texture	*tex;
	t_list		*lst;

	tex = texture_new(size, ren);
	lst = ft_lstnew(tex, id);
	return (lst);
}
