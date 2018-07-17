#include "draw.h"

double	LERP(double t, double a, double b)
{
	return (1 - t) * a + t * b;
}

double	curve(const double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 8));
}

double	AT3(const float *v, const double x, const double y, \
			const double z)
{
		return (v[0] * x + v[1] * y + v[2] * z);
}

void	ft_perlin(t_data *data, t_color *color, t_inter *inter)
{
	double	coef;
	int		level;
	float	vec[3];

	coef = 0;
	vec[0] = inter->ip.x * 0.5;
	vec[1] = inter->ip.y * 0.5;
	vec[2] = inter->ip.z * 0.5;
	level = 1;
	while (++level < 40)
	{
		coef += (1.0 / level) * fabs(noise(vec));
	}
	coef = 0.30 * cos((inter->ip.x + inter->ip.y + inter->ip.z) * 0.05 + coef) + 0.9;
	if (coef < 0)
		coef = 0;
	else if (coef > 1)
		coef = 1;
	color->argb.r *= coef;
	color->argb.g *= coef;
	color->argb.b *= coef;
}