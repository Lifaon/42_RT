#include "draw.h"


void	ft_perlin(t_data *data, t_color *color, t_inter *inter)
{
	double	coef;
	int		level;
	float	vec[3];
	t_color ret;

	coef = 0;
	vec[0] = inter->ip.x * 0.5;
	vec[1] = inter->ip.y * 0.5;
	vec[2] = inter->ip.z * 0.5;
	level = 1;
	while (++level < 3)
	{
		coef += (1.0 / level) * fabs(noise(vec));
	}
	coef = 0.3 * cos((inter->ip.x + inter->ip.y + inter->ip.z) * 0.05 + coef) + 0.9;
	if (coef < 0)
		coef = 0;
	else if (coef > 1)
		coef = 1;
	color->argb.r *= coef;
	color->argb.g *= coef;
	color->argb.b *= coef;
}