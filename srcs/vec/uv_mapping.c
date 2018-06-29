/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:56:00 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/29 20:36:52 by mlantonn         ###   ########.fr       */
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
	return (obj.tex->pxl[((int)(obj.tex->size.x * u) + \
		((int)(obj.tex->size.y * v) * obj.tex->size.x))]);
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
	u = (int)(dot_product(vp, obj.y_dir) * vp_len) + (obj.tex->size.x / 2);
	v = (int)(dot_product(vp, obj.z_dir) * vp_len) \
		+ (obj.tex->size.y / 2);
	if (u >= 0 && u < obj.tex->size.x && v >= 0 && v < obj.tex->size.y)
		return (obj.tex->pxl[u + (v * obj.tex->size.x)]);
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
	v = -(int)(dot_product(obj.dir, vp) * vp_len) % obj.tex->size.y;
	if (v < 0)
		v = obj.tex->size.y + v;
	if (u >= 0 && u <= 1 && v >= 0 && v < obj.tex->size.y)
		return (obj.tex->pxl[(int)(obj.tex->size.x * u) \
		+ (v * obj.tex->size.x)]);
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
