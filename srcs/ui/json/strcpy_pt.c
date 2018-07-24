/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_pt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:40:17 by fchevrey          #+#    #+#             */
/*   Updated: 2018/07/24 13:40:50 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

char		*strcpy_pt(char *str, t_point pt)
{
	*str = '[';
	str++;
	str = strcpy_int(str, pt.x);
	*str = ',';
	str++;
	*str = ' ';
	str++;
	str = strcpy_int(str, pt.y);
	*str = ']';
	str++;
	return (str);
}
