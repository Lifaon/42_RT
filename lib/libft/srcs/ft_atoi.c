/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:29:36 by pmiceli           #+#    #+#             */
/*   Updated: 2018/04/22 19:30:04 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char const *str)
{
	int		val;
	int		i;
	int		sign;

	i = 0;
	val = 0;
	while (ft_isdigit(str[i]) == 0)
		i++;
	sign = (str[i - 1] == '-') ? -1 : 1;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
		val = val * 10 + (str[i++] - '0');
	return (sign * val);
}
