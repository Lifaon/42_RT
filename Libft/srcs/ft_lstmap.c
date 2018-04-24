/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:08:49 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/27 15:37:57 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*p;

	p = NULL;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (lst)
	{
		new = f(lst);
		lst = lst->next;
		p = new;
	}
	while (lst)
	{
		if (!(new->next = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		new->next = f(lst);
		lst = lst->next;
		new = new->next;
	}
	return (p);
}
