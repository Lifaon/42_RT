#include "draw.h"


void	ft_perlin(t_data *data, t_color *color, t_inter *inter)
{
	double	coef;
	int		level;
	float	vec[3];
	t_color ret;

	coef = 0;
	vec[0] = inter->ip.x * 0.05;
	vec[1] = inter->ip.y * 0.05;
	vec[2] = inter->ip.z * 0.05;
	level = 1;
	while (++level < 40)
	{
		coef += (1.0 / level) * fabs(noise_vec(vec));
	}
	coef = 0.2 * cos((inter->ip.x + inter->ip.y + inter->ip.z) * 0.05 + coef) + 0.9;
	//coef = 0.42 * coef + 0.8;
	if (coef < 0)
		coef = 0;
	else if (coef > 1)
		coef = 1;
	color->argb.r *= coef;
	color->argb.g *= coef;
	color->argb.b *= coef;
}



// t_vec	bump_mapping(t_inter inter)
// {
// 	t_vec vec;
// 	t_vec ret;

// 	vec.x = inter.normal.x + inter.ip.x;
// 	vec.y = 50 * inter.normal.y + 100 * inter.ip.y;
// 	vec.z = inter.normal.z + inter.ip.z;
// 	ret.x = noise(vec.x - 0.001, vec.y, vec.z) - noise(vec.x + 0.001, vec.y, vec.z);
// 	ret.y = noise(vec.x, vec.y - 0.001, vec.z) - noise(vec.x, vec.y + 0.001, vec.z);
// 	ret.z = noise(vec.x, vec.y, vec.z - 0.001) - noise(vec.x, vec.y, vec.z + 0.001);
// 	return (ret);
// }