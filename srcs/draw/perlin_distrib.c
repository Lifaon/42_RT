void		plan_perlin(t_inter inter, t_perlin p, t_obj obj)
{
	int a;

	a = 2;
	if (p.perlin == 3)
	{
		inter.normal.z = (inter.normal.z + noise_3D(inter.ip.z - a, inter.ip.y, inter.ip.x, p))
		- (inter.normal.z + noise_3D(inter.ip.z + a, inter.ip.y, inter.ip.z, p));
		 inter.normal.y = (inter.normal.y + noise_3D(inter.ip.z, inter.ip.y - a, inter.ip.x, p))
		- (inter.normal.y + noise_3D(inter.ip.z, inter.ip.y + a, inter.ip.x));
		inter.normal.x = (inter.nornal.x + noise3D(inter.ip.z, inter.ip.y, inter.ip.x - a)) 
		- (inter.normal.x + noise_3D(inter.ip.z, inter.ip.y, inter.ip.x + a));
	}
}