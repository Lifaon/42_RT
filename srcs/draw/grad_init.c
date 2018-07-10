#include "draw.h"

static void		grad_tab2(t_perlin *p)
{
	p->grad3[8][0] = 0;
	p->grad3[8][1] = 1;
	p->grad3[8][2] = 1;
	p->grad3[9][0] = 0;
	p->grad3[9][1] = -1;
	p->grad3[9][2] = 1;
	p->grad3[10][0] = 0;
	p->grad3[10][1] = 1;
	p->grad3[10][2] = -1;
	p->grad3[11][0] = 0;
	p->grad3[11][1] = -1;
	p->grad3[11][2] = -1;
	p->grad3[12][0] = 1;
	p->grad3[12][1] = 1;
	p->grad3[12][2] = 0;
	p->grad3[13][0] = -1;
	p->grad3[13][1] = 1;
	p->grad3[13][2] = 0;
	p->grad3[14][0] = 0;
	p->grad3[14][1] = -1;
	p->grad3[14][2] = 1;
	p->grad3[15][0] = 0;
	p->grad3[15][1] = -1;
	p->grad3[15][2] = -1;
}

void		grad_tab(t_perlin *p)
{
	p->grad3[0][0] = 1;
	p->grad3[0][1] = 1;
	p->grad3[0][2] = 0;
	p->grad3[1][0] = -1;
	p->grad3[1][1] = 1;
	p->grad3[1][2] = 0;
	p->grad3[2][0] = 1;
	p->grad3[2][1] = -1;
	p->grad3[2][2] = 0;
	p->grad3[3][0] = -1;
	p->grad3[3][1] = -1;
	p->grad3[3][2] = 0;
	p->grad3[4][0] = 1;
	p->grad3[4][1] = 0;
	p->grad3[4][2] = 1;
	p->grad3[5][0] = -1;
	p->grad3[5][1] = 0;
	p->grad3[5][2] = 1;
	p->grad3[6][0] = 1;
	p->grad3[6][1] = 0;
	p->grad3[6][2] = -1;
	p->grad3[7][0] = -1;
	p->grad3[7][1] = 0;
	p->grad3[7][2] = -1;
	grad_tab2(p);
}
