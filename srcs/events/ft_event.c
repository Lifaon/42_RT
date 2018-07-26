/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:56:23 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/26 10:30:21 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	ft_event(t_data *data)
{
	ft_putstr("here\n");
	gtk_widget_grab_focus(g_ui->ev_box);
	gtk_widget_grab_default(g_ui->ev_box);
	ft_putstr("there\n");
	gtk_main();
	exit_all(data);
}
