/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_object_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 20:40:19 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/24 20:44:43 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	parse_limit(t_obj *object, char *str, int *index)
{
	int i;

	i = *index;
	while (str[i] && str[i] != ':')
		++i;
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

static void	which_object_variable3(t_obj *object, char *str, int *index)
{
	if (read_quotes(str + *index, "\"tex_pos\"", index))
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

static void	which_object_variable2(t_obj *object, char *str, int *index)
{
	if (read_quotes(str + *index, "\"bump_intensity\"", index))
		object->bump_intensity = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"bump_scale\"", index))
		object->bump_scale = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"perl_scale\"", index))
		object->perl_scale = parse_nb(str + *index, index);
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
	else
		which_object_variable3(object, str, index);
}

void		which_object_variable(t_obj *object, char *str, int *index)
{
	if (read_quotes(str + *index, "\"position\"", index))
		object->pos = parse_vec(str + *index, index);
	else if (read_quotes(str + *index, "\"radius\"", index))
		object->r = fabs(parse_nb(str + *index, index));
	else if (read_quotes(str + *index, "\"color\"", index))
		object->color = parse_color(str + *index, index);
	else if (read_quotes(str + *index, "\"color2\"", index))
		object->color2 = parse_color(str + *index, index);
	else if (read_quotes(str + *index, "\"color_type\"", index))
		object->color_type = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"color_scale\"", index))
		object->color_scale = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"perl_scale\"", index))
		object->perl_scale = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"perl_type\"", index))
		object->perl_type = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"perl_opacity\"", index))
		object->perl_opacity = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"bump_flag\"", index))
		object->bump_flag = parse_nb(str + *index, index);
	else
		which_object_variable2(object, str, index);
}
