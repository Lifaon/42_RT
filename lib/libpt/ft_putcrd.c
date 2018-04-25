/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 20:14:03 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:37:42 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"
#include "libft.h"

void	ft_putcrd(t_point crd)
{
	ft_putstr("x = ");
	ft_putnbr(crd.x);
	ft_putstr("  y = ");
	ft_putnbr(crd.y);
	ft_putchar('\n');
}
