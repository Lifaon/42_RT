/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sub_notebook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:23:33 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/28 20:52:59 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

int		create_sub_notebook(t_ui *ui, int do_options)
{
	g_data->ui->is_active = 0;
	if (!(create_light_ui(ui->tab)))
		return (0);
	if (!(create_camera_ui(ui->tab)))
		return (0);
	if (!(create_object_ui(ui->tab)))
		return (0);
	ft_putstr("cmon\n");
	if (do_options == 1)
		if (!(create_options_ui(ui->tab)))
			return (0);
	ft_putstr("my menn\n");
	g_data->ui->is_active = 1;
	return (1);
}
