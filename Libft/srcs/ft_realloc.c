/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:41:43 by mlantonn          #+#    #+#             */
/*   Updated: 2017/12/12 19:24:13 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

void	*ft_realloc(void *ptr, size_t old, size_t size)
{
	void *cpy;

	if (!(cpy = ft_memalloc(size)))
	{
		ft_memdel(&ptr);
		return (NULL);
	}
	ft_memcpy(cpy, ptr, old);
	ft_memdel(&ptr);
	return (cpy);
}
