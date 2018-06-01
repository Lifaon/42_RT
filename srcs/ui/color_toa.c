/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_toa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 22:32:46 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/01 20:30:47 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"

static char		*write_uint8(char *str, uint8_t nb, size_t *index)
{
	if (nb == 0)
		str[--*index] = '0';
	while (nb)
	{
		str[--*index] = '0' + (nb % 10);
		nb /= 10;
	}
	return (str);
}

char			*color_toa(char *str, t_color color)
{
	size_t			size;
	size_t			cpy_size;
	unsigned int	nb;
	char			*dst;

	size = size_color(color);
	cpy_size = size;
	str[--size] = ']';
	str = write_uint8(str, color.argb.a, &size);
	str[--size] = ' ';
	str[--size] = ',';
	str = write_uint8(str, color.argb.b, &size);
	str[--size] = ' ';
	str[--size] = ',';
	str = write_uint8(str, color.argb.g, &size);
	str[--size] = ' ';
	str[--size] = ',';
	str = write_uint8(str, color.argb.r, &size);
	str[--size] = '[';
	str += cpy_size;
	return (str);
}
