/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_pxl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:50:41 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/27 18:52:03 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mygtk.h"
uint32_t	*get_img_pxl(char *filename)
{
	uint32_t	*pxl;

	img = gtk_image_new_from_file("./srcs/ui/assets/exit.png");
	pxb = pixelbuf_new_from_img(img);
	return (pxl);
}
