/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:46:17 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/17 05:12:44 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_is_base(char *nbr, char *base)
{
	int		i;

	i = 0;
	while (nbr[i])
	{
		if (ft_strchr(base, ft_toupper(nbr[i])) == NULL)
			return (0);
		i++;
	}
	return (1);
}
