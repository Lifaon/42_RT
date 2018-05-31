/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:57:46 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/31 16:31:18 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_error(t_data *data, char *str)
{
	int err;

	err = 0;
	if (brackets(str))
		++err;
	if (err)
	{
		free(str);
		exit_all(data);
	}
}
