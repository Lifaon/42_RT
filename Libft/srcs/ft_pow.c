/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 18:37:40 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/10 19:01:22 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double x, int n)
{
	double nb;

	if (n == 0)
		return (1);
	if (n > 0)
	{
		nb = x;
		while (n-- > 1)
			nb *= x;
	}
	else
	{
		nb = 1;
		while (n++ < 0)
			nb /= x;
	}
	return (nb);
}
