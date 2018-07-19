/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caustic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:01:48 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/19 07:45:48 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#define PHOTON_NB 100000

t_photon	refract(t_inter *inter, t_vec ray, t_photon photon)
{
	t_vec		r;
	double		coeff;
	double		n_i = 1.0f;
	double		n_t = g_data->objs[inter->obj_i].ior;
	double		angle_i;
	double		angle_t;
	double		dot;
	double		eta;
	double		k;

	if (++inter->depth >= g_data->depth_max)
	{
		photon.color.c = 0;
		return (photon);
	}
	coeff = inter->trans_at_ip;
	dot = dot_product(ray, g_data->objs[inter->obj_i].get_normal(\
		g_data->objs[inter->obj_i], *inter));
	if (!inter->in_object) // on est dans en dehors de l'objet //
		dot = -dot;
	else // on est dans l'objet //
		ft_swap_double(&n_i, &n_t);
	inter->in_object = inter->in_object ? 0 : 1;
	eta = n_i / n_t;
	k = 1.0f - eta * eta * (1.0f - dot * dot);
	if (k < 0.0f) // no refraction car full reflection interne
		return (photon);
	angle_i = acos(dot);
	angle_t = asin((n_i * sin(angle_i)) / n_t);
	r = vec_normalize(vec_add(vec_multiply(ray, eta), \
		vec_multiply(inter->normal, eta * dot - sqrt(k))));
	inter->origin = vec_add(inter->ip, vec_multiply(r, 0.3));
	if (other_hit(g_data, r, inter))
	{
		photon.pos = inter->ip;
		if (inter->trans_at_ip == 0)
			return (photon);
		inter->color = substract_colors((t_color){.c = 0xFFFFFF}, inter->color);
		inter->color = col_multiply(inter->color, inter->trans_at_ip);
		photon.color = substract_colors(photon.color, inter->color);
		photon.obj_i = inter->obj_i;
		return (refract(inter, ray, photon));
	}
	else
		photon.color.c = 0;
	return (photon);
}

t_vec		get_random_direction(void)
{
	t_vec	dir;
	t_vec	angle;

	dir = (t_vec){0, -1, 0};
	angle.x = (int)(360. * rand() / (RAND_MAX + 1.0));
	angle.y = (int)(360. * rand() / (RAND_MAX + 1.0));
	angle.z = (int)(360. * rand() / (RAND_MAX + 1.0));
	dir = all_rotations(dir, angle);
	return (dir);
}

t_photon	add_photon(t_light light)
{
	t_photon	photon;
	t_inter		inter;
	t_vec		dir;

	inter.min_dist = 0.01;
	inter.origin = light.pos;
	inter.depth = 0;
	dir = get_random_direction();
	photon.obj_i = 0;
	if (!other_hit(g_data, dir, &inter) || inter.trans_at_ip == 0.)
	{
		photon.pos = (t_vec){0, 0, 0};
		photon.color.c = 0;
		return (photon);
	}
	inter.color = substract_colors((t_color){.c = 0xFFFFFF}, inter.color);
	inter.color = col_multiply(inter.color, inter.trans_at_ip);
	photon.color = substract_colors(light.color, inter.color);
	photon = refract(&inter, dir, photon);
	photon.color = col_multiply(photon.color, light.ambi);
	return (photon);
}

void		get_photon_map(void)
{
	int i;
	int	j;
	int	off;

	if (!g_data->nb_lights || !g_data->nb_lights_on || !g_data->nb_objects)
		return ;
	if (!(g_data->photon_map = (t_photon *)malloc(sizeof(t_photon) \
		* g_data->nb_lights_on * PHOTON_NB)))
		return ;
	i = -1;
	off = 0;
	while (++i < g_data->nb_lights)
	{
		if (g_data->lights[i].disabled)
		{
			++off;
			continue ;
		}
		j = -1;
		while (++j < PHOTON_NB)
			g_data->photon_map[(i - off) * PHOTON_NB + j] = add_photon(\
				g_data->lights[i]);
	}
}
