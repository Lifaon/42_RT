/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:33:03 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 19:28:38 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ui.h"

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

char			*strcpy_color(char *str, t_color color)
{
	size_t			size;
	size_t			cpy_size;

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
