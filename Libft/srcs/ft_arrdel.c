/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:16:05 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/27 18:05:56 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

void	ft_arrdel(char ***tab)
{
	char **tmp;

	if (!tab || !*tab)
		return ;
	tmp = *tab;
	while (*tmp)
		free(*tmp++);
	free(*tab);
	*tab = NULL;
}
