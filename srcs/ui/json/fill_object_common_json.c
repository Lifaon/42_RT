#include "ui.h"

static char		*fill_limits_json(char *str, t_obj *obj)
{
	str = my_strcopy(str, ",\n\t\t\t\"limit\" : ");
	if (obj->limited == LIMIT_NONE)
		str = my_strcopy(str, "\"none\"");
	else
	{
		if (obj->limited == LIMIT_AXE)
			str = my_strcopy(str, "\"axe\"");
		else if (obj->limited == LIMIT_SPHERE)
			str = my_strcopy(str, "\"sphere\"");
		else if (obj->limited == LIMIT_RECTANGLE)
			str = my_strcopy(str, "\"rectangle\"");
		else if (obj->limited == LIMIT_CIRCLE)
			str = my_strcopy(str, "\"circle\"");
		else if (obj->limited == LIMIT_CYLINDER)
			str = my_strcopy(str, "\"cylinder\"");
		else if (obj->limited == LIMIT_CONE)
			str = my_strcopy(str, "\"cone\"");
		str = my_strcopy(str, ",\n\t\t\t\"min\" : ");
		str = strcpy_vec(str, obj->min);
		str = my_strcopy(str, ",\n\t\t\t\"max\" : ");
		str = strcpy_vec(str, obj->max);
	}
	return (str);
}

static char		*fill_tex_file_json(char *str, t_obj *obj)
{
	if (obj->tex)
	{
		str = my_strcopy(str, ",\n\t\t\t\"texture\" : \"");
		str = my_strcopy(str, obj->tex_filename);
		str = my_strcopy(str, "\"");
		str = my_strcopy(str, ",\n\t\t\t\"tex_pos\" : ");
		str = strcpy_pt(str, obj->tex_pos);
		str = my_strcopy(str, ",\n\t\t\t\"tex_scale\" : ");
		str = strcpy_db(str, obj->tex_scale);
		str = my_strcopy(str, ",\n\t\t\t\"tex_repeat\" : ");
		str = strcpy_int(str, obj->tex_repeat);
		str = my_strcopy(str, ",\n\t\t\t\"tex_limit\" : ");
		str = strcpy_int(str, obj->tex_limit);
		str = my_strcopy(str, ",\n\t\t\t\"tex_trans\" : ");
		str = strcpy_db(str, obj->tex_trans);
	}
	return (str);
}

static char		*fill_bump_json(char *str, t_obj *obj)
{
	str = my_strcopy(str, ",\n\t\t\t\"bump_flag\" : ");
	str = strcpy_int(str, obj->bump_flag);
	str = my_strcopy(str, ",\n\t\t\t\"bump_scale\" : ");
	str = strcpy_int(str, obj->bump_scale);
	str = my_strcopy(str, ",\n\t\t\t\"bump_intensity\" : ");
	str = strcpy_db(str, obj->bump_intensity);
	return (str);
}

static char		*fill_textures_json(char *str, t_obj *obj)
{
	if (obj->color_type)
	{
		str = my_strcopy(str, ",\n\t\t\t\"color2\" : ");
		str = strcpy_color(str, obj->color2);
		str = my_strcopy(str, ",\n\t\t\t\"color_type\" : ");
		str = strcpy_int(str, obj->color_type);
		str = my_strcopy(str, ",\n\t\t\t\"color_scale\" : ");
		str = strcpy_int(str, obj->color_scale);
	}
	if (obj->perl_type != PERLIN_NONE)
	{
		str = my_strcopy(str, ",\n\t\t\t\"perl_type\" : ");
		str = strcpy_int(str, obj->perl_type);
		str = my_strcopy(str, ",\n\t\t\t\"perl_scale\" : ");
		str = strcpy_int(str, obj->perl_scale);
		str = my_strcopy(str, ",\n\t\t\t\"perl_opacity\" : ");
		str = strcpy_db(str, obj->perl_opacity);
	}
	if (obj->bump_flag)
		str = fill_bump_json(str, obj);
	str = fill_tex_file_json(str, obj);
	return (str);
}

char			*fill_object_common_json(char *str, t_obj *obj)
{
	str = my_strcopy(str, ",\n\t\t\t\"position\" : ");
	str = strcpy_vec(str, obj->pos);
	str = my_strcopy(str, ",\n\t\t\t\"specular\" : ");
	str = strcpy_db(str, obj->spec);
	str = my_strcopy(str, ",\n\t\t\t\"color\" : ");
	str = strcpy_color(str, obj->color);
	str = my_strcopy(str, ",\n\t\t\t\"alpha\" : ");
	str = strcpy_db(str, obj->alpha);
	str = my_strcopy(str, ",\n\t\t\t\"trans\" : ");
	str = strcpy_db(str, obj->trans);
	str = my_strcopy(str, ",\n\t\t\t\"shiny\" : ");
	str = strcpy_db(str, obj->shiny);
	str = my_strcopy(str, ",\n\t\t\t\"ior\" : ");
	str = strcpy_db(str, obj->ior);
	str = fill_limits_json(str, obj);
	str = fill_textures_json(str, obj);
	return (str);
}
