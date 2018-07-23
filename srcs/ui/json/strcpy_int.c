/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_db.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:51:01 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/29 17:01:24 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*strcpy_int(char *str, int n)
{
	size_t			size;
	size_t			cpy_size;
	unsigned int	nb;

	size = size_int(n);
	cpy_size = size;
	if (n == 0)
		str[--size] = '0';
	nb = (n < 0) ? -n : n;	
	while (--size > 0 && nb)
	{
		str[size] = '0' + (nb % 10);
		nb /= 10;
	}
	str[0] = '0' + nb;
	if (n < 0)
		str[0] = '-';
	str += cpy_size;
	return (str);
}

/*#include <stdio.h>
#include <stdlib.h>
int 	main(void)
{
	char *str;
	char *cpy_str;
	int i = -1;

	str = (char*)malloc(1024);
	cpy_str = str;
	while (++i < 1024)
		str[i] = 'A';
	//str[1] = '\n';
	str = strcpy_int(str, 1);
	str[0] = '\n';
	str++;
	str = strcpy_int(str, 400);
	str[0] = '\n';
	str++;
	str = strcpy_int(str, 3999);
	str[0] = '\n';
	str++;
	str = strcpy_int(str, -5778320);
	str[0] = '\n';
	str++;
	str = strcpy_int(str, 0);
	str[0] = '\n';
	str++;
	str = strcpy_int(str, -2147483648);
	str[0] = '\n';
	str++;
	str = strcpy_int(str, 2147483647);
	str[0] = '\n';
	str++;
	printf("%s\n", cpy_str);
}*/