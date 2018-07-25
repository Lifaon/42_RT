/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:50:10 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/25 14:11:44 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	which_option2(t_data *data, char *str, int *index)
{
	if (read_quotes(str + *index, "\"caustic_flag\"", index))
		data->caustic_flag = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"photon_total\"", index))
		data->photon_total = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"photon_ppx\"", index))
		data->photon_ppx = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"photon_size\"", index))
		data->photon_size = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"stereo_scale\"", index))
		data->stereo_scale = parse_nb(str + *index, index);
}

static void	which_option(t_data *data, char *str, int *index)
{
	if (read_quotes(str + *index, "\"active_cam\"", index))
		data->i = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"aa\"", index))
		data->aa = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"px\"", index))
		data->px = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"depth_of_field\"", index))
		data->depth_of_field = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"dof_coeff\"", index))
		data->dof_coeff = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"cel_shading\"", index))
		data->cel_shading = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"filter\"", index))
		data->filter = parse_nb(str + *index, index);
	else if (read_quotes(str + *index, "\"depth_max\"", index))
		data->depth_max = parse_nb(str + *index, index);
	else
		which_option2(data, str, index);
}

void		parse_options(t_data *data, char *str, int *index)
{
	int i;
	int in_braces;

	i = 0;
	while (str[i] != '{')
		++i;
	in_braces = 1;
	while (in_braces)
	{
		++i;
		if (str[i] == '\"' && in_braces == 1)
			which_option(data, str, &i);
		if (str[i] == '{' || str[i] == '}')
			in_braces += (str[i] == '{' ? 1 : -1);
	}
	*index += i;
}
