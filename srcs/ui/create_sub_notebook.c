/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sub_notebook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:23:33 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/26 10:29:16 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

int		create_sub_notebook(t_ui *ui)
{
	g_ui->is_active = 0;
	if (!(create_light_ui(ui->tab)))
		return (0);
	ft_putstr("light\n");
	if (!(create_camera_ui(ui->tab)))
		return (0);
	ft_putstr("cam\n");
	if (!(create_object_ui(ui->tab)))
		return (0);
	ft_putstr("obj\n");
	if (!(create_options_ui(ui->tab)))
		return (0);
	ft_putstr("option\n");
	g_ui->is_active = 1;
	return (1);
}
