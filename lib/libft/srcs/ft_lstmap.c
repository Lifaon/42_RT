/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:24:44 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 14:55:18 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dst;
	t_list	*tempo;

	if (!(dst = ft_lstnew(NULL, 0)))
		return (NULL);
	dst = f(lst);
	tempo = dst;
	while (lst->next)
	{
		tempo->next = f(lst->next);
		if (tempo->next == NULL)
			return (NULL);
		lst = lst->next;
		tempo = tempo->next;
	}
	return (dst);
}
