/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_str_json.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:09:47 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/28 23:32:46 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char		*str_cams(char *str)
{
	int		i;

	i = 0;
	str = my_strcopy(str, "{\n\t\"cameras\" :\n\t[\n\t\t{\n");
	while (i < CAM_NB)
	{
		str = my_strcopy(str, "\t\t{\n");
		str = my_strcopy(str, "\t\t\t\"position\" : ");
		str = strcpy_vec(str, g_data->cams[i].pos);
		str = my_strcopy(str, "\t\t\t\"fov\" : ");
		str = strcpy_db(str, g_data->cams[i].fov);
		i++;
		if (i == CAM_NB)
			str = my_strcopy(str, "\t\t}\n");
		else
			str = my_strcopy(str, "\t\t},\n");
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
	str = my_strcopy(str, "\t\"lights\" :\n\t[\n\t\t{\n");
	while (i < g_data->nb_lights)
	{
		str = my_strcopy(str, "\t\t{\n");
		str = my_strcopy(str, "\t\t\t\"position\" : ");
		str = strcpy_vec(str, g_data->lights[i].pos);
		str = my_strcopy(str, ",\n\t\t\t\"ambiant\" : ");
		str = strcpy_db(str, g_data->lights[i].ambi);
		i++;
		if (i == g_data->nb_lights)
			str = my_strcopy(str, ",\n\t\t}\n");
		else
			str = my_strcopy(str, ",\n\t\t},\n");
	}
	if (g_data->nb_objects == 0)
		str = my_strcopy(str, "\t]\n");
	else
		str = my_strcopy(str, "\t],\n");
	return (str);
}

static char		*str_obj_type(char *str, t_obj_type type)
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
	str = my_strcopy(str, "\t\"objects\" :\n\t{\n\t\t{\n");
	while (i < g_data->nb_objects)
	{
		str = str_obj_type(str, g_data->objs[i].obj_type);
		str = my_strcopy(str, "\t\t{\n");
		str = my_strcopy(str, "\t\t\t\"position\" : ");
		str = strcpy_vec(str, g_data->objs[i].pos);
		str = my_strcopy(str, "\t\t\t\"direction\" : ");
		str = strcpy_vec(str, g_data->objs[i].dir);
		str = my_strcopy(str, "\t\t\t\"radius\" : ");
		str = strcpy_db(str, g_data->objs[i].r);
		str = my_strcopy(str, "\t\t\t\"color\" : ");
		str = color_toa(str, g_data->objs[i].color);
		i++;
		if (i == g_data->nb_objects)
			str = my_strcopy(str, "\t\t}\n");
		else
			str = my_strcopy(str, "\t\t},\n");
	}
		str = my_strcopy(str, "\t},\n}");
	return (str);
}

char			*fill_str_json(size_t size)
{
	char	*str;
	char	*dst;

	str = ft_strnew(size);
	dst = str;
	str = str_cams(str);
	str[0] = '\0';
	ft_putchar('\n');
	ft_putendl(dst);
	ft_putnbr(444);
	ft_putchar('\n');
	str[0] = '&';
	str = str_lights(str);
	str[0] = '\0';
	ft_putchar('\n');
	ft_putendl(dst);
	ft_putnbr(444);
	ft_putchar('\n');
	str = str_objects(str);
	str[0] = '\0';
	return (dst);
}
