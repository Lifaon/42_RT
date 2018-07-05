/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:09:47 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/27 20:19:41 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_W 900
# define WIN_H 700
/*
**	Size of the window created.
*/

# define CAM_NB 4
/*
**	Number of cameras used.
*/

# define NB_THR 8
/*
**	Number of threads used.
*/

# define MAX_RECURSION 3
/*
**	int value for the max recursion for reflection
*/
# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define CONE 3
# define LIMIT_NONE -1
# define LIMIT_AXE 0
# define LIMIT_SPHERE 1
# define LIMIT_RECTANGLE 2
# define LIMIT_CIRCLE 3
# define LIMIT_CYLINDER 4
# define LIMIT_CONE 5
/*
**	Alternative to enums for OpenCL compatibility.
*/

# define MODE_NO_INF 0
# define MODE_PLUS_INF 1
# define MODE_LESS_INF 2
# define MODE_BOTH_INF 3
/*
** used to know what infinite value is acceptable for GtkEntry before
** modifying g_data
*/

# define FILTER_NONE 0
# define FILTER_BNW 1
# define FILTER_SEPIA 2

#endif
