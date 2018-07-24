/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_str_json.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:09:47 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 19:52:12 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static size_t	size_of_cams(void)
{
	size_t		size;
	int			i;

	i = 0;
	size = ft_strlen("{\n\t\"cameras\" :\n\t[\n\t\t{\n");
	while (i < CAM_NB)
	{
		size += ft_strlen("\t\t{\n");
		size += ft_strlen("\t\t\t\"position\" : ");
		size += size_vec(g_data->cams[i].pos) + 2;
		size += ft_strlen("\t\t\t\"fov\" : ");
		size += size_double(g_data->cams[i].fov) + 1;
		size += ft_strlen("\t\t\t\"angle\" : ");
		size += size_vec(g_data->cams[i].angle) + 2;
		size += ft_strlen("\t\t},\n");
		i++;
	}
	size--;
	if (g_data->nb_objects == 0 && g_data->nb_lights == 0)
		size += ft_strlen("\t]\n");
	else
		size += ft_strlen("\t],\n");
	return (size);
}

static size_t	size_one_light(t_light *light)
{
	size_t		size;

	size = ft_strlen("\t\t{\n");
	size += ft_strlen("\t\t\t\"position\" : ");
	size += size_vec(light->pos) + 2;
	size += ft_strlen("\t\t\t\"angle\" : ");
	size += size_vec(light->angle) + 2;
	size += ft_strlen("\t\t\t\"is_para\" : ");
	size += size_int(light->is_para) + 2;
	size += ft_strlen("\t\t\t\"ambiant\" : ");
	size += size_double(light->ambi) + 2;
	size += ft_strlen("\t\t\t\"radius\" : ");
	size += size_double(light->r) + 2;
	size += ft_strlen("\t\t\t\"color\" : ");
	size += size_color(light->color) + 1;
	size += ft_strlen("\t\t},\n");
	return (size);
}

static size_t	size_of_lights(void)
{
	size_t		size;
	int			i;

	i = 0;
	size = ft_strlen("\t\"lights\" :\n\t[\n\t\t{\n");
	while (i < g_data->nb_lights)
	{
		size += size_one_light(&g_data->lights[i]);
		i++;
	}
	size--;
	if (g_data->nb_objects == 0)
		size += ft_strlen("\t]\n");
	else
		size += ft_strlen("\t],\n");
	return (size);
}

size_t			size_of_str_json(void)
{
	return (size_of_cams() + size_of_lights() + size_of_objects_json());
}
