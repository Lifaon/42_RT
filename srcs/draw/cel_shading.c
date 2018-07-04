/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cel_shading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 03:38:24 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/04 20:29:17 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#define KERN_SIZE 9

static void	cel_colors(float *edges, uint32_t *dst, uint32_t *src, t_point size)
{
	t_point crd;
	int		i;

	i = 0;
	crd.y = -1;
	while(++crd.y < size.y)
	{
		crd.x = -1;
		while (++crd.x < size.x)
		{
			if (edges[i] == 1.)
				dst[i] = 0xFF000000;
			else
				dst[i] = src[i];
			++i;
		}
	}
}

void		cel_shading(void)
{
	uint32_t	*src;
	uint32_t	*ptr;
	t_point		size;
	float		*edges;

	size.x = g_data->img->size.x;
	size.y = g_data->img->size.y;
	if (!(edges = (float *)malloc(sizeof(float) * size.x * size.y)))
		return ;
	if (!(src = (uint32_t *)malloc(32 * size.x * size.y)))
	{
		free(edges);
		return ;
	}
	draw_edge_image(edges, g_data->img->pxl, size);
	ptr = g_data->img->pxl;
	g_data->img->pxl = src;
	draw_image();
	g_data->img->pxl = ptr;
	cel_colors(edges, g_data->img->pxl, src, size);
	free(src);
	free(edges);
}
