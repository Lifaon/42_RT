/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_setup1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 00:32:28 by vtudes            #+#    #+#             */
/*   Updated: 2018/07/17 00:32:29 by vtudes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void		perlin_tab5(t_perlin *p)
{
	p->perm[95] = 54;
	p->perm[96] = 65;
	p->perm[97] = 25;
	p->perm[98] = 63;
	p->perm[99] = 161;
	p->perm[100] = 1;
	p->perm[101] = 216;
	p->perm[102] = 80;
	p->perm[103] = 73;
	p->perm[104] = 209;
	p->perm[105] = 76;
	p->perm[106] = 132;
	p->perm[107] = 187;
	p->perm[108] = 208;
	p->perm[109] = 89;
	p->perm[110] = 18;
	p->perm[111] = 169;
	p->perm[112] = 200;
	p->perm[113] = 196;
	p->perm[114] = 135;
	p->perm[115] = 130;
	p->perm[116] = 116;
	p->perm[117] = 188;
	p->perm[118] = 159;
	perlin_tab6(p);
}

static void		perlin_tab4(t_perlin *p)
{
	p->perm[72] = 77;
	p->perm[73] = 146;
	p->perm[74] = 158;
	p->perm[75] = 231;
	p->perm[76] = 83;
	p->perm[77] = 111;
	p->perm[78] = 229;
	p->perm[79] = 122;
	p->perm[80] = 60;
	p->perm[81] = 211;
	p->perm[82] = 133;
	p->perm[83] = 230;
	p->perm[84] = 220;
	p->perm[85] = 105;
	p->perm[86] = 92;
	p->perm[87] = 41;
	p->perm[88] = 55;
	p->perm[89] = 46;
	p->perm[90] = 245;
	p->perm[91] = 40;
	p->perm[92] = 244;
	p->perm[93] = 102;
	p->perm[94] = 143;
	perlin_tab5(p);
}

static void		perlin_tab3(t_perlin *p)
{
	p->perm[48] = 57;
	p->perm[49] = 177;
	p->perm[50] = 33;
	p->perm[51] = 88;
	p->perm[52] = 237;
	p->perm[53] = 149;
	p->perm[54] = 56;
	p->perm[55] = 87;
	p->perm[56] = 174;
	p->perm[57] = 20;
	p->perm[58] = 125;
	p->perm[59] = 136;
	p->perm[60] = 171;
	p->perm[61] = 168;
	p->perm[62] = 68;
	p->perm[63] = 175;
	p->perm[64] = 74;
	p->perm[65] = 165;
	p->perm[66] = 71;
	p->perm[67] = 134;
	p->perm[68] = 139;
	p->perm[69] = 48;
	p->perm[70] = 27;
	p->perm[71] = 166;
	perlin_tab4(p);
}

static void		perlin_tab2(t_perlin *p)
{
	p->perm[24] = 37;
	p->perm[25] = 240;
	p->perm[26] = 21;
	p->perm[27] = 10;
	p->perm[28] = 23;
	p->perm[29] = 190;
	p->perm[30] = 6;
	p->perm[31] = 148;
	p->perm[32] = 247;
	p->perm[33] = 120;
	p->perm[34] = 234;
	p->perm[35] = 75;
	p->perm[36] = 0;
	p->perm[37] = 26;
	p->perm[38] = 197;
	p->perm[39] = 62;
	p->perm[40] = 94;
	p->perm[41] = 252;
	p->perm[42] = 219;
	p->perm[43] = 203;
	p->perm[44] = 117;
	p->perm[45] = 35;
	p->perm[46] = 11;
	p->perm[47] = 32;
	perlin_tab3(p);
}

void			perlin_tab1(t_perlin *p)
{
	p->perm[0] = 151;
	p->perm[1] = 160;
	p->perm[2] = 137;
	p->perm[3] = 91;
	p->perm[4] = 90;
	p->perm[5] = 15;
	p->perm[6] = 131;
	p->perm[7] = 13;
	p->perm[8] = 201;
	p->perm[9] = 95;
	p->perm[10] = 96;
	p->perm[11] = 53;
	p->perm[12] = 194;
	p->perm[13] = 233;
	p->perm[14] = 7;
	p->perm[15] = 225;
	p->perm[16] = 140;
	p->perm[17] = 36;
	p->perm[18] = 103;
	p->perm[19] = 30;
	p->perm[20] = 69;
	p->perm[21] = 142;
	p->perm[22] = 8;
	p->perm[23] = 99;
	perlin_tab2(p);
}
