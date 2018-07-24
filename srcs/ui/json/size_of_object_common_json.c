/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_object_common_json.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:42:10 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 20:01:50 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

static size_t		size_of_limits_json(t_obj *obj)
{
	size_t		size;

	size = ft_strlen(",\n\t\t\t\"limit\" : ");
	if (obj->limited == LIMIT_NONE)
		size += ft_strlen("\"none\"");
	else
	{
		if (obj->limited == LIMIT_AXE)
			size += ft_strlen("\"axe\"");
		else if (obj->limited == LIMIT_SPHERE)
			size += ft_strlen("\"sphere\"");
		else if (obj->limited == LIMIT_RECTANGLE)
			size += ft_strlen("\"rectangle\"");
		else if (obj->limited == LIMIT_CIRCLE)
			size += ft_strlen("\"circle\"");
		else if (obj->limited == LIMIT_CYLINDER)
			size += ft_strlen("\"cylinder\"");
		else if (obj->limited == LIMIT_CONE)
			size += ft_strlen("\"cone\"");
		size += ft_strlen(",\n\t\t\t\"min\" : ");
		size += size_vec(obj->min);
		size += ft_strlen(",\n\t\t\t\"max\" : ");
		size += size_vec(obj->max);
	}
	return (size);
}

static size_t		size_of_tex_file_json(t_obj *obj)
{
	size_t		size;

	size = ft_strlen(",\n\t\t\t\"texture\" : \"");
	size += ft_strlen(obj->tex_filename);
	size += ft_strlen("\"");
	size += ft_strlen(",\n\t\t\t\"tex_pos\" : ");
	size += size_pt(obj->tex_pos);
	size += ft_strlen(",\n\t\t\t\"tex_scale\" : ");
	size += size_int(obj->tex_scale);
	size += ft_strlen(",\n\t\t\t\"tex_repeat\" : ");
	size += size_int(obj->tex_repeat);
	size += ft_strlen(",\n\t\t\t\"tex_limit\" : ");
	size += size_int(obj->tex_limit);
	size += ft_strlen(",\n\t\t\t\"tex_trans\" : ");
	size += size_double(obj->tex_trans);
	return (size);
}

static size_t		size_of_bump_json(t_obj *obj)
{
	size_t		size;

	size = 0;
	if (obj->bump_flag)
	{
		size = ft_strlen(",\n\t\t\t\"bump_flag\" : ");
		size += size_int(obj->bump_flag);
		size += ft_strlen(",\n\t\t\t\"bump_scale\" : ");
		size += size_int(obj->bump_scale);
		size += ft_strlen(",\n\t\t\t\"bump_intensity\" : ");
		size += size_double(obj->bump_intensity);
	}
	return (size);
}

static size_t		size_of_textures_json(t_obj *obj)
{
	size_t		size;

	size = 0;
	if (obj->color_type != COLOR_SIMPLE)
	{
		size += ft_strlen(",\n\t\t\t\"color2\" : ");
		size += size_color(obj->color2);
		size += ft_strlen(",\n\t\t\t\"color_type\" : ");
		size += size_int(obj->color_type);
		size += ft_strlen(",\n\t\t\t\"color_scale\" : ");
		size += size_int(obj->color_scale);
	}
	if (obj->perl_type != PERLIN_NONE)
	{
		size += ft_strlen(",\n\t\t\t\"perl_type\" : ");
		size += size_int(obj->perl_type);
		size += ft_strlen(",\n\t\t\t\"perl_scale\" : ");
		size += size_int(obj->perl_scale);
		size += ft_strlen(",\n\t\t\t\"perl_opacity\" : ");
		size += size_double(obj->perl_opacity);
	}
	size += size_of_bump_json(obj);
	if (obj->tex)
		size += size_of_tex_file_json(obj);
	return (size);
}

size_t			size_of_object_common_json(t_obj *obj)
{
	size_t		size;

	size = ft_strlen(",\n\t\t\t\"position\" : ");
	size += size_vec(obj->pos);
	size += ft_strlen("\t\t\t\"specular\" : ");
	size += size_double(obj->spec);
	size += ft_strlen(",\n\t\t\t\"color\" : ");
	size += size_color(obj->color);
	size += ft_strlen(",\n\t\t\t\"alpha\" : ");
	size += size_double(obj->alpha);
	size += ft_strlen(",\n\t\t\t\"trans\" : ");
	size += size_double(obj->trans);
	size += ft_strlen(",\n\t\t\t\"shiny\" : ");
	size += size_double(obj->shiny);
	size += ft_strlen(",\n\t\t\t\"ior\" : ");
	size += size_double(obj->ior);
	size += size_of_limits_json(obj);
	size += size_of_textures_json(obj);
	return (size);
}
