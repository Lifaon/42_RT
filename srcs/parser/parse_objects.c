/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:02:27 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/24 20:40:16 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	parse_object(t_obj *object, char *str, int *index)
{
	int i;
	int	in_braces;

	i = 0;
	in_braces = 1;
	while (in_braces)
	{
		++i;
		if (str[i] == '\"' && in_braces == 1)
			which_object_variable(object, str, &i);
		if (str[i] == '{' || str[i] == '}')
			in_braces += (str[i] == '{' ? 1 : -1);
	}
	if (object->spec > 1 || object->spec < 0)
		object->spec = object->spec > 1 ? 1 : 0;
	if (object->alpha < 1)
		object->alpha = 1;
	if (object->shiny > 1 || object->shiny < 0)
		object->shiny = object->shiny > 1 ? 1 : 0;
	if (object->trans > 1 || object->trans < 0)
		object->trans = object->trans > 1 ? 1 : 0;
	if (object->tex_scale < 1)
		object->tex_scale = 1;
	get_dir(object);
	*index += i;
}

static void	which_object(t_data *data, char *str, int *index, int *object_index)
{
	int			obj_type;
	int			i;

	i = 0;
	if (read_quotes(str, "\"sphere\"", &i))
		obj_type = SPHERE;
	else if (read_quotes(str, "\"plane\"", &i))
		obj_type = PLANE;
	else if (read_quotes(str, "\"cylinder\"", &i))
		obj_type = CYLINDER;
	else if (read_quotes(str, "\"cone\"", &i))
		obj_type = CONE;
	else
		return ;
	while (str[i] != '{')
		++i;
	data->objs[*object_index].obj_type = obj_type;
	data->objs[*object_index].intersect = data->intersect[obj_type];
	data->objs[*object_index].get_normal = data->get_normal[obj_type];
	parse_object(&data->objs[(*object_index)], str + i, &i);
	if (data->objs[*object_index].limited != LIMIT_NONE)
		data->objs[*object_index].limit = data->limit[\
			data->objs[*object_index].limited];
	++*object_index;
	*index += i;
}

void		parse_objects(t_data *data, char *str, int *index)
{
	int object_index;
	int in_braces;
	int i;

	i = 0;
	while (str[i] != '{')
		++i;
	if (!(data->nb_objects = get_nb_objects(str + i + 1)))
		return ;
	if (init_objects(data, data->nb_objects))
	{
		data->nb_objects = 0;
		free(str);
		exit_all(data);
	}
	in_braces = 1;
	object_index = 0;
	while (in_braces)
	{
		if (str[++i] == '\"' && object_index < data->nb_objects)
			which_object(data, str + i, &i, &object_index);
		else if (str[i] == '{' || str[i] == '}')
			in_braces += (str[i] == '{' ? 1 : -1);
	}
	*index += i;
}
