/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 02:09:32 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/13 04:25:49 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static t_color	blend(t_light light, t_color base, t_color shadow, double coeff)
{
	t_color sub;

	sub = substract_colors(light.color, shadow);
	sub = col_multiply(sub, 1 - coeff);
	sub = substract_colors(base, sub);
	return (substract_colors(sub, light.color_neg));
}

static t_color	get_color_at_ip(t_obj obj, t_vec ray, t_inter *inter)
{
	t_color	ret;

	if (obj.tex && obj.trans)
		ret.c = uv_mapping(obj, ray, inter);
	else if (obj.checkerboard && obj.trans)
		ret = checkerboard(obj, ray, inter);
	else
		ret = inter->color;
	if (obj.tex && obj.tex_trans)
		inter->trans_at_ip = 1 - (ret.argb.a / 255.);
	else
		inter->trans_at_ip = obj.trans;
	ret.argb.a = 255;
	return (ret);
}

t_color			shadow(t_light light, t_inter inter, t_vec ray, double len)
{
	t_color	base;
	t_color	shadow;
	t_color	tmp;
	double	trans;

	base = inter.color;
	shadow = light.color;
	trans = 1;
	inter.min_dist = 0.01;
	while (other_hit(g_data, ray, &inter) && inter.t < len)
	{
		tmp = get_color_at_ip(g_data->objs[inter.obj_i], ray, &inter);
		trans *= inter.trans_at_ip;
		if (trans == 0.)
			return (ambient_shading(base, light));
		len -= inter.t;
		inter.origin = inter.ip;
		tmp = substract_colors(light.color, tmp);
		shadow = substract_colors(shadow, tmp);
	}
	return (blend(light, base, shadow, trans));
}
