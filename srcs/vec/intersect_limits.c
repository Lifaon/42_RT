/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_limits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 20:07:59 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/22 20:24:08 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int		limit_axe(t_obj obj, t_vec ray, t_inter *inter)
{
	t_vec	ip;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, obj.pos);
	if (ip.x <= obj.limit.axe_max.x && ip.x >= obj.limit.axe_min.x && \
		ip.y <= obj.limit.axe_max.y && ip.y >= obj.limit.axe_min.y && \
		ip.z <= obj.limit.axe_max.z && ip.z >= obj.limit.axe_min.z)
		return (1);
	inter->t = inter->t != inter->t1 ? inter->t1 : inter->t2;
	if (obj.obj_type == PLANE || inter->t < inter->min_dist)
		return (0);
	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, obj.pos);
	if (ip.x <= obj.limit.axe_max.x && ip.x >= obj.limit.axe_min.x && \
		ip.y <= obj.limit.axe_max.y && ip.y >= obj.limit.axe_min.y && \
		ip.z <= obj.limit.axe_max.z && ip.z >= obj.limit.axe_min.z)
		return (1);
	return (0);
}

int		limit_sphere(t_obj sphere, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	t_vec	adj;
	double	len;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, sphere.pos);
	adj = vec_multiply(vec_normalize(sphere.dir), \
		dot_product(vec_normalize(ip), vec_normalize(sphere.dir)) * sphere.r);
	len = get_length(vec_substract(adj, ip));
	if (dot_product(vec_normalize(ip), vec_normalize(sphere.dir)) < 0)
		len *= -1;
	if (sphere.limit.min <= len && len <= sphere.limit.max)
		return (1);
	inter->t = inter->t != inter->t1 ? inter->t1 : inter->t2;
	if (inter->t < inter->min_dist)
		return (0);
	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, sphere.pos);
	adj = vec_multiply(vec_normalize(sphere.dir), \
		dot_product(vec_normalize(ip), vec_normalize(sphere.dir)) * sphere.r);
	len = get_length(vec_substract(adj, ip));
	if (dot_product(vec_normalize(ip), vec_normalize(sphere.dir)) < 0)
		len *= -1;
	if (sphere.limit.min <= len && len <= sphere.limit.max)
		return (1);
	return (0);
}

int		limit_rectangle(t_obj plane, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	t_vec	adjx;
	t_vec	adjy;
	double	len;
	double	len2;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, plane.pos);
	len = get_length(ip);
	ip = vec_normalize(ip);
	adjx = vec_multiply(plane.limit.x, dot_product(ip, plane.limit.x) * len);
	adjy = vec_multiply(plane.limit.y, dot_product(ip, plane.limit.y) * len);
	len = get_length(adjx);
	len2 = get_length(adjy);
	if (len <= plane.limit.min && len <= plane.limit.max)
		return (1);
	return (0);
}

int		limit_circle(t_obj plane, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	double	len;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, plane.pos);
	len = get_length(ip);
	if (plane.limit.min <= len && len <= plane.limit.max)
		return (1);
	return (0);
}

int		limit_cyl(t_obj cyl, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	double	len;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, cyl.pos);
	len = sqrt(fabs(dot_product(ip, ip) - (cyl.r * cyl.r)));
	if (dot_product(ip, cyl.dir) < 0)
		len *= -1;
	if (cyl.limit.min <= len && len <= cyl.limit.max)
		return (1);
	inter->t = inter->t != inter->t1 ? inter->t1 : inter->t2;
	if (inter->t < inter->min_dist)
		return (0);
	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, cyl.pos);
	len = sqrt(fabs(dot_product(ip, ip) - (cyl.r * cyl.r)));
	if (dot_product(ip, cyl.dir) < 0)
		len *= -1;
	if (cyl.limit.min <= len && len <= cyl.limit.max)
		return (1);
	return (0);
}

int		limit_cone(t_obj cone, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	double	len;
	double	adj;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, cone.pos);
	len = dot_product(ip, ip);
	adj = dot_product(vec_normalize(ip), vec_normalize(cone.dir)) * sqrt(len);
	len = sqrt(fabs(len - (adj * adj)));
	if (dot_product(ip, cone.dir) < 0)
		len *= -1;
	if (cone.limit.min <= len && len <= cone.limit.max)
		return (1);
	inter->t = inter->t != inter->t1 ? inter->t1 : inter->t2;
	if (inter->t < inter->min_dist)
		return (0);
	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, cone.pos);
	len = dot_product(ip, ip);
	adj = dot_product(vec_normalize(ip), vec_normalize(cone.dir)) * sqrt(len);
	len = sqrt(fabs(len - (adj * adj)));
	if (dot_product(ip, cone.dir) < 0)
		len *= -1;
	if (cone.limit.min <= len && len <= cone.limit.max)
		return (1);
	return (0);
}
