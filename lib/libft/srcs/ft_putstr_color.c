/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:49:08 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/19 18:58:54 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_color(char *str, char *color)
{
	if (ft_strcmp(color, "black") == 0)
		ft_putstr("\033[30m");
	if (ft_strcmp(color, "red") == 0)
		ft_putstr("\033[31m");
	if (ft_strcmp(color, "green") == 0)
		ft_putstr("\033[32m");
	if (ft_strcmp(color, "yellow") == 0)
		ft_putstr("\033[33m");
	if (ft_strcmp(color, "blue") == 0)
		ft_putstr("\033[34m");
	if (ft_strcmp(color, "pink") == 0)
		ft_putstr("\033[35m");
	if (ft_strcmp(color, "cyan") == 0)
		ft_putstr("\033[36m");
	if (ft_strcmp(color, "grey") == 0)
		ft_putstr("\033[37m");
	if (ft_strcmp(color, "orange") == 0)
		ft_putstr("\033[038;2;255;153;0m");
	if (ft_strcmp(color, "purple") == 0)
		ft_putstr("\033[038;2;154;37;232m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}
