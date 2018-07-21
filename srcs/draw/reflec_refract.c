/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflec_refract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:11:04 by pmiceli           #+#    #+#             */
/*   Updated: 2018/07/21 08:56:47 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "rtv1.h"

t_color		blend_coeff(t_color old, t_color new, double coeff)
{
	t_color old_coeff;
	t_color new_coeff;

	old_coeff = col_multiply(old, 1 - coeff);
	new_coeff = col_multiply(new, coeff);
	return (add_colors(old_coeff, new_coeff));
}

t_color		draw_reflec(t_data *data, t_inter *inter, t_color ret, t_vec ray)
{
	t_vec	r;
	double	coeff;

	++inter->depth;
	coeff = data->objs[inter->obj_i].shiny;
	r = vec_normalize(vec_add(vec_multiply(\
		inter->normal, dot_product(inter->normal, ray) * -2.0), ray));
	inter->origin = vec_add(inter->ip, vec_multiply(r, 0.3));
	if (other_hit(data, r, inter))
		return (blend_coeff(ret, get_px_color(data, r, *inter), coeff));
	return (blend_coeff(ret, (t_color){.c = 0xFF000000}, coeff));
}

t_color		draw_refract(t_data *data, t_inter *inter, t_color ret, t_vec ray)
{
	t_vec		r;
	double		coeff;
	double		dot;
	double		eta;
	double		k;

	++inter->depth;
	coeff = inter->trans_at_ip;
	dot = dot_product(ray, data->objs[inter->obj_i].get_normal(\
		data->objs[inter->obj_i], *inter));
	eta = 1. / data->objs[inter->obj_i].ior;
	if (dot < 0.)	// in object
		dot = -dot;
	else	// out of object
		eta = data->objs[inter->obj_i].ior;
	k = 1.0f - eta * eta * (1.0f - dot * dot);
	if (k < 0.)
	{
		eta = 1.;
		k = 1.0f - dot * dot;
	}
	r = vec_normalize(vec_add(vec_multiply(ray, eta), \
		vec_multiply(inter->normal, eta * dot - sqrt(k))));
	inter->origin = vec_add(inter->ip, vec_multiply(r, 0.3));
	if (other_hit(data, r, inter))
		return (blend_coeff(ret, get_px_color(data, r, *inter), coeff));
	return (blend_coeff(ret, (t_color){.c = 0xFF000000}, coeff));
}
