#include "draw.h"

void	setup_z(t_perlin *p, float vecx)
{
	p->t = vecx + N;
	p->bz0 = ((int)p->t) & BM;
	p->bz1 = (p->bz0 + 1) & BM;
	p->rz0 = p->t - (int)p->t;
	p->rz1 = p->rz0 - 1;
}

void		setup_y(t_perlin *p, float vecy)
{
	p->t = vecy + N;
	p->by0 = ((int)p->t) & BM;
	p->by1 = (p->by0 + 1) & BM;
	p->ry0 = p->t - (int)p->t;
	p->ry1 = p->ry0 - 1;
}

void		setup_x(t_perlin *p, float vecz)
{
	p->t = vecz + N;
	p->bx0 = ((int)p->t) & BM;
	p->bx1 = (p->bx0 + 1) & BM;
	p->rx0 = p->t - (int)p->t;
	p->rx1 = p->rx0 - 1;
}