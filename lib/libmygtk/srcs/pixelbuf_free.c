/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelbuf_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 18:49:41 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/24 17:20:46 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mygtk.h"

void	pixelbuf_free(t_pixelbuf **pxlbuf)
{
	g_object_unref((*pxlbuf)->buf);
	ft_putstr("here\n");
	g_clear_object(&(*pxlbuf)->buf);
	ft_putstr("nope\n");
	free(*pxlbuf);
	*pxlbuf = NULL;
}
