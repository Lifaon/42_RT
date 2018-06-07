/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:16:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/07 04:00:36 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "draw.h"

static void	draw_pixel(t_data *data, t_vec ray, t_point crd)
{
	t_inter	inter;
	double	t;
	int		i;

	t = INFINITY;
	i = -1;
	inter.min_dist = 0;
	while (++i < data->nb_objects)
	{
		inter.oc = data->objs[i].oc;
		if (data->objs[i].intersect(data->objs[i], ray, &inter) && inter.t < t)
		{
			t = inter.t;
			inter.obj_i = i;
		}
	}
	if (t < INFINITY)
	{
		inter.t = t;
		inter.ip = vec_add(data->cams[data->i].pos, vec_multiply(ray, inter.t));
		inter.normal = get_normal(ray, data->objs[inter.obj_i], inter);
	}
	pt_to_tex(crd, data->tex, t < INFINITY ? get_px_color(data, inter) : 0);
}

void		draw_image(t_data *data)
{
	t_camera	cam;
	t_point		crd;
	t_vec		vp;
	t_vec		ray;

	cam = data->cams[data->i];
	crd = (t_point){0, 0};
	vp = cam.vp_up_left;
	while (crd.x < WIN_W)
	{
		vp.x = cam.vp_up_left.x + (double)crd.x;
		vp.y = cam.vp_up_left.y - (double)crd.y;
		ray = compute_ray(data, vp, cam);
		draw_pixel(data, ray, crd);
		crd = pt_ypluseg(crd, 0, WIN_H);
	}
	put_tex_to_win(data->tex, data->win->ren);
}
