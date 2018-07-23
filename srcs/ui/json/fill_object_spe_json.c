/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_json.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:20:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/24 20:09:37 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static char		*fill_sphere_json(char *str, t_obj *obj)
{
	str = my_strcopy(str, ",\n\t\t\t\"radius\" : ");
	str = strcpy_db(str, obj->r);
	return (str);
}

static char		*fill_plane_json(char *str, t_obj *obj)
{
	str = my_strcopy(str, ",\n\t\t\t\"angle\" : ");
	str = strcpy_vec(str, obj->angle);
	str = my_strcopy(str, ",\n\t\t\t\"specular\" : ");
	str = strcpy_db(str, obj->spec);
	return (str);
}

static char		*fill_cylinder_json(char *str, t_obj *obj)
{
	str = my_strcopy(str, ",\n\t\t\t\"angle\" : ");
	str = strcpy_vec(str, obj->angle);
	str = my_strcopy(str, ",\n\t\t\t\"radius\" : ");
	str = strcpy_db(str, obj->r);
	return (str);
}

static char		*fill_cone_json(char *str, t_obj *obj)
{
	str = my_strcopy(str, ",\n\t\t\t\"angle\" : ");
	str = strcpy_vec(str, obj->angle);
	str = my_strcopy(str, ",\n\t\t\t\"radius\" : ");
	str = strcpy_db(str, obj->r);
	return (str);
}

char			*fill_object_spe_json(char *str, t_obj *obj)
{
	if (type == SPHERE)
		str = fill_sphere_json(str, obj);
	else if (type == PLANE)
		str = fill_plane_json(str, obj);
	else if (type == CYLINDER)
		str = fill_cylinder_json(str, obj);
	else if (type == CONE)
		str = fill_cone_json(str, obj);
	return (str);
}
