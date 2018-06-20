/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixelated_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:42:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/20 15:24:38 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	draw_pixels(t_data *data, t_point crd, int color)
{
	t_point px;

	crd.x *= PX;
	crd.y *= PX;
	px.y = -1;
	while (++px.y < PX)
	{
		px.x = -1;
		while (++px.x < PX)
			pt_to_pixelbuf(\
				(t_point){crd.x + px.x, crd.y + px.y}, data->img, color);
	}
}

void		draw_pixelated_image(t_data *data)
{
	t_point		crd;
	t_inter		inter;
	t_vec		vp;
	t_vec		ray;

	vp = g_data->cam.vp_up_left;
	crd.y = -1;
	while (++crd.y < WIN_W / PX)
	{
		vp.y = g_data->cam.vp_up_left.y - ((PX * 0.5) + (double)crd.y * PX);
		crd.x = -1;
		while (++crd.x < WIN_W / PX)
		{
			vp.x = g_data->cam.vp_up_left.x + ((PX * 0.5) + (double)crd.x * PX);
			ray = compute_ray(vp);
			if (hit(data, ray, &inter))
				draw_pixels(data, crd, get_px_color(data, inter));
			else
				draw_pixels(data, crd, 0xFF000000);
		}
	}
	put_pixelbuf_to_widget(data->img, NULL);
	gtk_widget_show_all(data->win);
}
