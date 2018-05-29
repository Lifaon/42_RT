/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_page.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:33:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/29 18:37:07 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

gboolean	change_page_light(GtkWidget *widget, gint arg1,  gpointer data)
{
	if (!data)
		data = NULL;
	ft_putnbr(arg1);
	ft_putchar('\n');
	g_data->ui.tab_light = arg1;
	return (TRUE);
}
