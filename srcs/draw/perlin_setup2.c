/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_setup2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 00:33:02 by vtudes            #+#    #+#             */
/*   Updated: 2018/07/17 00:33:04 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void		perlin_tab10(t_perlin *p)
{
	p->perm[215] = 107;
	p->perm[216] = 49;
	p->perm[217] = 192;
	p->perm[218] = 214;
	p->perm[219] = 31;
	p->perm[220] = 181;
	p->perm[221] = 199;
	p->perm[222] = 106;
	p->perm[223] = 157;
	p->perm[224] = 184;
	p->perm[225] = 84;
	p->perm[226] = 204;
	p->perm[227] = 176;
	p->perm[228] = 115;
	p->perm[229] = 121;
	p->perm[230] = 50;
	p->perm[231] = 45;
	p->perm[232] = 127;
	p->perm[233] = 4;
	p->perm[234] = 150;
	p->perm[235] = 254;
	p->perm[236] = 138;
	p->perm[237] = 236;
	p->perm[238] = 205;
	perlin_tab11(p);
}

static void		perlin_tab9(t_perlin *p)
{
	p->perm[191] = 104;
	p->perm[192] = 218;
	p->perm[193] = 246;
	p->perm[194] = 97;
	p->perm[195] = 228;
	p->perm[196] = 251;
	p->perm[197] = 34;
	p->perm[198] = 242;
	p->perm[199] = 193;
	p->perm[200] = 238;
	p->perm[201] = 210;
	p->perm[202] = 144;
	p->perm[203] = 12;
	p->perm[204] = 191;
	p->perm[205] = 179;
	p->perm[206] = 162;
	p->perm[207] = 241;
	p->perm[208] = 81;
	p->perm[209] = 51;
	p->perm[210] = 145;
	p->perm[211] = 235;
	p->perm[212] = 249;
	p->perm[213] = 14;
	p->perm[214] = 239;
	perlin_tab10(p);
}

static void		perlin_tab8(t_perlin *p)
{
	p->perm[167] = 70;
	p->perm[168] = 221;
	p->perm[169] = 153;
	p->perm[170] = 101;
	p->perm[171] = 155;
	p->perm[172] = 167;
	p->perm[173] = 43;
	p->perm[174] = 172;
	p->perm[175] = 9;
	p->perm[176] = 129;
	p->perm[177] = 22;
	p->perm[178] = 39;
	p->perm[179] = 253;
	p->perm[180] = 19;
	p->perm[181] = 98;
	p->perm[182] = 108;
	p->perm[183] = 110;
	p->perm[184] = 79;
	p->perm[185] = 113;
	p->perm[186] = 224;
	p->perm[187] = 232;
	p->perm[188] = 178;
	p->perm[189] = 185;
	p->perm[190] = 112;
	perlin_tab9(p);
}

static void		perlin_tab7(t_perlin *p)
{
	p->perm[143] = 212;
	p->perm[144] = 207;
	p->perm[145] = 206;
	p->perm[146] = 59;
	p->perm[147] = 227;
	p->perm[148] = 47;
	p->perm[149] = 16;
	p->perm[150] = 58;
	p->perm[151] = 17;
	p->perm[152] = 182;
	p->perm[153] = 189;
	p->perm[154] = 28;
	p->perm[155] = 42;
	p->perm[156] = 223;
	p->perm[157] = 183;
	p->perm[158] = 170;
	p->perm[159] = 213;
	p->perm[160] = 119;
	p->perm[161] = 248;
	p->perm[162] = 152;
	p->perm[163] = 2;
	p->perm[164] = 44;
	p->perm[165] = 154;
	p->perm[166] = 163;
	perlin_tab8(p);
}

void			perlin_tab6(t_perlin *p)
{
	p->perm[119] = 86;
	p->perm[120] = 164;
	p->perm[121] = 100;
	p->perm[122] = 109;
	p->perm[123] = 198;
	p->perm[124] = 173;
	p->perm[125] = 186;
	p->perm[126] = 3;
	p->perm[127] = 64;
	p->perm[128] = 52;
	p->perm[129] = 217;
	p->perm[130] = 226;
	p->perm[131] = 250;
	p->perm[132] = 124;
	p->perm[133] = 123;
	p->perm[134] = 5;
	p->perm[135] = 202;
	p->perm[136] = 38;
	p->perm[137] = 147;
	p->perm[138] = 118;
	p->perm[139] = 126;
	p->perm[140] = 255;
	p->perm[141] = 82;
	p->perm[142] = 85;
	perlin_tab7(p);
}
