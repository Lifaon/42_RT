/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 01:49:50 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/14 22:56:07 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#define FOCAL_DIST 3000.
#define FOCAL_COEFF .005

static void	fill_kernel(t_color *copy, t_point crd, t_vec kernel[9])
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
			++i;
			if ((new.x < 0 && crd.x < 2) ||
				(new.x > 0 && crd.x > WIN_W - 3) ||
				(new.y < 0 && crd.y < 2) ||
				(new.y > 0 && crd.y > WIN_H - 3))
				current = copy[crd.x + crd.y * WIN_W];
			else
				current = copy[(crd.x + new.x) + ((crd.y + new.y) * WIN_W)];
			kernel[i].x = current.argb.r;
			kernel[i].y = current.argb.g;
			kernel[i].z = current.argb.b;
		}
	}
}

static int	gaussian_blur(t_color *copy, t_point crd)
{
	t_vec	kernel[25];
	t_vec	added;
	t_color	ret;
	float	coeff;
	int		i;

	fill_kernel(copy, crd, kernel);
	added = (t_vec){0, 0, 0};
	coeff = 1. / 25.;
	i = -1;
	while (++i < 25)
		added = vec_add(added, vec_multiply(kernel[i], coeff));
	ret.argb.r = added.x;
	ret.argb.g = added.y;
	ret.argb.b = added.z;
	return (ret.c);
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

	if (!(copy = (t_color *)malloc(32 * WIN_H * WIN_W)))
	{
		perror("Error : ");
		exit_all(data);
	}
	copy_colors(copy, data->tex->tab_pxl, WIN_W * WIN_H);
	crd.y = -1;
	while (++crd.y < WIN_H)
	{
		crd.x = -1;
		while (++crd.x < WIN_W)
			pt_to_tex(crd, data->tex, gaussian_blur(copy, crd));
	}
	free(copy);
}
