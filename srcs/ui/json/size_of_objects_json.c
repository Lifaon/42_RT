/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_objects_json.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:50:09 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 14:58:05 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static size_t	size_obj_type(t_obj *obj)
{
	size_t		size;

	size = 11;
	if (obj->obj_type == CYLINDER)
		size += 8;
	if (obj->obj_type == CONE)
		size += 4;
	else if (obj->obj_type == SPHERE)
		size += 6;
	else if (obj->obj_type == PLANE)
		size += 5;
	size += ft_strlen("\t\t\t\"angle\" : ");
	size += size_vec(obj->angle) + 2;
	if (obj->obj_type != PLANE)
	{
		size += ft_strlen("\t\t\t\"radius\" : ");
		size += size_double(obj->r) + 2;
	}
	return (size);
}

/*
** size is set at 11 for the 3 cratere before the type_name '\t' '\t' '"'
** the 4 caracter at the end of line '"' ' ' ':' ' '
** and the 4 caracter of the begenning of the next line '\t' '\t' '}' '\n'
*/

size_t			size_of_objects_json(void)
{
	size_t		size;
	int			i;

	i = 0;
	size = ft_strlen("\t\"objects\" :\n\t{\n\t\t{\n");
	while (i < g_data->nb_objects)
	{
		size += size_obj_type(&g_data->objs[i]);
		size += ft_strlen("\t\t{\n");
		size += size_of_object_common_json(&g_data->objs[i]);
		size += ft_strlen("\t\t},\n");
		i++;
	}
	size--;
	size += ft_strlen("\t},\n");
	return (size);
}
