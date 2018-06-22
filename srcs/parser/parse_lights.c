/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 13:30:41 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/20 19:51:21 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	which_light_variable(t_light *light, char *str, int *index)
{
	if (read_quotes(str + *index, "\"position\"", index))
		light->pos = parse_vec(str + *index, index);
	else if (read_quotes(str + *index, "\"color\"", index))
		light->color = parse_color(str + *index, index);
	else if (read_quotes(str + *index, "\"radius\"", index))
		light->r = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"ambient\"", index))
		light->ambi = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"direction\"", index))
	{
		light->dir = parse_vec(str + *index, index);
		light->is_para = (light->dir.x != 0.0 || light->dir.y != 0.0 \
			|| light->dir.z != 0.0) ? 1 : 0;
	}
}

static void	parse_light(t_light *light, char *str, int *index)
{
	int i;
	int in_braces;

	i = 0;
	in_braces = 1;
	while (in_braces)
	{
		++i;
		if (str[i] == '\"' && in_braces == 1)
			which_light_variable(light, str, &i);
		if (str[i] == '{' || str[i] == '}')
			in_braces += (str[i] == '{' ? 1 : -1);
	}
	if (light->ambi > 1 || light->ambi < 0)
		light->ambi = light->ambi > 1 ? 1 : 0;
	*index += i;
}

void		parse_lights(t_data *data, char *str, int *index)
{
	int light_index;
	int in_braces;
	int i;

	i = -1;
	while (str[++i] != '[');
	in_braces = 1;
	if (!(data->nb_lights = get_nb_lights(str + i)))
		return ;
	data->nb_lights_on = data->nb_lights;
	if (init_lights(data, data->nb_lights))
	{
		data->nb_lights = 0;
		free(str);
		exit_all(data);
	}
	light_index = 0;
	while (in_braces)
	{
		if (str[++i] == '{' && light_index < data->nb_lights)
			parse_light(&data->lights[light_index++], str + i, &i);
		else if (str[i] == '[' || str[i] == ']')
			in_braces += (str[i] == '[' ? 1 : -1);
	}
	*index += i;
}
