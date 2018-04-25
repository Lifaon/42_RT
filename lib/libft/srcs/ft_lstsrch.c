/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsrch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:37:56 by fchevrey          #+#    #+#             */
/*   Updated: 2018/03/06 13:40:54 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstsrch(t_list *lst, int id)
{
	t_list		*cpy;

	if (!lst)
		return (NULL);
	cpy = lst;
	while (cpy)
	{
		if (cpy->id == id)
			return (cpy);
		cpy = cpy->next;
	}
	return (NULL);
}
