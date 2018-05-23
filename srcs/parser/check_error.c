/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:57:46 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/23 17:00:12 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// check si quand on a "cameras" ou autre on a bien des brackets ou des braces
// check si les vecteurs sont bien 3 par 3

int		check_error(char *str)
{
	if (brackets(str))
		return (-1);
	return (0);
}
