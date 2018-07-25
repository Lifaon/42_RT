/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_options_json.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:45:56 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/25 16:30:36 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static char		*fill_caustic(char *str)
{
	str = my_strcopy(str, ",\n\t\t\"photon_total\" : ");
	str = strcpy_int(str, g_data->photon_total);
	str = my_strcopy(str, ",\n\t\t\"photon_ppx\" : ");
	str = strcpy_int(str, g_data->photon_ppx);
	str = my_strcopy(str, ",\n\t\t\"photon_size\" : ");
	str = strcpy_db(str, g_data->photon_size);
	return (str);
}

static char		*fill_filters(char *str)
{
	str = my_strcopy(str, ",\n\t\t\"cel_shading\" : ");
	str = strcpy_int(str, g_data->cel_shading);
	str = my_strcopy(str, ",\n\t\t\"filter\" : ");
	str = strcpy_int(str, g_data->filter);
	str = my_strcopy(str, ",\n\t\t\"stereo_scale\" : ");
	str = strcpy_int(str, g_data->stereo_scale);
	return (str);
}

static char		*fill_dof(char *str)
{
	str = my_strcopy(str, ",\n\t\t\"depth_of_field\" : ");
	str = strcpy_int(str, g_data->depth_of_field);
	str = my_strcopy(str, ",\n\t\t\"dof_coeff\" : ");
	str = strcpy_db(str, g_data->dof_coeff);
	return (str);
}

char		*fill_options_json(char *str)
{
	str = my_strcopy(str, "\t\"options\" :\n\t{\n");
	str = my_strcopy(str, "\t\t\"active_cam\" : ");
	str = strcpy_int(str, g_data->i);
	if (g_data->px > 1)
	{
		str = my_strcopy(str, ",\n\t\t\"px\" : ");
		str = strcpy_int(str, g_data->px);
	}
	else if (g_data->aa > 1)
	{
		str = my_strcopy(str, ",\n\t\t\"aa\" : ");
		str = strcpy_int(str, g_data->aa);
	}
	str = fill_filters(str);
	str = my_strcopy(str, ",\n\t\t\"depth_max\" : ");
	str = strcpy_int(str, g_data->depth_max);
	if (g_data->depth_of_field > -1)
		str = fill_dof(str);
	str = my_strcopy(str, ",\n\t\t\"caustic_flag\" : ");
	str = strcpy_int(str, g_data->caustic_flag);
	if (g_data->caustic_flag == 1)
		str = fill_caustic(str);
	str = my_strcopy(str, "\n\t}\n}");
	return (str);
}
