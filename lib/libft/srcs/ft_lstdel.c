/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:10:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 14:53:54 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *))
{
	t_list		*list;
	t_list		*tmp;

	if (alst && del && *alst)
	{
		list = *alst;
		tmp = list;
		while (list)
		{
			tmp = tmp->next;
			del(list->content);
			free(list);
			list = NULL;
			list = tmp;
		}
		*alst = NULL;
	}
}
