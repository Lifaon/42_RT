/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:16:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/03 17:57:12 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	draw_pixel(t_data *data, t_obj *objs, t_ray light, t_point crd)
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
			objs[i].pi = vec_add(data->ray.o, vec_multiply(data->ray.d, tmp));
			t = tmp;
			i2 = i;
		}
	}
	if (t < MAX_DIST)
		pt_to_tex(crd, data->tex,  shadow_ray(objs, light, i2));
	else
		pt_to_tex(crd, data->tex,  0);
}

void		draw_image(t_data *data, t_obj *objs, t_ray light)
{
	t_point		crd;
	t_vec		tmp;

	crd = pt_set(0, 0);
	tmp.z = data->vp00.z;
	while (crd.x < WIN_W)
	{
		tmp.y = data->vp00.y - (double)crd.y;
		tmp.x = data->vp00.x + (double)crd.x;
		data->ray.d = vec_normalize(tmp);
		draw_pixel(data, objs, light, crd);
		crd = pt_ypluseg(crd, 0, WIN_H);
	}
	put_tex_to_win(data->tex, data->win->ren);
}
