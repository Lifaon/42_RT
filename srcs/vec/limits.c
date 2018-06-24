/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 20:07:59 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/24 02:29:56 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int		limit_sphere(t_obj sphere, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	t_vec	len;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_normalize(vec_substract(ip, sphere.pos));
	len.x = dot_product(ip, sphere.dir) * sphere.r;
	len.y = dot_product(ip, sphere.y_dir) * sphere.r;
	len.z = dot_product(ip, sphere.z_dir) * sphere.r;
	if (sphere.min.x <= len.x && len.x <= sphere.max.x && \
		sphere.min.y <= len.y && len.y <= sphere.max.y && \
		sphere.min.z <= len.z && len.z <= sphere.max.z)
		return (1);
	return (0);
}

int		limit_rectangle(t_obj plane, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	double	ip_len;
	double	leny;
	double	lenz;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, plane.pos);
	ip_len = get_length(ip);
	ip = vec_normalize(ip);
	leny = dot_product(ip, plane.y_dir) * ip_len;
	lenz = dot_product(ip, plane.z_dir) * ip_len;
	if (plane.min.x <= leny && leny <= plane.max.x && \
		plane.min.y <= lenz && lenz <= plane.max.y)
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
	if (plane.min.x <= len && len <= plane.max.x)
		return (1);
	return (0);
}

int		limit_cyl(t_obj cyl, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	t_vec	len;
	double	ip_len;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, cyl.pos);
	ip_len = dot_product(ip, ip);
	ip = vec_normalize(ip);
	len.x = sqrt(fabs(ip_len - (cyl.r * cyl.r)));
	if (dot_product(ip, cyl.dir) < 0)
		len.x *= -1;
	ip_len = sqrt(ip_len);
	len.y = dot_product(cyl.y_dir, ip) * ip_len;
	len.z = dot_product(cyl.z_dir, ip) * ip_len;
	if (cyl.min.x <= len.x && len.x <= cyl.max.x && \
		cyl.min.y <= len.y && len.y <= cyl.max.y && \
		cyl.min.z <= len.z && len.z <= cyl.max.z)
		return (1);
	return (0);
}

int		limit_cone(t_obj cone, t_vec ray, t_inter *inter)
{
	t_vec	ip;
	t_vec	len;
	double	ip_len;

	ip = vec_add(inter->origin, vec_multiply(ray, inter->t));
	ip = vec_substract(ip, cone.pos);
	ip_len = get_length(ip);
	ip = vec_normalize(ip);
	len.x = dot_product(cone.dir, ip) * ip_len;
	len.y = dot_product(cone.y_dir, ip) * ip_len;
	len.z = dot_product(cone.z_dir, ip) * ip_len;
	if (cone.min.x <= len.x && len.x <= cone.max.x && \
		cone.min.y <= len.y && len.y <= cone.max.y && \
		cone.min.z <= len.z && len.z <= cone.max.z)
		return (1);
	return (0);
}
