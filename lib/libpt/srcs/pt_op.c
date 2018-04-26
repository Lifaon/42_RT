/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:01:51 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:37:02 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

static t_point	ft_div_pt(t_point crd1, char operand, t_point crd2)
{
	t_point		result;

	result.x = -2147483648;
	result.y = -2147483648;
	if (operand == '/')
	{
		result.x = crd1.x / crd2.x;
		result.y = crd1.y / crd2.y;
	}
	else if (operand == '%')
	{
		result.y = crd1.y % crd2.y;
		result.x = crd1.x % crd2.x;
	}
	return (result);
}

t_point			pt_op(t_point crd1, char operand, t_point crd2)
{
	t_point		result;

	result.x = -2147483648;
	result.y = -2147483648;
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
	else if (operand == '/' || operand == '%')
		result = ft_div_pt(crd1, operand, crd2);
	return (result);
}
