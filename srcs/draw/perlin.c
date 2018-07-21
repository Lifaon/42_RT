#include "draw.h"

static int perm[B + B +2];
static float grad3[B + B + 2][3];
static int grad_start = 1;

static void		normalize3(float v[3])
{
	float s;

	s = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	v[0] = v[0] / s;
	v[1] = v[1] / s;
	v[2] = v[2] / s;
}

static int		shuffle(int i)
{
	int k;
	int j;

	while (--i)
	{
		k = perm[i];
		j = random() % B;
		perm[i] = perm[j];
		perm[j] = k;
	}
	return (i);
}

static void		initialisation(void)
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < B)
	{
		perm[i] = i;
		j = -1;
		while (++j < 3)
			grad3[i][j] = (float)((random() % (B + B)) - B) / B;
		normalize3(grad3[i]);
	}
	i = shuffle(i);
	while(++i < B + 2)
	{
		perm[B + i] = perm[i];
		j = -1;
		while (++j < 3)
			grad3[B + i][j] = grad3[i][j];
	}
	grad_start = 0;
}

float		noise(float vecx, float vecy, float vecz)
{
	t_perlin	p;
	int			i;
	int			j;

	if (grad_start)
		initialisation();
	setup_x(&p, vecx);
	setup_y(&p, vecy);
	setup_z(&p, vecz);
	i = perm[p.bx0];
	j = perm[p.bx1];
	p.b00 = perm[i + p.by0];
	p.b10 = perm[j + p.by0];
	p.b01 = perm[i + p.by1];
	p.b11 = perm[j + p.by1];
	p.t = curve(p.rx0);
	p.sy = curve(p.ry0);
	p.sz = curve(p.rz0);
	get_a(&p, 1, grad3);
	get_c(&p, grad3);
	get_a(&p, 2, grad3);
	get_d(&p, grad3);
	return (LERP(p.sz, p.c, p.d));
}

float		noise_vec(float vec[3])
{
	return (noise(vec[0], vec[1], vec[2]));
}