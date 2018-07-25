/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caustic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:01:48 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/25 14:39:04 by mlantonn         ###   ########.fr       */
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
	t_vec	r;

	++inter->depth;
	r = get_refrac_ray(g_data, inter, ray);
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

int				init_map(void)
{
	int		i;
	int		j;

	if (!g_data->nb_lights || !g_data->nb_lights_on || !g_data->nb_objects)
		return (-1);
	i = -1;
	j = 0;
	while (++i < g_data->nb_lights)
		if (g_data->lights[i].is_para && !g_data->lights[i].disabled)
			++j;
	if (j >= g_data->nb_lights_on)
		return (-1);
	if (!(g_data->photon_map = (t_photon *)malloc(sizeof(t_photon) \
		* (g_data->nb_lights_on - j) * g_data->photon_total)))
		return (-1);
	return (0);
}

void			get_photon_map(void)
{
	int		i;
	int		j;
	int		index;

	if (init_map())
		return ;
	i = -1;
	index = 0;
	while (++i < g_data->nb_lights)
	{
		if (g_data->lights[i].disabled || g_data->lights[i].is_para)
		{
			++index;
			continue ;
		}
		j = 0;
		while (j < g_data->photon_total)
			if (add_photon(&g_data->photon_map[j \
				+ ((i - index) * g_data->photon_total)], g_data->lights[i]))
				++j;
	}
	g_data->photon_hit = (i - index) * g_data->photon_total;
}
