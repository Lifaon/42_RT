/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:02:27 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/08 14:26:37 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "rtv1.h"

static int	get_nb_objects(char *str)
{
	int i;
	int in_braces;
	int	nb_objects;

	i = -1;
	in_braces = 1;
	nb_objects = 0;
	while (in_braces)
	{
		++i;
		if (str[i] == '{')
		{
			if (in_braces == 1)
				++nb_objects;
			++in_braces;
		}
		else if (str[i] == '}')
			--in_braces;
	}
	return (nb_objects);
}

static int	init_objects(t_data *data, int nb)
{
	int i;

	i = -1;
	if (!(data->objs = (t_obj *)malloc(sizeof(t_obj) * nb)))
		return (-1);
	while (++i < nb)
	{
		data->objs[i].r = 100;
		data->objs[i].ambi = 1;
		data->objs[i].diff = 1;
		data->objs[i].spec = 1;
		data->objs[i].color.c = 0xA600A6;
		data->objs[i].pos = (t_vec){0, 0, 2000};
		data->objs[i].dir = (t_vec){1, 1, 0};
		data->objs[i].normal = (t_vec){1, 1, 0.001};
		data->objs[i].intersect = intersect_sphere;
		data->objs[i].get_normal = get_sphere_normal;
	}
	return (0);
}

static void	parse_object(t_obj *object, char *str, int *index)
{
	int i;
	int	in_braces;

	i = 0;
	while (str[i] != '{')
		++i;
	in_braces = 1;
	while (in_braces)
	{
		++i;
		if (str[i] == '\"')
		{
			if (read_quotes(str + i, "\"position\"", &i))
				object->pos = parse_vec(str + i, &i);
			else if (read_quotes(str + i, "\"color\"", &i))
				object->color = parse_color(str + i, &i);
			else if (read_quotes(str + i, "\"direction\"", &i))
				object->dir = parse_vec(str + i, &i);
			else if (read_quotes(str + i, "\"normal\"", &i))
				object->normal = parse_vec(str + i, &i);
			else if (read_quotes(str + i, "\"radius\"", &i))
				object->r = parse_nb(str + i, &i);
			else if (read_quotes(str + i, "\"ambient\"", &i))
				object->ambi = parse_nb(str + i, &i);
			else if (read_quotes(str + i, "\"diffuse\"", &i))
				object->diff = parse_nb(str + i, &i);
			else if (read_quotes(str + i, "\"specular\"", &i))
				object->spec = parse_nb(str + i, &i);
		}
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
	{
		data->objs[*object_index].intersect = intersect_sphere;
		data->objs[*object_index].get_normal = get_sphere_normal;
	}
	else if (read_quotes(str, "\"plane\"", &i))
	{
		data->objs[*object_index].intersect = intersect_plane;
		data->objs[*object_index].get_normal = get_plane_normal;
	}
	else if (read_quotes(str, "\"cylinder\"", &i))
	{
		/*data->objs[*object_index].intersect = intersect_cylinder;
		data->objs[*object_index].get_normal = get_cylinder_normal;*/
	}
	else if (read_quotes(str, "\"cone\"", &i))
	{
		/*data->objs[*object_index].intersect = intersect_cone;
		data->obks[*object_index].get_normal = get_cone_normal;*/
	}
	else
		return ;
	*index += i;
	parse_object(&data->objs[(*object_index)++], str, index);
}

//	penser à changer le proto en int pour savoir si malloc a réussi ou pas.
//	ça vaut aussi pour parse_lights();
void		parse_objects(t_data *data, char *str, int *index)
{
	int object_index;
	int in_braces;
	int i;

	i = 0;
	while (str[i] != '{')
		++i;
	in_braces = 1;
	if (!(data->nb_objects = get_nb_objects(str + i + 1)))
		return ;
	init_objects(data, data->nb_objects);
	object_index = 0;
	while (in_braces)
	{
		++i;
		if (str[i] == '\"' && object_index < data->nb_objects)
			which_object(data, str + i, index, &object_index);
		else if (str[i] == '{' || str[i] == '}')
			in_braces += (str[i] == '{' ? 1 : -1);
	}
	*index += i;
}
