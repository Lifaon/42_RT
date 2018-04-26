/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_tex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:37:39 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/20 14:06:17 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmysdl.h"

void	free_all_tex(t_list **texs)
{
	t_list		*lst;
	t_list		*lst_n;
	t_texture	*tex;

	if (!texs || !(*texs))
		return ;
	lst = *texs;
	while (lst)
	{
		lst_n = lst->next;
		tex = (t_texture*)lst->content;
		free_tex(&tex);
		free(lst);
		lst = lst_n;
	}
}
