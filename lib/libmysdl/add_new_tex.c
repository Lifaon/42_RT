/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:50:03 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/20 13:58:38 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

int		add_new_tex(t_point size, SDL_Renderer *ren, t_list **src)
{
	t_texture	*tex;
	t_list		*lst;
	int			id;

	if (!(tex = texture_new(size, ren)))
		return (-1);
	if (!src)
	{
		*src = ft_lstnew(tex, 0);
		return (0);
	}
	lst = *src;
	id = -1;
	while (lst->next)
	{
		if (lst->id >= id)
			id = lst->id + 1;
		lst = lst->next;
	}
	if (!(lst->next = ft_lstnew(tex, id)))
		return (-1);
	return (id);
}
