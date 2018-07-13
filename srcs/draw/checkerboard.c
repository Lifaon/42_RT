/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:44:26 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/13 04:07:24 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	cb_sphere(t_obj obj, t_vec ray, t_inter *inter)
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
	inter->uv.x = (int)((obj.checkerboard * 2) * u);
	inter->uv.y = (int)((obj.checkerboard * 2) * v);
}

static void	cb_plane(t_obj obj, t_vec ray, t_inter *inter)
{
	t_vec	vp;
	double	vp_len;

	vp = vec_add(inter->origin, vec_multiply(ray, inter->t));
	vp = vec_substract(vp, obj.pos);
	vp_len = get_length(vp);
	vp = vec_normalize(vp);
	inter->uv.x = ((int)(dot_product(vp, obj.y_dir) * vp_len));
	inter->uv.y = ((int)(dot_product(vp, obj.z_dir) * vp_len));
	if (inter->uv.x < 0)
		inter->uv.x -= (obj.checkerboard * 2);
	if (inter->uv.y < 0)
		inter->uv.y -= (obj.checkerboard * 2);
	inter->uv.x /= (obj.checkerboard * 2);
	inter->uv.y /= (obj.checkerboard * 2);
}

static void	cb_cyl_cone(t_obj obj, t_vec ray, t_inter *inter)
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
	inter->uv.y = (int)(dot_product(obj.dir, vp) * vp_len);
	if (inter->uv.y < 0)
		inter->uv.y -= (obj.checkerboard * 2);
	inter->uv.y /= (obj.checkerboard * 2);
	inter->uv.x = (int)(u * (obj.checkerboard * 2));
}

t_color	checkerboard(t_obj obj, t_vec ray, t_inter *inter)
{
	if (obj.obj_type == SPHERE)
		cb_sphere(obj, ray, inter);
	else if (obj.obj_type == PLANE)
		cb_plane(obj, ray, inter);
	else if (obj.obj_type == CYLINDER || obj.obj_type == CONE)
		cb_cyl_cone(obj, ray, inter);
	else
		return (obj.color);
	if (((inter->uv.x + inter->uv.y)) % 2)
		return (obj.color);
	return (obj.color2);
}
