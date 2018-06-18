/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:16:23 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/18 17:55:03 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "draw.h"

static void	draw_pixel(t_data *data, t_camera cam, t_vec vp, t_point crd)
{
	t_inter	inter;
	t_vec	ray;

	if (data->aa <= 1)
	{
		ray = compute_ray(vp, cam);
		inter.min_dist = 0;
		if (hit(data, cam, ray, &inter))
			pt_to_tex(crd, data->tex, get_px_color(data, cam, inter));
		else
			pt_to_tex(crd, data->tex, 0);
	}
	else if (data->aa > 1)
		pt_to_tex(crd, data->tex, anti_aliasing(data, vp));
}

void		draw_image(t_data *data)
{
	t_camera	cam;
	t_point		crd;
	t_vec		vp;

	cam = data->cams[data->i];
	crd = (t_point){0, 0};
	vp = cam.vp_up_left;
	while (crd.x < WIN_W)
	{
		vp.x = cam.vp_up_left.x + (double)crd.x;
		vp.y = cam.vp_up_left.y - (double)crd.y;
		draw_pixel(data, cam, vp, crd);
		crd = pt_ypluseg(crd, 0, WIN_H);
	}
	put_tex_to_win(data->tex, data->win->ren);
}
