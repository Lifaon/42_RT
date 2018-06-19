/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_of_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 22:57:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/19 18:05:54 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#define TAB_NB 81
#define ANGLE_COEFF 0.2
#define ANGLE_INC 0.05

static void	malloc_tabs(t_data *data, t_color *color_tabs[TAB_NB])
{
	int i;
	int	j;

	i = -1;
	while (++i < TAB_NB)
		if (!(color_tabs[i] = (t_color *)malloc(32 * WIN_H * WIN_W)))
		{
			j = -1;
			perror("Error : ");
			while (++j < i)
				free(color_tabs[j]);
			exit_all(data);
		}
}

static void	fill_color_tab(t_data *data, t_camera cam, t_color *color_tab)
{
	t_inter	inter;
	t_vec	ray;
	t_point	crd;
	t_vec	vp;

	vp = cam.vp_up_left;
	crd.y = -1;
	while (++crd.y < WIN_H)
	{
		vp.y = cam.vp_up_left.y - (double)crd.y;
		crd.x = -1;
		while (++crd.x < WIN_W)
		{
			vp.x = cam.vp_up_left.x + (double)crd.x;
			ray = compute_ray(vp, cam);
			inter.min_dist = 0;
			if (hit(data, cam, ray, &inter))
				color_tab[crd.x + crd.y * WIN_W].c = get_px_color(data, cam, inter);
			else
				color_tab[crd.x + crd.y * WIN_W].c = 0;
		}
	}
}

static void	blend(t_pixelbuf *img, t_color *color_tabs[TAB_NB], int size)
{
	t_color ret;
	t_vec	added;
	float	coeff;
	int		i;
	int		j;

	ret.c = 0;
	coeff = 1. / TAB_NB;
	i = -1;
	while (++i < size)
	{
		j = -1;
		added = (t_vec){0, 0, 0};
		while (++j < TAB_NB)
		{
			added.x += color_tabs[j][i].argb.r;
			added.y += color_tabs[j][i].argb.g;
			added.z += color_tabs[j][i].argb.b;
		}
		ret.argb.r = added.x * coeff;
		ret.argb.g = added.y * coeff;
		ret.argb.b = added.z * coeff;
		img->pxl[i] = ret.c;
	}
}

void		depth_of_field(t_data *data, t_vec point)
{
	t_color		*color_tabs[TAB_NB];
	t_camera	cam;
	t_vec		angle;
	int			i;

	malloc_tabs(data, color_tabs);
	angle = (t_vec){0, -ANGLE_COEFF, 0};
	i = -1;
	while (angle.y <= ANGLE_COEFF)
	{
		angle.x = -ANGLE_COEFF;
		while (angle.x <= ANGLE_COEFF)
		{
			cam = data->cams[data->i];
			rotate_around_point(data, &cam, point, angle);
			fill_color_tab(data, cam, color_tabs[++i]);
			angle.x += ANGLE_INC;
		}
		angle.y += ANGLE_INC;
	}
	blend(data->img, color_tabs, WIN_W * WIN_H);
	i = -1;
	while (++i < TAB_NB)
		free(color_tabs[i]);
	put_pixelbuf_to_widget(data->img, NULL);
	gtk_widget_show_all(data->win);
}
