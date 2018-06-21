/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_limits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 20:07:59 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/21 20:42:18 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int		limit_axe(t_obj obj, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	t_vec	max = {obj.r * 0.75, obj.r * 0.75, obj.r * 0.75};
	t_vec	min = {-obj.r * 0.75, -obj.r * 0.75, -obj.r * 0.75};

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, obj.pos);
	if (ip.x <= max.x && ip.x >= min.x && \
		ip.y <= max.y && ip.y >= min.y && \
		ip.z <= max.z && ip.z >= min.z)
		return (1);
	inter->t = inter->t != inter->t1 ? inter->t1 : inter->t2;
	if (inter->t < inter->min_dist)
		return (0);
	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, obj.pos);
	if (ip.x <= max.x && ip.x >= min.x && \
		ip.y <= max.y && ip.y >= min.y && \
		ip.z <= max.z && ip.z >= min.z)
		return (1);
	return (0);
}

int		limit_sphere(t_obj sphere, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	double	adj;
	double	max = 20000;
	double	min = -0;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, sphere.pos);
	adj = dot_product(vec_normalize(ip), vec_normalize(sphere.dir)) * sphere.r;
	if (dot_product(ip, sphere.dir) < 0)
		adj *= -1;
	if (min <= adj && adj <= max)
		return (1);
	inter->t = inter->t != inter->t1 ? inter->t1 : inter->t2;
	if (inter->t < inter->min_dist)
		return (0);
	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, sphere.pos);
	adj = dot_product(vec_normalize(ip), vec_normalize(sphere.dir)) * sphere.r;
	if (dot_product(ip, sphere.dir) < 0)
		adj *= -1;
	if (min <= adj && adj <= max)
		return (1);
	return (0);
}

int		limit_cyl(t_obj cyl, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	double	len;
	double	max = 400;
	double	min = -10000;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, cyl.pos);
	len = get_length(ip);
	len = sqrt(fabs((len * len) - (cyl.r * cyl.r)));
	if (dot_product(ip, cyl.dir) < 0)
		len *= -1;
	if (min <= len && len <= max)
		return (1);
	inter->t = inter->t != inter->t1 ? inter->t1 : inter->t2;
	if (inter->t < inter->min_dist)
		return (0);
	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, cyl.pos);
	len = get_length(ip);
	len = sqrt(fabs((len * len) - (cyl.r * cyl.r)));
	if (dot_product(ip, cyl.dir) < 0)
		len *= -1;
	if (min <= len && len <= max)
		return (1);
	return (0);
}

int		limit_cone(t_obj cone, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	double	hyp;
	double	adj;
	double	opp;
	double	max = 1000;
	double	min = -0;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, cone.pos);
	hyp = get_length(ip);
	adj = dot_product(vec_normalize(ip), vec_normalize(cone.dir)) * hyp;
	opp = sqrt(fabs((hyp * hyp) - (adj * adj)));
	if (dot_product(ip, cone.dir) < 0)
		opp *= -1;
	if (min <= opp && opp <= max)
		return (1);
	inter->t = inter->t != inter->t1 ? inter->t1 : inter->t2;
	if (inter->t < inter->min_dist)
		return (0);
	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, cone.pos);
	hyp = get_length(ip);
	adj = dot_product(vec_normalize(ip), vec_normalize(cone.dir)) * hyp;
	opp = sqrt(fabs((hyp * hyp) - (adj * adj)));
	if (dot_product(ip, cone.dir) < 0)
		opp *= -1;
	if (min <= opp && opp <= max)
		return (1);
	return (0);
}
