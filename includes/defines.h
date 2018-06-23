/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:09:47 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/23 17:36:10 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_W 1400
# define WIN_H 1000
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
/*
**	Alternative to enums for OpenCL compatibility.
*/

#endif
