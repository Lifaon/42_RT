/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_object_json.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 20:06:28 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/24 20:10:30 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static int		size_sphere_json(int size, int i)
{
	size += ft_strlen("\t\t\t\"radius\" : ");
	size += size_double(g_data->objs[i].r) + 1;
	return (size);
}

static int		size_plane_json(int size, int i)
{
	size += ft_strlen("\t\t\t\"angle\" : ");
	size += size_vec(g_data->objs[i].angle) + 2;
	size += ft_strlen("\t\t\t\"specular\" : ");
	size += size_double(g_data->objs[i].r) + 1;
	return (size);
}

static int		size_cylinder_json(int size, int i)
{
	size += ft_strlen("\t\t\t\"angle\" : ");
	size += size_vec(g_data->objs[i].angle) + 2;
	size += ft_strlen("\t\t\t\"radius\" : ");
	size += size_double(g_data->objs[i].r) + 1;
	return (size);
}

static int		size_cone_json(int size, int i)
{
	size += ft_strlen("\t\t\t\"angle\" : ");
	size += size_vec(g_data->objs[i].angle) + 2;
	size += ft_strlen("\t\t\t\"radius\" : ");
	size += size_double(g_data->objs[i].r) + 1;
	return (size);
}

int				size_of_object_json(int size, int type, int i)
{
	if (type == SPHERE)
		size += size_sphere_json(size, i);
	else if (type == PLANE)
		size += size_plane_json(size, i);
	else if (type == CYLINDER)
		size += size_cylinder_json(size, i);
	else if (type == CONE)
		size += size_cone_json(size, i);
	return (size);
}