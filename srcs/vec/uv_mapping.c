/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:56:00 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/03 19:44:26 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	uv_mapping_sphere(t_obj obj, t_vec ray, t_inter *inter)
{
	t_vec	vp;
	double	phi;
	double	u;
	double	v;

	vp = vec_add(inter->origin, vec_multiply(ray, inter->t));
	vp = vec_normalize(vec_substract(vp, obj.pos));
	phi = acos(dot_product(obj.dir, vp));
	u = (acos(dot_product(vp, obj.y_dir) / sin(phi))) / (2 * M_PI);
	if (dot_product(obj.z_dir, vp) < 0)
		u = 1 - u;
	v = phi / M_PI;
	inter->uv.x = (int)(obj.tex->size.x * u);
	inter->uv.y = (int)(obj.tex->size.y * v);
}

void	uv_mapping_plane(t_obj obj, t_vec ray, t_inter *inter)
{
	t_vec	vp;
	double	vp_len;

	vp = vec_add(inter->origin, vec_multiply(ray, inter->t));
	vp = vec_substract(vp, obj.pos);
	vp_len = get_length(vp);
	vp = vec_normalize(vp);
	inter->uv.x = (int)(dot_product(vp, obj.y_dir) * vp_len * obj.tex_scale) \
		+ (obj.tex->size.x / 2) - obj.tex_pos.x;
	inter->uv.y = (int)(dot_product(vp, obj.z_dir) * vp_len * obj.tex_scale) \
		+ (obj.tex->size.y / 2) + obj.tex_pos.y;
	if (obj.tex_repeat)
	{
		inter->uv.x %= obj.tex->size.x;
		inter->uv.y %= obj.tex->size.y;
		if (inter->uv.x < 0)
			inter->uv.x = obj.tex->size.x + inter->uv.x;
		if (inter->uv.y < 0)
			inter->uv.y = obj.tex->size.y + inter->uv.y;
	}
}

void	uv_mapping_cyl_cone(t_obj obj, t_vec ray, t_inter *inter)
{
	t_vec	vp;
	double	vp_len;
	double	u;

	vp = vec_add(inter->origin, vec_multiply(ray, inter->t));
	vp = vec_substract(vp, obj.pos);
	vp_len = get_length(vp);
	vp = vec_normalize(vp);
	u = (acos(dot_product(vp, obj.y_dir) \
		/ sin(acos(dot_product(obj.dir, vp))))) / (2 * M_PI);
	if (dot_product(obj.z_dir, vp) < 0)
		u = 1 - u;
	inter->uv.y = (obj.tex->size.y / 2) - (int)(dot_product(obj.dir, vp) \
		* vp_len * obj.tex_scale) + obj.tex_pos.x;
	if (obj.tex_repeat)
	{
		inter->uv.y %= obj.tex->size.y;
		if (inter->uv.y < 0)
			inter->uv.y = obj.tex->size.y + inter->uv.y;
	}
	inter->uv.x = (int)(obj.tex->size.x * u);
}

int		uv_mapping(t_obj obj, t_vec ray, t_inter *inter)
{
	if (obj.tex_limit && !obj.tex_repeat && obj.obj_type != SPHERE)
		return (obj.tex->pxl[inter->uv.x + (inter->uv.y * obj.tex->size.x)]);
	if (obj.obj_type == SPHERE)
		uv_mapping_sphere(obj, ray, inter);
	else if (obj.obj_type == PLANE)
		uv_mapping_plane(obj, ray, inter);
	else if (obj.obj_type == CYLINDER || obj.obj_type == CONE)
		uv_mapping_cyl_cone(obj, ray, inter);
	else
		return (obj.color.c);
	if (inter->uv.x >= 0 && inter->uv.x < obj.tex->size.x \
		&& inter->uv.y >= 0 && inter->uv.y < obj.tex->size.y)
		return (obj.tex->pxl[inter->uv.x + (inter->uv.y * obj.tex->size.x)]);
	return (obj.color.c);
}
