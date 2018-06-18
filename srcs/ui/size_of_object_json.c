/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_object_json.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 20:06:28 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/18 20:24:57 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		size_sphere_json(int size, int i)
{
	size += ft_strlen("\t\t\t\"radius\" : ");
	size += size_double(g_data->objs[i].r) + 1;
	return (size);
}

static int		size_plane_json(int size, int i)
{
	size += ft_strlen("\t\t\t\"normal\" : ");
	size += size_vec(g_data->objs[i].normal) + 2;
	size += ft_strlen("\t\t\t\"specular\" : ");
	size += size_double(g_data->objs[i].r) + 1;
	return (size);
}

static int		size_cylinder_json(int size, int i)
{
	size += ft_strlen("\t\t\t\"direction\" : ");
	size += size_vec(g_data->objs[i].dir) + 2;
	size += ft_strlen("\t\t\t\"radius\" : ");
	size += size_double(g_data->objs[i].r) + 1;
	return (size);
}

static int		size_cone_json(int size, int i)
{
	size += ft_strlen("\t\t\t\"direction\" : ");
	size += size_vec(g_data->objs[i].dir) + 2;
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
