/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptfl_bc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:49:52 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:36:21 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

t_ptfl			ptfl_bc(t_ptfl crd, char operand, float nb)
{
	t_ptfl		result;

	result = ptfl_set(0, 0);
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
	else if (operand == '/' && nb != 0)
	{
		result.x = crd.x / nb;
		result.y = crd.y / nb;
	}
	return (result);
}
