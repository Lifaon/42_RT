/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:48:34 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/10 19:07:38 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		img_init(t_mlx *mlx)
{
	int	bpp;
	int	s_l;
	int	endian;

	if (!(mlx->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H)))
	{
		ft_putendl("mlx_new_image() error");
		mlx_destroy_window(mlx->mlx, mlx->win);
		return (-1);
	}
	mlx->addr = (int *)mlx_get_data_addr(mlx->img, &bpp, &s_l, &endian);
	return (0);
}
