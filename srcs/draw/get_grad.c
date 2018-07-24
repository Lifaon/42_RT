/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:34:22 by vtudes            #+#    #+#             */
/*   Updated: 2018/07/22 16:44:24 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		get_a(t_perlin *p, int i, float g_grad3[B + B + 2][3])
{
	if (i == 1)
	{
		p->q = g_grad3[p->b00 + p->bz0];
		p->u = at3(p->q, p->rx0, p->ry0, p->rz0);
		p->q = g_grad3[p->b10 + p->bz0];
		p->v = at3(p->q, p->rx1, p->ry0, p->rz0);
		p->a = lerp(p->t, p->u, p->v);
	}
	else if (i == 2)
	{
		p->q = g_grad3[p->b00 + p->bz1];
		p->u = at3(p->q, p->rx0, p->ry0, p->rz1);
		p->q = g_grad3[p->b10 + p->bz1];
		p->v = at3(p->q, p->rx1, p->ry0, p->rz1);
		p->a = lerp(p->t, p->u, p->v);
	}
}

void		get_c(t_perlin *p, float g_grad3[B + B + 2][3])
{
	p->q = g_grad3[p->b01 + p->bz0];
	p->u = at3(p->q, p->rx0, p->ry1, p->rz0);
	p->q = g_grad3[p->b11 + p->bz0];
	p->v = at3(p->q, p->rx1, p->ry1, p->rz0);
	p->b = lerp(p->t, p->u, p->v);
	p->c = lerp(p->sy, p->a, p->b);
}

void		get_d(t_perlin *p, float g_grad3[B + B + 2][3])
{
	p->q = g_grad3[p->b01 + p->bz1];
	p->u = at3(p->q, p->rx0, p->ry1, p->rz1);
	p->q = g_grad3[p->b11 + p->bz1];
	p->v = at3(p->q, p->rx1, p->ry1, p->rz1);
	p->b = lerp(p->t, p->u, p->v);
	p->d = lerp(p->sy, p->a, p->b);
}
