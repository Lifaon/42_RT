/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:59:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/08 14:43:02 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	get_sphere_normal(t_obj sphere, t_inter inter)
{
	t_vec normal;

	normal = vec_substract(inter.ip, sphere.pos);
	normal.x /= sphere.r;
	normal.y /= sphere.r;
	normal.z /= sphere.r;
	return (normal);
}

/*
**	Plane normal is constant.
*/
t_vec	get_plane_normal(t_obj plane, t_inter inter)
{
	return (plane.normal);
}
