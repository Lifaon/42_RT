/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:02:27 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/14 16:28:46 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	which_object_variable(t_obj *object, char *str, int *index)
{
	if (read_quotes(str + *index, "\"position\"", index))
		object->pos = parse_vec(str + *index, index);
	else if (read_quotes(str + *index, "\"radius\"", index))
		object->r = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"normal\"", index))
		object->normal = vec_normalize(parse_vec(str + *index, index));
	else if (read_quotes(str + *index, "\"color\"", index))
		object->color = parse_color(str + *index, index);
	else if (read_quotes(str + *index, "\"direction\"", index))
		object->dir = vec_normalize(parse_vec(str + *index, index));
	else if (read_quotes(str + *index, "\"specular\"", index))
		object->spec = parse_nb(str + *index, index);
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
		if (str[i] == '\"')
			which_object_variable(object, str, &i);
		if (str[i] == '{' || str[i] == '}')
			in_braces += (str[i] == '{' ? 1 : -1);
	}
	*index += i;
}

static void	which_object(t_data *data, char *str, int *index, int *object_index)
{
	int i;

	i = 0;
	if (read_quotes(str, "\"sphere\"", &i))
		init_function_ptrs(&data->objs[*object_index], 0);
	else if (read_quotes(str, "\"plane\"", &i))
		init_function_ptrs(&data->objs[*object_index], 1);
	else if (read_quotes(str, "\"cylinder\"", &i))
		init_function_ptrs(&data->objs[*object_index], 2);
	else if (read_quotes(str, "\"cone\"", &i))
		init_function_ptrs(&data->objs[*object_index], 3);
	else
		return ;
	while (str[i] != '{')
		++i;
	parse_object(&data->objs[(*object_index)++], str + i, &i);
	*index += i;
}

int			parse_objects(t_data *data, char *str, int *index)
{
	int object_index;
	int in_braces;
	int i;

	i = 0;
	while (str[i] != '{')
		++i;
	in_braces = 1;
	if (!(data->nb_objects = get_nb_objects(str + i + 1)))
		return (1);
	if (init_objects(data, data->nb_objects))
		return (-1);
	object_index = 0;
	while (in_braces)
	{
		++i;
		if (str[i] == '\"' && object_index < data->nb_objects)
			which_object(data, str + i, &i, &object_index);
		else if (str[i] == '{' || str[i] == '}')
			in_braces += (str[i] == '{' ? 1 : -1);
	}
	*index += i;
	return (0);
}
