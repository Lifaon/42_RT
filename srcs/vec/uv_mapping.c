/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:56:00 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/30 04:44:52 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

static int	uv_mapping_sphere(t_obj obj, t_inter *inter)
{
	t_vec	vp;
	double	phi;
	double	u;
	double	v;

	vp = vec_normalize(vec_substract(inter->ip, obj.pos));
	phi = acos(dot_product(obj.dir, vp));
	u = (acos(dot_product(vp, obj.y_dir) / sin(phi))) / (2 * M_PI);
	if (dot_product(obj.z_dir, vp) < 0)
		u = 1 - u;
	v = phi / M_PI;
	return (obj.tex[((int)(obj.tex_size.x * u) \
		+ ((int)(obj.tex_size.y * v) * obj.tex_size.x))].c);
}

static int	uv_mapping_plane(t_obj obj, t_inter *inter)
{
	t_vec	vp;
	double	vp_len;
	int		u;
	int		v;

	vp = vec_substract(inter->ip, obj.pos);
	vp_len = get_length(vp);
	vp = vec_normalize(vp);
	u = (int)(dot_product(vp, obj.y_dir) * vp_len) + (obj.tex_size.x / 2);
	v = (int)(dot_product(vp, obj.z_dir) * vp_len) + (obj.tex_size.y / 2);
	//u -= 1000;
	//v += 1000;
	//u %= obj.tex_size.x;
	//v %= obj.tex_size.y;
	//if (u < 0)
	//	u = obj.tex_size.x + u;
	//if (v < 0)
	//	v = obj.tex_size.y + v;
	if (u >= 0 && u < obj.tex_size.x && v >= 0 && v < obj.tex_size.y)
		return (obj.tex[u + (v * obj.tex_size.x)].c);
	return (obj.color.c);
}

static int	uv_mapping_cyl_cone(t_obj obj, t_inter *inter)
{
	t_vec	vp;
	double	phi;
	double	vp_len;
	double	u;
	int		v;

	vp = vec_substract(inter->ip, obj.pos);
	vp_len = get_length(vp);
	vp = vec_normalize(vp);
	phi = acos(dot_product(obj.dir, vp));
	u = (acos(dot_product(vp, obj.y_dir) / sin(phi))) / (2 * M_PI);
	if (dot_product(obj.z_dir, vp) < 0)
		u = 1 - u;
	v = (obj.tex_size.y / 2) - (int)(dot_product(obj.dir, vp) * vp_len);
	//v += 1000;
	//v %= obj.tex_size.y;
	//if (v < 0)
	//	v = obj.tex_size.y + v;
	if (u >= 0 && u <= 1 && v >= 0 && v < obj.tex_size.y)
		return (obj.tex[(int)(obj.tex_size.x * u) \
		+ (v * obj.tex_size.x)].c);
	return (obj.color.c);
}

int		uv_mapping(t_obj obj, t_inter *inter)
{
	if (obj.obj_type == SPHERE)
		return (uv_mapping_sphere(obj, inter));
	else if (obj.obj_type == PLANE)
		return (uv_mapping_plane(obj, inter));
	else if (obj.obj_type == CYLINDER || obj.obj_type == CONE)
		return (uv_mapping_cyl_cone(obj, inter));
	return (obj.color.c);
}
