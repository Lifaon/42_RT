/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptfl_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:37:58 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:36:17 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

t_ptfl		ptfl_op(t_ptfl crd1, char operand, t_ptfl crd2)
{
	t_ptfl		result;

	result = ptfl_set(0, 0);
	if (operand == '-')
	{
		result.x = crd1.x - crd2.x;
		result.y = crd1.y - crd2.y;
	}
	else if (operand == '+')
	{
		result.x = crd1.x + crd2.x;
		result.y = crd1.y + crd2.y;
	}
	else if (operand == '*')
	{
		result.x = crd1.x * crd2.x;
		result.y = crd1.y * crd2.y;
	}
	else if (operand == '/' && crd2.x != 0 && crd2.y != 0)
	{
		result.x = crd1.x / crd2.x;
		result.y = crd1.y / crd2.y;
	}
	return (result);
}
