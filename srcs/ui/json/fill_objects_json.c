/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objects_json.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:02:56 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 11:35:16 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static char		*fill_obj_type(char *str, t_obj *obj)
{
	str = my_strcopy(str, "\t\t\"");
	if (obj->obj_type == CYLINDER)
		str = my_strcopy(str, "cylinder");
	else if (obj->obj_type == CONE)
		str = my_strcopy(str, "cone");
	else if (obj->obj_type == SPHERE)
		str = my_strcopy(str, "sphere");
	else
		str = my_strcopy(str, "plane");
	str = my_strcopy(str, "\" :\n\t\t{\n");
	str = my_strcopy(str, "\t\t\t\"angle\" : ");
	str = strcpy_vec(str, obj->angle);
	if (obj->obj_type != PLANE)
	{
		str = my_strcopy(str, ",\n\t\t\t\"radius\" : ");
		str = strcpy_db(str, obj->r);
	}
	return (str);
}

char			*fill_objects_json(char *str)
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
