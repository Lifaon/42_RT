#include "draw.h"

void		get_a(t_perlin *p, int i, float grad3[B + B +2][3])
{
	if (i == 1)
	{
		p->q = grad3[p->b00 + p->bz0];
		p->u = AT3(p->q, p->rx0, p->ry0, p->rz0);
		p->q = grad3[p->b10 + p->bz0];
		p->v = AT3(p->q, p->rx1, p->ry0, p->rz0);
		p->a = LERP(p->t, p->u, p->v);
	}
	else if (i == 2)
	{
		p->q = grad3[p->b00 + p->bz1];
		p->u = AT3(p->q, p->rx0, p->ry0, p->rz1);
		p->q = grad3[p->b10 + p->bz1];
		p->v = AT3(p->q, p->rx1, p->ry0, p->rz1);
		p->a = LERP(p->t, p->u, p->v);
	}
}

void		get_d(t_perlin *p, float grad3[B +B + 2][3])
{
	p->q = grad3[p->b01 + p->bz1];
	p->u = AT3(p->q, p->rx0, p->ry1, p->rz1);
	p->q = grad3[p->b11 + p->bz1];
	p->v = AT3(p->q, p->rx1, p->ry1, p->rz1);
	p->b = LERP(p->t, p->u, p->v);
	p->d = LERP(p->sy, p->a, p->b);
}

void		get_c(t_perlin *p, float grad3[B +B + 2][3])
{
	p->q = grad3[p->b01 + p->bz0];
	p->u = AT3(p->q, p->rx0, p->ry1, p->rz0);
	p->q = grad3[p->b11 + p->bz0];
	p->v = AT3(p->q, p->rx1, p->ry1, p->rz0);
	p->b = LERP(p->t, p->u, p->v);
	p->c = LERP(p->sy, p->a, p->b);
}