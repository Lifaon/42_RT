/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:36:09 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/07 15:26:39 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_nbr(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap_float(float *a, float *b)
{
	float temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap_char(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap_double(double *a, double *b)
{
	double temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
