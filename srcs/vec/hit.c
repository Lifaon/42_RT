/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:17:41 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/23 19:35:31 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int		hit(t_data *data, t_vec ray, t_inter *inter)
{
	static int		depth = 0;
	double			t;
	int				i;

	t = INFINITY;
	i = -1;
	inter->min_dist = 0;
	inter->origin = data->cam.pos;
	while (++i < data->nb_objects)
	{
		inter->oc = data->objs[i].oc;
		if (data->objs[i].intersect(data->objs[i], ray, inter) && inter->t < t)
		{
			t = inter->t;
			inter->obj_i = i;
		}
	}
	if (t < INFINITY)
	{
		inter->t = t;
		inter->ip = vec_add(data->cam.pos, vec_multiply(ray, inter->t));
		inter->normal = get_normal(ray, data->objs[inter->obj_i], *inter);
		return (1);
	}
	return (0);
}
