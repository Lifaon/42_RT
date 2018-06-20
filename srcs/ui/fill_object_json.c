/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_json.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:20:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/18 20:32:41 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char		*fill_sphere_json(char *str, int i)
{
	str = my_strcopy(str, ",\n\t\t\t\"radius\" : ");
	str = strcpy_db(str, g_data->objs[i].r);
	return (str);
}

static char		*fill_plane_json(char *str, int i)
{
	str = my_strcopy(str, ",\n\t\t\t\"normal\" : ");
	str = strcpy_vec(str, g_data->objs[i].normal);
	str = my_strcopy(str, ",\n\t\t\t\"specular\" : ");
	str = strcpy_db(str, g_data->objs[i].spec);
	return (str);
}

static char		*fill_cylinder_json(char *str, int i)
{
	str = my_strcopy(str, ",\n\t\t\t\"direction\" : ");
	str = strcpy_vec(str, g_data->objs[i].dir);
	str = my_strcopy(str, ",\n\t\t\t\"radius\" : ");
	str = strcpy_db(str, g_data->objs[i].r);
	return (str);
}

static char		*fill_cone_json(char *str, int i)
{
	str = my_strcopy(str, ",\n\t\t\t\"direction\" : ");
	str = strcpy_vec(str, g_data->objs[i].dir);
	str = my_strcopy(str, ",\n\t\t\t\"radius\" : ");
	str = strcpy_db(str, g_data->objs[i].r);
	return (str);
}

char		*fill_object_json(char *str, int type, int i)
{
	if (type == SPHERE)
		str = fill_sphere_json(str, i);
	else if (type == PLANE)
		str = fill_plane_json(str, i);
	else if (type == CYLINDER)
		str = fill_cylinder_json(str, i);
	else if (type == CONE)
		str = fill_cone_json(str, i);
	return (str);
}