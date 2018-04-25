/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:00:06 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/13 23:03:22 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab_int(int **tab)
{
	int		j;
	int		k;

	j = 0;
	while (tab[j])
	{
		k = 0;
		while (tab[j][k])
		{
			ft_putnbr(tab[j][k]);
			k++;
		}
		if (tab[j])
			ft_putchar('\n');
		j++;
	}
}
