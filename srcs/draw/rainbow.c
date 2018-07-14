/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:15:54 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/14 05:14:31 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

static int	rb_sphere(t_obj obj, t_vec ray, t_inter *inter)
{
	t_vec	vp;
	double	phi;
	double	u;

	vp = vec_add(inter->origin, vec_multiply(ray, inter->t));
	vp = vec_normalize(vec_substract(vp, obj.pos));
	phi = acos(dot_product(obj.dir, vp));
	u = phi / M_PI;
	return (u * 1530);
}

static int	rb_plane(t_obj obj, t_vec ray, t_inter *inter)
{
	t_vec	vp;
	double	vp_len;

	vp = vec_add(inter->origin, vec_multiply(ray, inter->t));
	vp = vec_substract(vp, obj.pos);
	vp_len = get_length(vp);
	return (((int)(vp_len / (obj.tex_scale * .01))) % 1530);
}

static int	rb_cyl_cone(t_obj obj, t_vec ray, t_inter *inter)
{
	t_vec	vp;
	double	vp_len;
	int		ret;

	vp = vec_add(inter->origin, vec_multiply(ray, inter->t));
	vp = vec_substract(vp, obj.pos);
	vp_len = get_length(vp);
	vp = vec_normalize(vp);
	ret = (dot_product(obj.dir, vp) * vp_len);
	return (abs((int)(ret / (obj.tex_scale * .01))) % 1530);
}

static t_color	rainbow2(t_color ret, double len)
{
	if (len < 765)
	{
		ret.argb.r = 0;
		ret.argb.g = 255;
		ret.argb.b = len - 510;
	}
	else if (len < 1020)
	{
		ret.argb.r = 0;
		ret.argb.g = 1020 - len;
		ret.argb.b = 255;
	}
	else if (len < 1275)
	{
		ret.argb.r = len - 1020;
		ret.argb.g = 0;
		ret.argb.b = 255;
	}
	else
	{
		ret.argb.r = 255;
		ret.argb.g = 0;
		ret.argb.b = 1530 - len;
	}
	return (ret);
}

t_color		rainbow(t_obj obj, t_vec ray, t_inter *inter)
{
	t_color ret;
	int		len;

	if (obj.obj_type == SPHERE)
		len = rb_sphere(obj, ray, inter);
	else if (obj.obj_type == PLANE)
		len = rb_plane(obj, ray, inter);
	else if (obj.obj_type == CYLINDER || obj.obj_type == CONE)
		len = rb_cyl_cone(obj, ray, inter);
	else
		return (obj.color);
	ret = obj.color;
	if (len < 255)
	{
		ret.argb.r = 255;
		ret.argb.g = len;
		ret.argb.b = 0;
	}
	else if (len < 510)
	{
		ret.argb.r = 510 - len;
		ret.argb.g = 255;
		ret.argb.b = 0;
	}
	return (len < 510 ? ret : rainbow2(ret, len));
}
