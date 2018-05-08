/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:16:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/08 18:29:06 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	draw_pixel(t_data *data, t_vec ray, int index)
{
	t_inter	inter;
	double	tmp;
	int		i;
	int		object_index;

	tmp = INFINITY;
	i = -1;
	while (++i < data->nb_objects)
		if (data->objs[i].intersect(data->objs[i], ray, &inter) && \
			inter.t < tmp)
		{
			tmp = inter.t;
			object_index = i;
		}
	if (tmp < INFINITY)
	{
		inter.t = tmp;
		inter.ip = vec_add(data->cams[data->i].pos, vec_multiply(ray, inter.t));
		data->mlx.addr[index] = shadow_ray(data, inter, object_index);
	}
}

void		draw_image(t_data *data)
{
	int		x;
	int		y;
	t_vec	ray;

	y = -1.0;
	ray.z = data->cams[data->i].vp_up_left.z;
	while (++y < WIN_H)
	{
		x = -1.0;
		ray.y = data->cams[data->i].vp_up_left.y - (double)y;
		while (++x < WIN_W)
		{
			ray.x = data->cams[data->i].vp_up_left.x + (double)x;
			draw_pixel(data, vec_normalize(ray), (y * WIN_W) + x);
		}
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}
