/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:31:01 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/20 20:13:59 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ui.h"

char	*my_strcopy(char *dest, char const *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		*dest = src[i];
		dest++;
		i++;
	}
	return (dest);
}
