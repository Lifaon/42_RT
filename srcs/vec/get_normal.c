/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:59:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/24 18:31:07 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	get_sphere_normal(t_obj sphere)
{
	t_vec normal;

	normal = vec_substract(sphere.c, sphere.pi);
	normal.x /= sphere.r;
	normal.y /= sphere.r;
	normal.z /= sphere.r;
	return (normal);
}

/*
**	Le plan ne change pas de normale.
*/
t_vec	get_plane_normal(t_obj plane)
{
	return (plane.norm);
}
