/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_str_json.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:09:47 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/18 20:27:36 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

static size_t	size_of_lights(void)
{
	size_t		size;
	int			i;

	i = 0;
	size = ft_strlen("\t\"lights\" :\n\t[\n\t\t{\n");
	while (i < g_data->nb_lights)
	{
		size += ft_strlen("\t\t{\n");
		size += ft_strlen("\t\t\t\"position\" : ");
		size += size_vec(g_data->lights[i].pos) + 2;
		size += ft_strlen("\t\t\t\"ambiant\" : ");
		size += size_double(g_data->lights[i].ambi) + 1;
		size += ft_strlen("\t\t},\n");
		i++;
	}
	size--;
	if (g_data->nb_objects == 0)
		size += ft_strlen("\t]\n");
	else
		size += ft_strlen("\t],\n");
	return (size);
}

static size_t	get_size_str_obj_type(int type)
{
	size_t		size;

	size = 7;
	if (type == SPHERE)
		return (size + 6);
	else if (type == PLANE)
		return (size + 5);
	else if (type == CYLINDER)
		return (size + 8);
	else if (type == CONE)
		return (size + 4);
	return (0);
}

static size_t	size_all_objects(void)
{
	size_t		size;
	int			i;

	i = 0;
	size = ft_strlen("\t\"objects\" :\n\t{\n\t\t{\n");
	while (i < g_data->nb_objects)
	{
		size += get_size_str_obj_type(g_data->objs[i].obj_type);
		size += ft_strlen("\t\t{\n");
		size += ft_strlen("\t\t\t\"position\" : ");
		size += size_vec(g_data->objs[i].pos) + 2;
		size += ft_strlen("\t\t\t\"color\" : ");
		size += size_color(g_data->objs[i].color) + 2;
		size += ft_strlen("\t\t\t\"alpha\" : ");
		size += size_double(g_data->objs[i].alpha) + 1;
		size += size_of_object_json(size, g_data->objs[i].obj_type, i);
		size += ft_strlen("\t\t},\n");
		i++;
	}
	size--;
	size += ft_strlen("\t},\n}");
	return (size);
}

size_t			size_of_str_json(void)
{
	return (size_of_cams() + size_of_lights() + size_all_objects());
}
