#include "draw.h"

static void	perlin_tab13(t_perlin p)
{
	p.perm[287] = 72;
	p.perm[288] = 243;
	p.perm[289] = 141;
	p.perm[290] = 128;
	p.perm[291] = 195;
	p.perm[292] = 78;
	p.perm[293] = 66;
	p.perm[294] = 215;
	p.perm[295] = 61;
	p.perm[296] = 156;
	p.perm[297] = 180;
}

static void	perlin_tab12(t_perlin p)
{
	p.perm[264] = 13;
	p.perm[265] = 201;
	p.perm[266] = 95;
	p.perm[267] = 96;
	p.perm[268] = 53;
	p.perm[269] = 194;
	p.perm[270] = 233;
	p.perm[271] = 7;
	p.perm[272] = 225;
	p.perm[273] = 140;
	p.perm[274] = 127;
	p.perm[275] = 4;
	p.perm[276] = 150;
	p.perm[277] = 254;
	p.perm[278] = 138;
	p.perm[279] = 236;
	p.perm[280] = 205;
	p.perm[281] = 93;
	p.perm[282] = 222;
	p.perm[283] = 114;
	p.perm[284] = 67;
	p.perm[285] = 29;
	p.perm[286] = 24;
	perlin_tab13(p);
}

void	perlin_tab11(t_perlin p)
{
	p.perm[240] = 222;
	p.perm[241] = 114;
	p.perm[242] = 67;
	p.perm[243] = 29;
	p.perm[244] = 24;
	p.perm[245] = 72;
	p.perm[246] = 243;
	p.perm[247] = 141;
	p.perm[248] = 128;
	p.perm[249] = 195;
	p.perm[250] = 78;
	p.perm[251] = 66;
	p.perm[252] = 215;
	p.perm[253] = 61;
	p.perm[255] = 156;
	p.perm[256] = 180;
	p.perm[257] = 151;
	p.perm[258] = 160;
	p.perm[259] = 137;
	p.perm[260] = 91;
	p.perm[261] = 90;
	p.perm[262] = 15;
	p.perm[263] = 131;
	perlin_tab12(p);
}

double		noise_3D_setup(t_perlin p)
{
	p.g111 = dot_perlin(get_gradian(p.x1 + 1, p.y1 + 1, p.z1 +1,\
		&p), p.x -1, p.y - 1, p.z - 1);
	p.u = quintic_poly(p.x);
	p.v = quintic_poly(p.y);
	p.w = quintic_poly(p.z);
	p.x00 = linear_interpolation(p.g000, p.g100, p.u);
	p.x10 = linear_interpolation(p.g010, p.g110, p.u);
	p.x11 = linear_interpolation(p.g001, p.g101, p.u);
	p.xy0 = linear_interpolation(p.g011, p.g111, p.u);
	p.x01 = linear_interpolation(p.x00, p.x10, p.v);
	p.xy1 = linear_interpolation(p.x01, p.x11, p.v);
	p.xyz = linear_interpolation(p.xy0, p.xy1, p.w);
	return (p.xyz);
}

double		noise_3D(double pos_x, double pos_y, double pos_z, t_perlin p)
{
	pos_x = fabs(pos_x) / p.perlin_stain;
	pos_y = fabs(pos_y) / p.perlin_stain;
	pos_z = fabs(pos_z) / p.perlin_stain;
	int_frac(pos_x, &p.x1, &p.x);
	int_frac(pos_y, &p.y1, &p.y);
	int_frac(pos_z, &p.z1, &p.z);
	p.g000 = dot_perlin(get_gradian(p.x1, p.y1, p.z1, &p), p.x, p.y, p.z);
	p.g001 = dot_perlin(get_gradian(p.x1, p.y1, p.z1 + 1, &p), p.x, p.y, p.z - 1);
	p.g010 = dot_perlin(get_gradian(p.x1, p.y1 + 1, p.z1, &p), p.x, p.y - 1, p.z);
	p.g011 = dot_perlin(get_gradian(p.x1, p.y1 + 1, p.z1 + 1, &p), p.x, p.y - 1, p.z - 1);
	p.g100 = dot_perlin(get_gradian(p.x1 + 1, p.y1, p.z1, &p), p.x - 1, p.y, p.z);
	p.g101 = dot_perlin(get_gradian(p.x1 + 1, p.y1, p.z1 + 1, &p), p.x - 1, p.y, p.z - 1);
	p.g110 = dot_perlin(get_gradian(p.x1 + 1, p.y1 + 1, p.z1, &p), p.x -1, p.y - 1, p.z);
	return (noise_3D_setup(p));
}