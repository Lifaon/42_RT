/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_str_json.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:09:47 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/20 20:12:04 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static char		*str_cams(char *str)
{
	int		i;

	i = 0;
	str = my_strcopy(str, "{\n\t\"cameras\" :\n\t[\n");
	while (i < CAM_NB)
	{
		str = my_strcopy(str, "\t\t{\n");
		str = my_strcopy(str, "\t\t\t\"position\" : ");
		str = strcpy_vec(str, g_data->cams[i].pos);
		str = my_strcopy(str, ",\n\t\t\t\"fov\" : ");
		str = strcpy_db(str, g_data->cams[i].fov);
		i++;
		if (i == CAM_NB)
			str = my_strcopy(str, "\n\t\t}\n");
		else
			str = my_strcopy(str, "\n\t\t},\n");
	}
	if (g_data->nb_objects == 0 && g_data->nb_lights == 0)
		str = my_strcopy(str, "\t]\n");
	else
		str = my_strcopy(str, "\t],\n");
	return (str);
}

static char		*str_lights(char *str)
{
	int			i;

	i = 0;
	str = my_strcopy(str, "\t\"lights\" :\n\t[\n");
	while (i < g_data->nb_lights)
	{
		str = my_strcopy(str, "\t\t{\n");
		str = my_strcopy(str, "\t\t\t\"position\" : ");
		str = strcpy_vec(str, g_data->lights[i].pos);
		t_vec vec;
		vec = g_data->lights[i].pos;
		printf("vec = [%lf, %lf, %lf]\n", vec.x, vec.y, vec.z);
		str = my_strcopy(str, ",\n\t\t\t\"ambiant\" : ");
		str = strcpy_db(str, g_data->lights[i].ambi);
		i++;
		if (i == g_data->nb_lights)
			str = my_strcopy(str, "\n\t\t}\n");
		else
			str = my_strcopy(str, "\n\t\t},\n");
	}
	if (g_data->nb_objects == 0)
		str = my_strcopy(str, "\t]\n");
	else
		str = my_strcopy(str, "\t],\n");
	return (str);
}

static char		*str_obj_type(char *str, int type)
{
	str = my_strcopy(str, "\t\t\"");
	if (type == SPHERE)
		str = my_strcopy(str, "sphere");
	else if (type == PLANE)
		str = my_strcopy(str, "plane");
	else if (type == CYLINDER)
		str = my_strcopy(str, "cylinder");
	else if (type == CONE)
		str = my_strcopy(str, "cone");
	str = my_strcopy(str, "\" :\n");
	return (str);
}

static char		*str_objects(char *str)
{
	int			i;

	i = 0;
	str = my_strcopy(str, "\t\"objects\" :\n\t{\n");
	while (i < g_data->nb_objects)
	{
		str = str_obj_type(str, g_data->objs[i].obj_type);
		str = my_strcopy(str, "\t\t{\n");
		str = my_strcopy(str, "\t\t\t\"position\" : ");
		str = strcpy_vec(str, g_data->objs[i].pos);
		str = my_strcopy(str, ",\n\t\t\t\"color\" : ");
		str = color_toa(str, g_data->objs[i].color);
		str = my_strcopy(str, ",\n\t\t\t\"alpha\" : ");
		str = strcpy_db(str, g_data->objs[i].alpha);
		str = fill_object_json(str, g_data->objs[i].obj_type, i);
		i++;
		if (i == g_data->nb_objects)
			str = my_strcopy(str, "\n\t\t}\n");
		else
			str = my_strcopy(str, "\n\t\t},\n");
	}
	str = my_strcopy(str, "\t}\n}");
	return (str);
}

char			*fill_str_json(size_t size)
{
	char	*str;
	char	*dst;

	str = ft_strnew(size);
	dst = str;
	str = str_cams(str);
	str = str_lights(str);
	str = str_objects(str);
	str[0] = '\0';
	return (dst);
}
