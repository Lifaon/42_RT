/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_of_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 22:57:49 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/05 03:03:38 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#define TAB_NB 81
#define ANGLE_COEFF 0.8
#define ANGLE_INC 0.2

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

static void	fill_color_tabs(t_data *data, t_vec pt, t_color *color_tabs[TAB_NB])
{
	t_vec		angle;
	int			i;
	uint32_t	*ptr;

	angle = (t_vec){0, -ANGLE_COEFF, 0};
	i = -1;
	ptr = data->img->pxl;
	while (angle.y <= ANGLE_COEFF)
	{
		angle.x = -ANGLE_COEFF;
		while (angle.x <= ANGLE_COEFF)
		{
			ft_putstr("\rDepth_of_field : ");
			ft_putstr(ft_itoa(++i * 100 / 81));
			ft_putstr("%");
			data->cam = data->cams[data->i];
			rotate_around_point(data, pt, angle);
			data->img->pxl = (uint32_t *)color_tabs[i];
			draw_image();
			angle.x += ANGLE_INC;
		}
		angle.y += ANGLE_INC;
	}
	ft_putstr("\rDepth_of_field : 100%\n");
	data->img->pxl = ptr;
}

static void	blend(t_pixelbuf *img, t_color *color_tabs[TAB_NB], int size)
{
	t_added	added;
	float	coeff;
	int		i;
	int		j;

	coeff = TAB_NB;
	i = -1;
	while (++i < size)
	{
		j = -1;
		added = (t_added){0, 0, 0, 0};
		while (++j < TAB_NB)
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
	t_color	*color_tabs[TAB_NB];
	t_vec	point;
	int		i;

	point = g_data->objs[g_data->depth_of_field].pos;
	malloc_tabs(g_data, color_tabs);
	fill_color_tabs(g_data, point, color_tabs);
	blend(g_data->img, color_tabs, WIN_W * WIN_H);
	i = -1;
	while (++i < TAB_NB)
		free(color_tabs[i]);
}
