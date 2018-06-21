/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ui_active.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:29:48 by fchevrey          #+#    #+#             */
/*   Updated: 2018/06/21 16:17:58 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

/*
** This function is used to assure that the function of the user interface is 
** inactivate when we want to add new widget or modifying exinsting widget.
** When is is called with star = 1, the function reset the ui at it's previous
** status.
** It's usefull for function that can be called at different multiple moment.
*/

void		check_ui_active(int start)
{
	static int		status = 1;
	static int		i = 0;

	if (i == 0 && start == 0)
		status = g_data->ui->is_active;
	else if (start == 1 && i == 1)
		g_data->ui->is_active = status;
	if (start == 0)
	{
		g_data->ui->is_active = 0;
		i++;
	}
	if (start == 1 && i > 0)
		i--;
}
