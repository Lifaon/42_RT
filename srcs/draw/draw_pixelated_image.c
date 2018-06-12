/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixelated_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:42:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/12 16:22:42 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	draw_pixels(t_data *data, t_point crd, int color)
{
	t_point px;

	crd.x *= PIXEL;
	crd.y *= PIXEL;
	px.y = -1;
	while (++px.y < PIXEL)
	{
		px.x = -1;
		while (++px.x < PIXEL)
			pt_to_tex((t_point){crd.x + px.x, crd.y + px.y}, data->tex, color);
	}
}

void		draw_pixelated_image(t_data *data)
{
	t_camera	cam;
	t_point		crd;
	t_inter		inter;
	t_vec		vp;
	t_vec		ray;

	cam = data->cams[data->i];
	vp = cam.vp_up_left;
	crd.y = -1;
	while (++crd.y < WIN_W / PIXEL)
	{
		vp.y = cam.vp_up_left.y - ((PIXEL * 0.5) + (double)crd.y * PIXEL);
		crd.x = -1;
		while (++crd.x < WIN_W / PIXEL)
		{
			vp.x = cam.vp_up_left.x + ((PIXEL * 0.5) + (double)crd.x * PIXEL);
			ray = compute_ray(vp, data->cams[data->i]);
			if (hit(data, ray, &inter))
				draw_pixels(data, crd, get_px_color(data, inter));
			else
				draw_pixels(data, crd, 0);
		}
	}
	put_tex_to_win(data->tex, data->win->ren);
}
