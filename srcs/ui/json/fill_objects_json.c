/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objects_json.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:02:56 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 18:23:29 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static char		*fill_sphere_json(char *str, t_obj *obj)
{
	str = my_strcopy(str, "\t\t\"");
	str = my_strcopy(str, "sphere");
	str = my_strcopy(str, "\" :\n\t\t{\n");
	str = my_strcopy(str, ",\n\t\t\t\"radius\" : ");
	str = strcpy_db(str, obj->r);
	return (str);
}

static char		*fill_plane_json(char *str, t_obj *obj)
{
	str = my_strcopy(str, "\t\t\"");
	str = my_strcopy(str, "plane");
	str = my_strcopy(str, "\" :\n\t\t{\n");
	str = my_strcopy(str, ",\n\t\t\t\"angle\" : ");
	str = strcpy_vec(str, obj->angle);
	str = my_strcopy(str, ",\n\t\t\t\"specular\" : ");
	str = strcpy_db(str, obj->spec);
	return (str);
}

static char		*fill_cone_cylinder_json(char *str, t_obj *obj)
{
	str = my_strcopy(str, "\t\t\"");
	if (obj->obj_type == CYLINDER)
		str = my_strcopy(str, "cylinder");
	else
		str = my_strcopy(str, "cone");
	str = my_strcopy(str, "\" :\n\t\t{\n");
	str = my_strcopy(str, ",\n\t\t\t\"angle\" : ");
	str = strcpy_vec(str, obj->angle);
	str = my_strcopy(str, ",\n\t\t\t\"radius\" : ");
	str = strcpy_db(str, obj->r);
	return (str);
}

static char		*fill_obj_type(char *str, t_obj *obj)
{
	if (obj->obj_type == SPHERE)
		str = fill_sphere_json(str, obj);
	else if (obj->obj_type == PLANE)
		str = fill_plane_json(str, obj);
	else if (obj->obj_type == CYLINDER || obj->obj_type == CONE)
		str = fill_cone_cylinder_json(str, obj);
	return (str);
}

char		*fill_objects_json(char *str)
{
	int			i;

	i = 0;
	str = my_strcopy(str, "\t\"objects\" :\n\t{\n");
	while (i < g_data->nb_objects)
	{
		str = fill_obj_type(str, &g_data->objs[i]);
		str = fill_object_common_json(str, &g_data->objs[i]);
		i++;
		if (i == g_data->nb_objects)
			str = my_strcopy(str, "\n\t\t}\n");
		else
			str = my_strcopy(str, "\n\t\t},\n");
	}
	str = my_strcopy(str, "\t}\n}");
	return (str);
}

