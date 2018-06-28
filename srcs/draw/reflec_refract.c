/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflec_refract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:11:04 by pmiceli           #+#    #+#             */
/*   Updated: 2018/06/28 17:58:20 by pmiceli          ###   ########.fr       */
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

t_color	draw_refract(t_data *data, t_inter inter, t_vec ray, t_color ret)
{
	t_vec		r;
	double		tmp;
	double		ind;
	int			i;
	double		t;
	t_vec		ip;
	int			obj_i_tmp;

	obj_i_tmp = inter.obj_i;
	i = 0;
	t = INFINITY;
//	ind = (double)I_WATER / (double)I_AIR;
	ind = 1.0;
	//doit etre l'indice de refrac du milieu sortant / entrant
	tmp = dot_product(inter.normal, ray) - sqrt(1.0f - pow(ind, 2.0f) * (1.0f - pow(dot_product(inter.normal, ray), 2.0f)));
	r = vec_cross_product(vec_multiply(inter.normal, (ind * tmp)), vec_multiply(ray, ind));
	r = vec_normalize(r);
	ip = inter.ip;
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
		ret = get_px_color(data, inter);
	//	ret = blend_colors(ret, col_multiply(get_px_color(data, inter), data->objs[obj_i_tmp].trans_pourcentage));
	}
	else
		ret = blend_colors(ret, (t_color){.c = 0xFF000000});
	return (ret);
}
