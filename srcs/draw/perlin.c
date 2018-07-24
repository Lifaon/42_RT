/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <vtudes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:40:54 by vtudes            #+#    #+#             */
/*   Updated: 2018/07/24 19:27:21 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int g_perm[B + B + 2];
static float g_grad3[B + B + 2][3];
static int g_grad_start = 1;

static void		normalize3(float v[3])
{
	float		s;

	s = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	v[0] = v[0] / s;
	v[1] = v[1] / s;
	v[2] = v[2] / s;
}

static int		shuffle(int i)
{
	int			k;
	int			j;

	while (--i)
	{
		k = g_perm[i];
		j = random() % B;
		g_perm[i] = g_perm[j];
		g_perm[j] = k;
	}
	return (i);
}

static void		initialisation(void)
{
	int			i;
	int			j;

	i = -1;
	while (++i < B)
	{
		g_perm[i] = i;
		j = -1;
		while (++j < 3)
			g_grad3[i][j] = (float)((random() % (B + B)) - B) / B;
		normalize3(g_grad3[i]);
	}
	i = shuffle(i);
	while (++i < B + 2)
	{
		g_perm[B + i] = g_perm[i];
		j = -1;
		while (++j < 3)
			g_grad3[B + i][j] = g_grad3[i][j];
	}
	g_grad_start = 0;
}

float			noise(float vecx, float vecy, float vecz)
{
	t_perlin	p;
	int			i;
	int			j;

	if (g_grad_start)
		initialisation();
	setup_x(&p, vecx);
	setup_y(&p, vecy);
	setup_z(&p, vecz);
	i = g_perm[p.bx0];
	j = g_perm[p.bx1];
	p.b00 = g_perm[i + p.by0];
	p.b10 = g_perm[j + p.by0];
	p.b01 = g_perm[i + p.by1];
	p.b11 = g_perm[j + p.by1];
	p.t = curve(p.rx0);
	p.sy = curve(p.ry0);
	p.sz = curve(p.rz0);
	get_a(&p, 1, g_grad3);
	get_c(&p, g_grad3);
	get_a(&p, 2, g_grad3);
	get_d(&p, g_grad3);
	return (lerp(p.sz, p.c, p.d));
}

float			noise_vec(float vec[3])
{
	return (noise(vec[0], vec[1], vec[2]));
}
