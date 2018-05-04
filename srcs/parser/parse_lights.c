/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 13:30:41 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/04 16:33:49 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	get_nb_lights(char *str)
{
	int i;
	int in_brace;
	int	nb_lights;

	i = -1;
	in_brace = 0;
	nb_lights = 0;
	while (str[++i] != ']' || in_brace)
	{
		if (str[i] == '{')
		{
			if (!in_brace)
				++nb_lights;
			++in_brace;
		}
		else if (str[i] == '}')
			--in_brace;
	}
	return (nb_lights);
}

static int	init_lights(t_data *data, int nb)
{
	int i;

	i = -1;
	if (!(data->lights = (t_light *)malloc(sizeof(t_light) * nb)))
		return (-1);
	while (++i < nb)
	{
		data->lights[i].is_para = 0;
		data->lights[i].r = 1;
		data->lights[i].pos = (t_vec){0.0, 0.0, 0.0};
		data->lights[i].dir = (t_vec){0.0, 0.0, 0.0};
		data->lights[i].color.c = 0xFFFFFF;
	}
	return (0);
}

static void	parse_light(t_light *light, char *str, int *index)
{
	int i;

	i = -1;
	while (str[++i] != '}')
		if (str[i] == '\"')
		{
			if (read_quotes(str + i, "\"position\"", &i))
				light->pos = parse_vec(str + i, &i);
			else if (read_quotes(str + i, "\"color\"", &i))
				light->color = parse_color(str + i, &i);
			else if (read_quotes(str + i, "\"direction\"", &i))
			{
				light->dir = parse_vec(str + i, &i);
				light->is_para = (light->dir.x != 0.0 || light->dir.y != 0.0 \
					|| light->dir.z != 0.0) ? 1 : 0;
			}
			else if (read_quotes(str + i, "\"radius\"", &i))
				light->r = parse_nb(str + i, &i);
		}
	*index += i;
}

void		parse_lights(t_data *data, char *str, int *index)
{
	int light_index;
	int i;

	i = 0;
	while (str[i] != '[')
		++i;
	if (!(data->nb_lights = get_nb_lights(str + i)))
		return ;
	init_lights(data, data->nb_lights);
	light_index = 0;
	while (str[++i] != ']')
		if (str[i] == '{' && light_index < data->nb_lights)
			parse_light(&data->lights[light_index++], str + i, &i);
	*index += i;
}
