/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wid_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:59:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/27 16:08:01 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_wid_data(t_wid_data *wid_d, t_point pos, t_point size,
	void (*f)(GtkWidget*, gpointer))
{
	wid_d->pos = pos;
	wid_d->size = size;
	wid_d->f = f;
}
