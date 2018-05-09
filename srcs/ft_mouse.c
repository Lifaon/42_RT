/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:15:31 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/03 19:42:11 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_mouse(int x, int y, t_data *data)
{
	if (data)
	{
		ft_putstr("mouse move x = ");
		ft_putnbr(x);
		ft_putstr(" y = ");
		ft_putnbr(y);
		ft_putchar('\n');
	}
	return (0);
}