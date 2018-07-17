/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_of_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 22:57:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/17 04:56:31 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	malloc_tabs(t_data *data, t_color *color_tabs[81])
{
	int i;
	int	j;

	i = -1;
	while (++i < 81)
		if (!(color_tabs[i] = (t_color *)malloc(32 * WIN_H * WIN_W)))
		{
			j = -1;
			perror("Error : ");
			while (++j < i)
				free(color_tabs[j]);
			exit_all(data);
		}
}

static void	fill_color_tabs(t_data *data, t_vec pt, t_color *color_tabs[81])
{
	uint32_t	*ptr;
	t_vec		angle;
	int			i;
	int 		j;

	ptr = data->img->pxl;
	i = -1;
	angle.z = 0;
	while (++i < 9)
	{
		angle.y = -data->dof_coeff + (data->dof_coeff * 0.25 * i);
		j = -1;
		while (++j < 9)
		{
			ft_putstr("\rDepth_of_field : %");
			ft_putstr(ft_itoa((i * 9 + j) * 100 / 81));
			angle.x = -data->dof_coeff + (data->dof_coeff * 0.25 * j);
			data->cam = data->cams[data->i];
			rotate_around_point(data, pt, angle);
			data->img->pxl = (uint32_t *)color_tabs[i * 9 + j];
			draw_image();
		}
	}
	ft_putstr("\rDepth_of_field : %100\n");
	data->img->pxl = ptr;
}

static void	blend(t_pixelbuf *img, t_color *color_tabs[81], int size)
{
	t_added	added;
	float	coeff;
	int		i;
	int		j;

	coeff = 81;
	i = -1;
	while (++i < size)
	{
		j = -1;
		added = (t_added){0, 0, 0, 0};
		while (++j < 81)
		{
			added.r += color_tabs[j][i].argb.r;
			added.g += color_tabs[j][i].argb.g;
			added.b += color_tabs[j][i].argb.b;
			added.a += color_tabs[j][i].argb.a;
		}
		img->pxl[i] = (t_color){.argb.r = added.r / coeff, \
			.argb.g = added.g / coeff, .argb.b = added.b / coeff, \
			.argb.a = added.a / coeff}.c;
	}
}

void		depth_of_field()
{
	t_color	*color_tabs[81];
	t_vec	point;
	int		i;

	point = g_data->objs[g_data->depth_of_field].pos;
	malloc_tabs(g_data, color_tabs);
	fill_color_tabs(g_data, point, color_tabs);
	blend(g_data->img, color_tabs, WIN_W * WIN_H);
	i = -1;
	while (++i < 81)
		free(color_tabs[i]);
}
