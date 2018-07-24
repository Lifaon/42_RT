/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_str_json.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:09:47 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 19:07:04 by fchevrey         ###   ########.fr       */
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
		str = my_strcopy(str, ",\n\t\t\t\"angle\" : ");
		str = strcpy_vec(str, g_data->cams[i].angle);
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

static char		*str_one_light(char *str, t_light *light)
{
	str = my_strcopy(str, "\t\t{\n");
	str = my_strcopy(str, "\t\t\t\"position\" : ");
	str = strcpy_vec(str, light->pos);
	str = my_strcopy(str, ",\n\t\t\t\"angle\" : ");
	str = strcpy_vec(str, light->angle);
	str = my_strcopy(str, ",\n\t\t\t\"is_para\" : ");
	str = strcpy_int(str, light->is_para);
	str = my_strcopy(str, ",\n\t\t\t\"ambiant\" : ");
	str = strcpy_db(str, light->ambi);
	str = my_strcopy(str, ",\n\t\t\t\"radius\" : ");
	str = strcpy_db(str, light->r);
	str = my_strcopy(str, ",\n\t\t\t\"color\" : ");
	str = strcpy_color(str, light->color);
	return (str);
}

static char		*str_lights(char *str)
{
	int			i;

	i = 0;
	str = my_strcopy(str, "\t\"lights\" :\n\t[\n");
	while (i < g_data->nb_lights)
	{
		str = str_one_light(str, &g_data->lights[i]);
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

char			*fill_str_json(size_t size)
{
	char	*str;
	char	*dst;

	str = ft_strnew(size);
	dst = str;
	str = str_cams(str);
	str = str_lights(str);
	str = fill_objects_json(str);
	str[0] = '\0';
	return (dst);
}
