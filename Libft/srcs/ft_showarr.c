/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:56:38 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/27 17:48:03 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_showarr(char **tab)
{
	if (tab == NULL)
		return ;
	while (*tab != NULL)
		ft_putendl(*tab++);
}
