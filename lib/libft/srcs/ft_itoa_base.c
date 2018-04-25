/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:24:56 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/18 20:34:52 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int nb, char *base)
{
	int		i;
	int		base_int;
	char	*s;

	i = ft_intlen_base(nb, base);
	base_int = ft_strlen(base);
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	if (nb == 0 || nb == -2147483648)
		return (ft_strdup(ft_itoa(nb)));
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		s[--i] = base[(nb % base_int)];
		nb = nb / base_int;
	}
	return (s);
}
