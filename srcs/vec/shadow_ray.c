/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 05:22:06 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/24 18:13:00 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		light_path_is_blocked(t_obj *objs, t_ray light, int index)
{
	double	length;
	double	t;
	int		i;

	length = get_length(light.d);
	light.d = vec_normalize(light.d);
	i = -1;
	while(++i < 2)
	{
		if (i == index)
			continue ;
		/*
		**	là il faudrait faire en sorte de check si on a une intersection
		**	entre l'objet touché et la source de lumière
		*/
	}
	return (0);
}

int		shadow_ray(t_obj *objs, t_ray light, int index)
{
	double	dot;
	double	t;
	int		i;

	objs[index].norm = objs[index].get_normal(objs[index]);
	light.d = vec_substract(objs[index].pi, light.o);
	//if (light_path_is_blocked(objs, light, index))
	//	return (0);
	dot = dot_product(vec_normalize(light.d), vec_normalize(objs[index].norm));
	if (dot >= 0)
		return (0xFF * dot);
	return (0);
}
