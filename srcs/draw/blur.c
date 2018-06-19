/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 01:49:50 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/19 18:52:35 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#define KERN_SIZE 25

static void	fill_kernel(t_color *copy, t_point crd, t_color kernel[KERN_SIZE])
{
	int		i;
	t_point	new;
	t_color	current;

	i = -1;
	new.y = -3;
	while (++new.y < 3)
	{
		new.x = -3;
		while (++new.x < 3)
		{
			if ((new.x < 0 && crd.x < 2) ||
				(new.x > 0 && crd.x > WIN_W - 3) ||
				(new.y < 0 && crd.y < 2) ||
				(new.y > 0 && crd.y > WIN_H - 3))
				current = copy[crd.x + crd.y * WIN_W];
			else
				current = copy[(crd.x + new.x) + ((crd.y + new.y) * WIN_W)];
			kernel[++i] = current;
		}
	}
}

static int	gaussian_blur(t_color *copy, t_point crd, t_color kernel[KERN_SIZE])
{
	int	r;
	int	g;
	int	b;
	int	a;
	int	i;

	fill_kernel(copy, crd, kernel);
	r = 0;
	g = 0;
	b = 0;
	a = 0;
	i = -1;
	while (++i < KERN_SIZE)
	{
		r += kernel[i].argb.r;
		g += kernel[i].argb.g;
		b += kernel[i].argb.b;
		a += kernel[i].argb.a;
	}
	return ((t_color){.argb.r = r / 25, .argb.g = g / 25, \
		.argb.b = b / 25, .argb.a = a / 25}.c);
}

static void	copy_colors(t_color *copy, uint32_t *src, int size)
{
	int		i;

	i = 0;
	while (i < size - 10)
	{
		copy[i].c = src[i];
		copy[i + 1].c = src[i + 1];
		copy[i + 2].c = src[i + 2];
		copy[i + 3].c = src[i + 3];
		copy[i + 4].c = src[i + 4];
		copy[i + 5].c = src[i + 5];
		copy[i + 6].c = src[i + 6];
		copy[i + 7].c = src[i + 7];
		copy[i + 8].c = src[i + 8];
		copy[i + 9].c = src[i + 9];
		i += 10;
	}
	while (i < size)
	{
		copy[i].c = src[i];
		++i;
	}
}

void		blur(t_data *data)
{
	t_color		*copy;
	t_point		crd;
	t_color		kernel[KERN_SIZE];

	if (!(copy = (t_color *)malloc(32 * WIN_H * WIN_W)))
	{
		perror("Error : ");
		exit_all(data);
	}
	copy_colors(copy, data->img->pxl, WIN_W * WIN_H);
	crd.y = -1;
	while (++crd.y < WIN_H)
	{
		crd.x = -1;
		while (++crd.x < WIN_W)
			pt_to_pixelbuf(crd, data->img, gaussian_blur(copy, crd, kernel));
	}
	free(copy);
}
