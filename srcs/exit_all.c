/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:08:07 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/09 14:08:30 by mlantonn         ###   ########.fr       */
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
	if (data->nb_objects)
		free(data->objs);
	if (data->nb_lights)
		free(data->lights);
	exit(0);
	return (0);
}
