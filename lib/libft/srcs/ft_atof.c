/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 22:59:26 by pmiceli           #+#    #+#             */
/*   Updated: 2018/04/22 19:24:43 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_atof(char const *str)
{
	float		n;
	int			i;
	int			k;
	double		signe;

	i = 0;
	n = 0;
	k = 0;
	if (!str)
		return (0);
	while (ft_isdigit(str[i]) == 0)
		i++;
	signe = (str[i - 1] == '-') ? -1 : 1;
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i++] - 48);
		if (str[i] == '.')
			k = i++;
	}
	while (k != 0 && str[++k])
		signe = signe * 10.0;
	return (n / signe);
}
