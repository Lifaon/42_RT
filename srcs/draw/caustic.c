/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caustic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:01:48 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/24 16:50:31 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int				reflec(t_inter *inter, t_vec ray, t_photon *photon)
{
	t_vec	r;

	++inter->depth;
	r = vec_normalize(vec_add(vec_multiply(\
		inter->normal, dot_product(inter->normal, ray) * -2.0), ray));
	inter->origin = vec_add(inter->ip, vec_multiply(r, 0.3));
	if (other_hit(g_data, r, inter) && inter->depth <= g_data->depth_max)
	{
		photon->pos = inter->ip;
		photon->obj_i = inter->obj_i;
		if (g_data->objs[inter->obj_i].shiny == 0.)
			return (1);
		inter->color = substract_colors((t_color){.c = 0xFFFFFF}, inter->color);
		inter->color = col_multiply(inter->color, \
			g_data->objs[inter->obj_i].shiny);
		photon->color = substract_colors(photon->color, inter->color);
		return (reflec(inter, ray, photon));
	}
	else
		return (0);
	return (1);
}

int				refract(t_inter *inter, t_vec ray, t_photon *photon)
{
	t_vec		r;
	double		dot;
	double		eta;
	double		k;

	++inter->depth;
	dot = dot_product(ray, g_data->objs[inter->obj_i].get_normal(\
		g_data->objs[inter->obj_i], *inter));
	eta = 1. / g_data->objs[inter->obj_i].ior;
	if (dot < 0.)
		dot = -dot;
	else
		eta = g_data->objs[inter->obj_i].ior;
	k = 1.0f - eta * eta * (1.0f - dot * dot);
	if (k < 0.)
	{
		eta = 1.;
		k = 1.0f - dot * dot;
	}
	r = vec_normalize(vec_add(vec_multiply(ray, eta), \
		vec_multiply(inter->normal, eta * dot - sqrt(k))));
	inter->origin = vec_add(inter->ip, vec_multiply(r, 0.3));
	if (other_hit(g_data, r, inter))
	{
		photon->pos = inter->ip;
		photon->obj_i = inter->obj_i;
		if (inter->trans_at_ip == 0)
			return (1);
		inter->color = substract_colors((t_color){.c = 0xFFFFFF}, inter->color);
		inter->color = col_multiply(inter->color, inter->trans_at_ip);
		photon->color = substract_colors(photon->color, inter->color);
		return (refract(inter, ray, photon));
	}
	else
		return (0);
	return (1);
}

t_vec			get_random_direction(void)
{
	t_vec		dir;
	t_vec		angle;

	dir = (t_vec){0, -1, 0};
	angle.x = (36000. * rand() / (RAND_MAX + 1.0)) * .01;
	angle.y = (36000. * rand() / (RAND_MAX + 1.0)) * .01;
	angle.z = (36000. * rand() / (RAND_MAX + 1.0)) * .01;
	dir = all_rotations(dir, angle);
	return (dir);
}

int				add_photon(t_photon *photon, t_light light)
{
	t_photon	new;
	t_inter		inter;
	t_vec		dir;

	inter.min_dist = 0.01;
	inter.origin = light.pos;
	inter.depth = 0;
	dir = get_random_direction();
	new.obj_i = 0;
	if (!other_hit(g_data, dir, &inter) || (inter.trans_at_ip == 0. \
		&& g_data->objs[inter.obj_i].shiny == 0.))
		return (0);
	inter.color = substract_colors((t_color){.c = 0xFFFFFF}, inter.color);
	inter.color = col_multiply(inter.color, inter.trans_at_ip);
	new.color = substract_colors(light.color, inter.color);
	if (g_data->objs[inter.obj_i].shiny != 0.)
	{
		if (!(reflec(&inter, dir, &new)))
			return (0);
	}
	else if (!(refract(&inter, dir, &new)))
		return (0);
	*photon = new;
	return (1);
}

void			get_photon_map(void)
{
	int			i;
	int			j;
	int			index;

	if (!g_data->nb_lights || !g_data->nb_lights_on || !g_data->nb_objects)
		return ;
	if (!(g_data->photon_map = (t_photon *)malloc(sizeof(t_photon) \
		* g_data->nb_lights_on * g_data->photon_total)))
		return ;
	index = 0;
	i = -1;
	while (++i < g_data->nb_lights)
	{
		if (g_data->lights[i].disabled || g_data->lights[i].is_para)
			continue ;
		j = -1;
		while (++j < g_data->photon_total)
			if (add_photon(&g_data->photon_map[index], g_data->lights[i]))
				++index;
	}
	g_data->photon_hit = index;
	printf("photon_hit = %d\n", index);
}
