#include "draw.h"

void		apply_perlin(t_inter inter, t_perlin p, t_obj obj)
{
	int a;

	a = 2;

	inter.normal.z = (inter.normal.z + noise_3D(inter.ip.z - a, inter.ip.y, inter.ip.x, p))
	- (inter.normal.z + noise_3D(inter.ip.z + a, inter.ip.y, inter.ip.z, p));
	 inter.normal.y = (inter.normal.y + noise_3D(inter.ip.z, inter.ip.y - a, inter.ip.x, p))
	- (inter.normal.y + noise_3D(inter.ip.z, inter.ip.y + a, inter.ip.x, p));
	inter.normal.x = (inter.normal.x + noise_3D(inter.ip.z, inter.ip.y, inter.ip.x - a, p)) 
	- (inter.normal.x + noise_3D(inter.ip.z, inter.ip.y, inter.ip.x + a, p));
}

void		call_perlin(t_data data)
{
	t_obj obj;
	t_perlin p;
	t_inter inter;

	if (obj.obj_type == PLANE)
		apply_perlin(inter, p, obj);
	if (obj.obj_type == SPHERE)
		apply_perlin(inter, p, obj);
	if (obj.obj_type == CONE)
		apply_perlin(inter, p, obj);
	if (obj.obj_type == CYLINDER)
		apply_perlin(inter, p, obj);
}