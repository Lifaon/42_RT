/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:28:12 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/18 17:05:46 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content, int id)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->id = 0;
	}
	else
	{
		list->content = content;
		list->id = id;
	}
	list->next = NULL;
	return (list);
}
