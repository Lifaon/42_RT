/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:16:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/03 19:30:00 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	draw_pixel(t_data *data, t_obj *objs, t_ray light, int index)
{
	double	t;
	double	tmp;
	int		i;
	int		i2;

	t = MAX_DIST;
	tmp = 0;
	i = -1;
	// 2 car je test avec deux objets mais en vrai faudra faire un truc propre
	while(++i < 2)
	{
		if (objs[i].intersect(data->ray, objs[i], &tmp) && tmp < t)
		{
			//objs[i].pi = vec_add(data->ray.o, vec_multiply(data->ray.d, tmp));
			t = tmp;
			i2 = i;
		}
	}
	if (t < MAX_DIST)
		data->mlx.addr[index] = shadow_ray(objs, light, i2);
	else
		data->mlx.addr[index] = 0;
}

void		draw_image(t_data *data, t_obj *objs, t_ray light)
{
	int		x;
	int		y;
	t_vec	tmp;

	y = -1.0;
	tmp.z = data->vp00.z;
	while (++y < WIN_H)
	{
		x = -1.0;
		tmp.y = data->vp00.y - (double)y;
		while (++x < WIN_W)
		{
			tmp.x = data->vp00.x + (double)x;
			data->ray.d = vec_normalize(tmp);
			draw_pixel(data, objs, light, (y * WIN_W) + x);
		}
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}
