/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_wheel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:17:35 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/03 19:30:14 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				ft_mouse_wheel(int y, t_data *data)
{
	if (data)
	{
		ft_putstr("Wheel y = ");
		ft_putnbr(y);
		ft_putchar('\n');
	}
	return (0);
}
