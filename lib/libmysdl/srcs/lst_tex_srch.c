/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tex_srch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:40:26 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/20 14:08:15 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

t_texture		*lst_tex_srch(t_list *lst, int id)
{
	t_list		*item;
	t_texture	*tex;

	item = ft_lstsrch(lst, id);
	if (!item || !(item->content))
		return (NULL);
	tex = (t_texture*)item->content;
	return (tex);
}
