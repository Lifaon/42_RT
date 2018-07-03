/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 22:56:20 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/03 19:06:54 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int		limit_axe(t_obj obj, t_vec ray, t_inter *inter)
{
	t_vec	ip;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, obj.pos);
	if (obj.min.x <= ip.x && ip.x <= obj.max.x && \
		obj.min.y <= ip.y && ip.y <= obj.max.y && \
		obj.min.z <= ip.z && ip.z <= obj.max.z)
		return (1);
	return (0);
}

int		limit_tex(t_obj obj, t_vec ray, t_inter *inter)
{
	if (!obj.tex_limit || !obj.tex || obj.tex_repeat || obj.obj_type == SPHERE)
		return (1);
	if (obj.obj_type == PLANE)
		uv_mapping_plane(obj, ray, inter);
	else if (obj.obj_type == CYLINDER || obj.obj_type == CONE)
		uv_mapping_cyl_cone(obj, ray, inter);
	else
		return (1);
	if (inter->uv.x >= 0 && inter->uv.x < obj.tex->size.x \
		&& inter->uv.y >= 0 && inter->uv.y < obj.tex->size.y)
		return (1);
	if (obj.obj_type == PLANE)
		return (0);
	inter->t = inter->t != inter->t1 ? inter->t1 : inter->t2;
	if (inter->t < inter->min_dist)
		return (0);
	if (obj.obj_type == PLANE)
		uv_mapping_plane(obj, ray, inter);
	else if (obj.obj_type == CYLINDER || obj.obj_type == CONE)
		uv_mapping_cyl_cone(obj, ray, inter);
	if (inter->uv.x >= 0 && inter->uv.x < obj.tex->size.x \
		&& inter->uv.y >= 0 && inter->uv.y < obj.tex->size.y)
		return (1);
	return (0);
}

int		obj_limit(t_obj obj, t_vec ray, t_inter *inter)
{
	if (obj.limited == LIMIT_NONE)
		return (1);
	if (obj.limit(obj, ray, inter))
		return (1);
	if (obj.obj_type == PLANE)
		return (0);
	inter->t = inter->t != inter->t1 ? inter->t1 : inter->t2;
	if (inter->t < inter->min_dist)
		return (0);
	if (obj.limit(obj, ray, inter))
		return (1);
	return (0);
}
