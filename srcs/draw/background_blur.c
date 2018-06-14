/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_blur.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 01:49:50 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/14 16:34:51 by mlantonn         ###   ########.fr       */
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
	while (++new.y <= 2)
	{
		new.x = -3;
		while (++new.x <= 2)
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
	{
		if (i == 5)
			added = vec_add(added, vec_multiply(kernel[i], coeff));
		else if (i % 2)
			added = vec_add(added, vec_multiply(kernel[i], coeff));
		else if (!(i % 2))
			added = vec_add(added, vec_multiply(kernel[i], coeff));
	}
	ret.argb.r = added.x;
	ret.argb.g = added.y;
	ret.argb.b = added.z;
	return (ret.c);
}

static void	blur(t_data *data, t_point crd, t_vec vp, t_color *copy)
{
	t_inter	inter;
	t_vec	ray;
	//double	coeff;

	inter.min_dist = 0;
	ray = compute_ray(vp, data->cams[data->i]);
	if (!hit(data, ray, &inter))
		return ;
	pt_to_tex(crd, data->tex, gaussian_blur(copy, crd));
}

t_color		*copy_colors(uint32_t *src)
{
	t_color	*copy;
	int		i;
	int		size;

	i = 0;
	size = WIN_H * WIN_W;
	copy = (t_color *)malloc(32 * size);
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
	return (copy);
}

void		background_blur(t_data *data)
{
	t_color		*copy;
	t_camera	cam;
	t_point		crd;
	t_vec		vp;

	copy = copy_colors(data->tex->tab_pxl);
	cam = data->cams[data->i];
	vp = cam.vp_up_left;
	crd.y = -1;
	while (++crd.y < WIN_H)
	{
		crd.x = -1;
		while (++crd.x < WIN_W)
		{
			vp.x = cam.vp_up_left.x + (double)crd.x;
			vp.y = cam.vp_up_left.y - (double)crd.y;
			blur(data, crd, vp, copy);
		}
	}
	free(copy);
}
