/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_options_json.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:17:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/26 08:30:45 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static size_t	size_caustic(void)
{
	size_t		size;

	size = ft_strlen(",\n\t\t\"caustic_flag\" : ");
	size += size_int(g_data->caustic_flag);
	if (g_data->caustic_flag == 1)
	{
		size += ft_strlen(",\n\t\t\"photon_total\" : ");
		size += size_int(g_data->photon_total);
		size += ft_strlen(",\n\t\t\"photon_ppx\" : ");
		size += size_int(g_data->photon_ppx);
		size += ft_strlen(",\n\t\t\"photon_size\" : ");
		size += size_double(g_data->photon_size);
	}
	return (size);
}

static size_t	size_filters(void)
{
	size_t		size;

	size = 0;
	size += ft_strlen(",\n\t\t\"cel_shading\" : ");
	size += size_int(g_data->cel_shading);
	size += ft_strlen(",\n\t\t\"filter\" : ");
	size += size_int(g_data->filter);
	size += ft_strlen(",\n\t\t\"stereo_scale\" : ");
	size += size_int(g_data->stereo_scale);
	return (size);
}

static size_t	size_dof(void)
{
	size_t		size;

	size = ft_strlen(",\n\t\t\"depth_of_field\" : ");
	size += size_int(g_data->depth_of_field);
	size += ft_strlen(",\n\t\t\"dof_coeff\" : ");
	size += size_double(g_data->dof_coeff);
	return (size);
}

size_t			size_of_options_json(void)
{
	size_t		size;

	size = ft_strlen("\t\"options\" :\n\t{\n");
	size += ft_strlen("\t\t\"active_cam\" : ");
	size += size_int(g_data->i);
	if (g_data->aa > 1)
	{
		size += ft_strlen(",\n\t\t\"aa\" : ");
		size += size_int(g_data->aa);
	}
	else if (g_data->px > 1)
	{
		size += ft_strlen(",\n\t\t\"px\" : ");
		size += size_int(g_data->px);
	}
	size += ft_strlen(",\n\t\t\"depth_max\" : ");
	size += size_int(g_data->depth_max);
	size += size_filters();
	if (g_data->depth_of_field > -1)
		size += size_dof();
	size += size_caustic();
	size += ft_strlen("\n\t}\n}");
	return (size);
}
