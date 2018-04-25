/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:35:49 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 19:17:03 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint32_t	get_color(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue)
{
	uint32_t color;

	color = alpha;
	color = (color * 256) + red;
	color = (color * 256) + green;
	color = (color * 256) + blue;
	return (color);
}
