/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_bc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:02:28 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:37:07 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

static t_point	ft_div_pt(t_point crd, char operand, int nb)
{
	t_point		result;

	result = crd;
	if (operand == '/')
	{
		result.x = crd.x / nb;
		result.y = crd.y / nb;
	}
	else if (operand == '%')
	{
		result.y = crd.y % nb;
		result.x = crd.x % nb;
	}
	return (result);
}

t_point			pt_bc(t_point crd, char operand, int nb)
{
	t_point		result;

	result = crd;
	if (operand == '-')
	{
		result.x = crd.x - nb;
		result.y = crd.y - nb;
	}
	else if (operand == '+')
	{
		result.x = crd.x + nb;
		result.y = crd.y + nb;
	}
	else if (operand == '*')
	{
		result.x = crd.x * nb;
		result.y = crd.y * nb;
	}
	else if (operand == '/' || operand == '%')
		result = ft_div_pt(crd, operand, nb);
	return (result);
}
