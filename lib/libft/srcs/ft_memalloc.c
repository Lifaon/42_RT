/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:39:24 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/10 12:36:10 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	len;

	len = 0;
	if (size == 0)
		return (NULL);
	if (!(mem = (void*)malloc(size)))
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
