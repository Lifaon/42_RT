/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:19:45 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/27 18:27:16 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *src, size_t n)
{
	char *cpy;

	if (!(cpy = ft_strnew(n)))
		return (NULL);
	ft_strncpy(cpy, src, n);
	cpy[n] = '\0';
	return (cpy);
}
