/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:08:07 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/03 19:14:05 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	Retourne une valeur pour etre utilisé par mlx_hook.
*/
int		exit_all(t_data *data)
{
	if (data->tex)
		free_tex(&data->tex);
	if (data->win)
		free_win(&data->win);
	SDL_Quit();
	/*if (data->mlx.img && data->mlx.mlx)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	if (data->mlx.win && data->mlx.mlx)
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);*/
	exit(0);
	return (0);
}
