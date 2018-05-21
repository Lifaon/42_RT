/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelbuf_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 18:49:41 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/12 18:54:06 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_gtk.h"

void	pixelbuf_free(t_pixelbuf **pxlbuf)
{
	free(*pxlbuf);
		//gtk_widget_destroy((*pxlbuf)->img);
}
