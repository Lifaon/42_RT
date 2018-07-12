/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:02:27 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/12 03:30:29 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	parse_limit(t_obj *object, char *str, int *index)
{
	int i;

	i = *index - 1;
	while (str[++i] && str[i] != ':');
	if (str[i] != ':')
		return ;
	*index = i + 1;
	if (read_quotes(str + *index, "\"axe\"", index))
		object->limited = LIMIT_AXE;
	else if (read_quotes(str + *index, "\"sphere\"", index))
		object->limited = LIMIT_SPHERE;
	else if (read_quotes(str + *index, "\"rectangle\"", index))
		object->limited = LIMIT_RECTANGLE;
	else if (read_quotes(str + *index, "\"circle\"", index))
		object->limited = LIMIT_CIRCLE;
	else if (read_quotes(str + *index, "\"cylinder\"", index))
		object->limited = LIMIT_CYLINDER;
	else if (read_quotes(str + *index, "\"cone\"", index))
		object->limited = LIMIT_CONE;
	else if (read_quotes(str + *index, "\"none\"", index))
		object->limited = LIMIT_NONE;
}

static void	which_object_variable(t_obj *object, char *str, int *index)
{
	if (read_quotes(str + *index, "\"position\"", index))
		object->pos = parse_vec(str + *index, index);
	else if (read_quotes(str + *index, "\"radius\"", index))
		object->r = fabs(parse_nb(str + *index, index));
	else if (read_quotes(str + *index, "\"color\"", index))
		object->color = parse_color(str + *index, index);
	else if (read_quotes(str + *index, "\"angle\"", index))
		object->angle = parse_vec(str + *index, index);
	else if (read_quotes(str + *index, "\"specular\"", index))
		object->spec = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"alpha\"", index))
		object->alpha = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"min\"", index))
		object->min = parse_vec(str + *index, index);
	else if (read_quotes(str + *index, "\"max\"", index))
		object->max = parse_vec(str + *index, index);
	else if (read_quotes(str + *index, "\"limit\"", index))
		parse_limit(object, str, index);
	else if (read_quotes(str + *index, "\"texture\"", index))
		parse_texture(object, str + *index, index);
	else if (read_quotes(str + *index, "\"tex_pos\"", index))
		object->tex_pos = parse_point(str + *index, index);
	else if (read_quotes(str + *index, "\"tex_scale\"", index))
		object->tex_scale = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"tex_repeat\"", index))
		object->tex_repeat = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"tex_limit\"", index))
		object->tex_limit = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"tex_trans\"", index))
		object->tex_trans = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"shiny\"", index))
		object->shiny = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"trans\"", index))
		object->trans = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"ior\"", index))
		object->ior = parse_nb(str + *index, index);
}

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
