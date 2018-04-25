/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:59:11 by fchevrey          #+#    #+#             */
/*   Updated: 2018/03/06 13:42:46 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd(t_list **alst, t_list *new_elem)
{
	if (alst != NULL && new_elem != NULL)
	{
		new_elem->next = *alst;
		*alst = new_elem;
	}
}
