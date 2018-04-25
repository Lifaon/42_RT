/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 02:00:04 by pmiceli           #+#    #+#             */
/*   Updated: 2018/04/22 19:37:14 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_atoi_base(char const *str, char *base)
{
	int		val;
	int		i;
	int		sign;
	int		base_len;
	int		digit;

	val = 0;
	sign = 1;
	base_len = ft_strlen(base);
	i = 0;
	while (ft_isdigit(str[i]) == 0)
		i++;
	sign = (str[i - 1] == '-') ? -1 : 1;
	sign = (sign == 1 && str[i - 3] == '-') ? -1 : 1;
	while (str[i] && ft_strchr(base, ft_toupper(str[i])) != NULL)
	{
		digit = ft_toupper(str[i]);
		digit = (str[i] >= 'A') ? digit - 'A' + 10 : digit - '0';
		if (digit >= 0 && digit < base_len)
			val = val * base_len + digit;
		i++;
	}
	return (sign * val);
}
