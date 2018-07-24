/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:09:47 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/24 17:17:08 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
**	Size of the window created
*/
# define WIN_W 900
# define WIN_H 700

/*
**	Number of threads used
*/
# define NB_THR 16

/*
**	Number of cameras used
*/
# define CAM_NB 4

/*
**	obj.obj_type
**	obj.intersect = g_data->intersect[obj.obj_type];
**	obj.get_normal = g_data->get_normal[obj.obj_type];
*/
# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define CONE 3

/*
**	obj.limited
**	obj.limit = g_data->limit[obj.limited];
*/
# define LIMIT_NONE -1
# define LIMIT_AXE 0
# define LIMIT_SPHERE 1
# define LIMIT_RECTANGLE 2
# define LIMIT_CIRCLE 3
# define LIMIT_CYLINDER 4
# define LIMIT_CONE 5
# define LIMIT_DEFINED_BY_TEX 6

/*
**	g_data.filter
*/
# define FILTER_NONE 0
# define FILTER_BNW 1
# define FILTER_SEPIA 2
# define FILTER_STEREO 3

/*
**	obj.color_type
*/
# define COLOR_SIMPLE 0
# define COLOR_CHECKERBOARD 1
# define COLOR_RAINBOW 2

/*
**	obj.perl_type
*/
# define PERLIN_NONE 0
# define PERLIN_CLASSIC 1
# define PERLIN_COSINE 2

/*
**	Used to know what infinite value is acceptable for GtkEntry before
**	modifying g_data
*/
# define MODE_NO_INF 0
# define MODE_PLUS_INF 1
# define MODE_LESS_INF 2
# define MODE_BOTH_INF 3

/*
**	Note: defines are used instead of enums for a possible OpenCL compatibility
*/

# define FILTER_NONE 0
# define FILTER_BNW 1
# define FILTER_SEPIA 2

# define CLUST_NONE 0
# define CLUST_HOST 1
# define CLUST_CLIENT 2
# define NB_CLIENT_MAX 5

#endif
