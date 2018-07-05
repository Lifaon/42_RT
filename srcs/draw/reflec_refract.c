/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflec_refract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:11:04 by pmiceli           #+#    #+#             */
/*   Updated: 2018/07/02 22:03:10 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "rtv1.h"

t_color	draw_reflec(t_data *data, t_inter inter, t_vec ray, int rec, t_color ret)
{
	t_vec		r;
	t_vec		ip;
	double		t;
	int			i;
	int			obj_i_tmp;

	obj_i_tmp = inter.obj_i;
	i = 0;
	t = INFINITY;
	ip = inter.ip;
	inter.normal = data->objs[inter.obj_i].get_normal(data->objs[inter.obj_i], inter);
	r = vec_normalize(vec_add(\
				vec_multiply(inter.normal, dot_product(inter.normal, ray) * -2.0),\
				ray));
	ip = vec_add(ip, vec_multiply(r, 0.3));
	while (i < data->nb_objects)
	{
		inter.oc = vec_substract(ip, data->objs[i].pos);
		if (data->objs[i].intersect(data->objs[i], r, &inter) && inter.t < t)
		{
			t = inter.t;
			inter.obj_i = i;
		}
		i++;
	}
	if (t < INFINITY)
	{
		inter.t = t;
		inter.ip = vec_add(ip, vec_multiply(r, inter.t));
		inter.normal = get_normal(r, data->objs[inter.obj_i], inter);
		ret = blend_colors(ret, col_multiply(get_px_color(data, inter), data->objs[obj_i_tmp].shin_pourcentage));
		if (data->objs[inter.obj_i].shiny && rec < 3)
			ret = draw_reflec(data, inter, r, ++rec, ret);
	}
	else
		ret = blend_colors(ret, (t_color){.c = 0xFF000000});
	return (ret);
}

t_color		draw_refract(t_data *data, t_inter inter, t_vec ray, t_color ret, int rec)
{
	t_vec		r;
	t_vec		ip;
	double		n_i = 1.0f;
	double		n_t = 1.0f /*data->objs[inter->obj_i].ior pas encore dans le parser */;
	double		angle_i;
	double		angle_t;
	double		t;
	int			i;
	int			obj_i_tmp;
	double		dot;
	double		eta;
	double		k;

	inter.normal = data->objs[inter.obj_i].get_normal(data->objs[inter.obj_i], inter);
	dot = dot_product(ray, inter.normal);
	if (dot < 0.0f) // on est dans en dehors de l'objet //
		dot = -dot;
	else // on est dans l'objet //
	{
		inter.normal = vec_multiply(inter.normal, -1);
		ft_swap_double(&n_i, &n_t);
	}
	eta = n_i / n_t;
	k = 1.0f - eta * eta * (1.0f - dot * dot);
	if (k < 0.0f) // nor refraction car full reflection interne 
		return ((t_color){.c = 0xFF000000});
	ip = inter.ip;
	t = INFINITY;
	obj_i_tmp = inter.obj_i;
	angle_i = acos(dot);
	angle_t = asin((n_i * sin(angle_i)) / n_t);
	// Loi de Snell-Descartes.
	//r = vec_normalize(vec_substract(vec_multiply(vec_add(ray, vec_multiply(inter.normal, \
						cos(angle_i))), n_i / n_t), vec_multiply(inter.normal, cos(angle_t))));
	r = vec_normalize(vec_add(vec_multiply(ray, eta), vec_multiply(inter.normal, eta * dot - sqrt(k))));
	i = -1;
	ip = vec_add(ip, vec_multiply(r, 0.3));
	while (++i < data->nb_objects)
	{
		inter.oc = vec_substract(ip, data->objs[i].pos);
		if (data->objs[i].intersect(data->objs[i], r, &inter) && inter.t < t)
		{
			t = inter.t;
			inter.obj_i = i;
		}
	}
	if (t < INFINITY)
	{
		inter.t = t;
		inter.origin = ip;
		inter.ip = vec_add(ip, vec_multiply(r, inter.t));
		inter.normal = get_normal(r, data->objs[inter.obj_i], inter);
		ret = blend_colors(ret, col_multiply(get_px_color(data, inter), data->objs[obj_i_tmp].trans_pourcentage));
		if (inter.obj_i == obj_i_tmp)
			ret = draw_refract(data, inter, r, ret, ++rec);
	}
	else
		ret = blend_colors(ret, (t_color){.c = 0xFF000000});
	return (ret);
}
