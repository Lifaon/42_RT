/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 22:56:20 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/23 23:41:44 by mlantonn         ###   ########.fr       */
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

int		obj_limit(t_obj obj, t_vec ray, t_inter *inter)
{
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
