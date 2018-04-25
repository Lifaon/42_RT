/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 19:49:08 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:35:50 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

static t_vector		ft_div_pt(t_vector crd1, char operand, t_vector crd2)
{
	t_vector		result;

	result = vec_set(0, 0, 0);
	if (crd2.x == 0 || crd2.y == 0 || crd2.z == 0)
		return (result);
	if (operand == '/')
	{
		result.x = crd1.x / crd2.x;
		result.y = crd1.y / crd2.y;
		result.z = crd1.z / crd2.z;
	}
	else if (operand == '%')
	{
		result.y = crd1.y % crd2.y;
		result.x = crd1.x % crd2.x;
		result.z = crd1.z % crd2.z;
	}
	return (result);
}

t_vector			vec_op(t_vector crd1, char operand, t_vector crd2)
{
	t_vector		result;

	result = vec_set(0, 0, 0);
	if (operand == '-')
	{
		result.x = crd1.x - crd2.x;
		result.y = crd1.y - crd2.y;
		result.z = crd1.z - crd2.z;
	}
	else if (operand == '+')
	{
		result.x = crd1.x + crd2.x;
		result.y = crd1.y + crd2.y;
		result.z = crd1.z + crd2.z;
	}
	else if (operand == '*')
	{
		result.x = crd1.x * crd2.x;
		result.y = crd1.y * crd2.y;
		result.z = crd1.z * crd2.z;
	}
	else if (operand == '/' || operand == '%')
		result = ft_div_pt(crd1, operand, crd2);
	return (result);
}
