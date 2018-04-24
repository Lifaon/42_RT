/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:09:47 by mlantonn          #+#    #+#             */
/*   Updated: 2018/04/24 13:35:41 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_W 1400.0
# define WIN_H 1000.0
# define NB_THR 8
/*
**	Size of the window created, and number of threads used to draw the image
**	faster. Note that you might have to change NB_THR if you change the size of
**	WIN_W and WIN_H.
*/

# define VP_DIST 1000.0
/*
**	Define the original distance between the camera and the viewplane.
*/

# define MAX_DIST 9000000000.0

# define PI 3.14159265359

#endif
