/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:34:31 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/24 18:36:49 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	t_mlx_init(t_mlx *mlx)
{
	if (!(mlx->mlx = mlx_init()))
	{
		ft_putendl("mlx_init() error.");
		exit(-1);
	}
	if (!(mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "RT")))
	{
		ft_putendl("mlx_new_window() error.");
		exit(-1);
	}
	if (img_init(mlx))
		exit(-1);
}
