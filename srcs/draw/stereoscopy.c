/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereoscopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 01:28:22 by vtudes            #+#    #+#             */
/*   Updated: 2018/07/24 22:21:20 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "rtv1.h"

static void		init_dir(t_vec *dir)
{
	*dir = (t_vec){0, 0, g_data->stereo_scale};
	*dir = pitch(*dir, g_data->cam.angle);
	*dir = yaw(*dir, g_data->cam.angle);
}

static void		blend(uint32_t *img, t_color *color_tabs[2], int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		img[i] = (t_color){.argb.r = color_tabs[0][i].argb.r, \
			.argb.g = color_tabs[1][i].argb.g, \
			.argb.b = color_tabs[1][i].argb.b, \
			.argb.a = 255}.c;
	}
}

static void		get_stereo_2(t_color **tab, t_vec dir)
{
	g_data->cam = g_data->cams[g_data->i];
	g_data->cam.pos = vec_add(g_data->cam.pos, \
		vec_cross_product2(dir, (t_vec){0, 1, 0}));
	if (g_data->clust_i == CLUST_CLIENT)
		g_data->cimg = (uint32_t*)tab[0];
	else
		g_data->img->pxl = (uint32_t *)tab[0];
	get_vp_up_left(&g_data->cam);
	get_oc();
	draw_image();
	if (g_data->filter == FILTER_BNW)
		black_and_white(g_data);
	g_data->cam = g_data->cams[g_data->i];
	if (g_data->clust_i == CLUST_CLIENT)
		g_data->cimg = (uint32_t*)tab[1];
	else
		g_data->img->pxl = (uint32_t *)tab[1];
	dir = vec_multiply(dir, -1);
	g_data->cam.pos = vec_add(g_data->cam.pos, \
		vec_cross_product2(dir, (t_vec){0, 1, 0}));
	get_vp_up_left(&g_data->cam);
	get_oc();
	draw_image();
	if (g_data->filter == FILTER_BNW)
		black_and_white(g_data);
	g_data->cam = g_data->cams[g_data->i];
	get_vp_up_left(&g_data->cam);
	get_oc();
}

void			get_stereo(void)
{
	t_vec		dir;
	t_color		*tab[2];
	uint32_t	*ptr;

	if (!(tab[0] = (t_color *)ft_memalloc(32 * WIN_W * WIN_H)))
	{
		perror("Error during steroscopy : ");
		return ;
	}
	if (!(tab[1] = (t_color *)ft_memalloc(32 * WIN_W * WIN_H)))
	{
		perror("Error during steroscopy : ");
		free(tab[0]);
		return ;
	}
	init_dir(&dir);
	ptr = g_data->clust_i == CLUST_CLIENT ? g_data->cimg : g_data->img->pxl;
	get_stereo_2(tab, dir);
	if (g_data->clust_i == CLUST_CLIENT)
		g_data->cimg = ptr;
	else
		g_data->img->pxl = ptr;
	blend(g_data->clust_i == CLUST_CLIENT ? g_data->cimg : g_data->img->pxl, \
			tab, WIN_W * WIN_H);
	free(tab[0]);
	free(tab[1]);
	ft_putendl_color("fin stero", "red");
}
