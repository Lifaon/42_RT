/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_page.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:33:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/29 19:36:50 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

gboolean	change_page_light(GtkNotebook *notebook, GtkWidget *page,
		gint arg1, gpointer data)
{
	if (!data)
		data = NULL;
	ft_putnbr(arg1);
	ft_putchar('\n');
	g_data->ui->tab_light = arg1;
	return (TRUE);
}
