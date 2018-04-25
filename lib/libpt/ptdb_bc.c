/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptdb_bc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:11:26 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:36:37 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpt.h"

t_ptdb			ptdb_bc(t_ptdb crd, char operand, double nb)
{
	t_ptdb		result;

	result = ptdb_set(0, 0);
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
