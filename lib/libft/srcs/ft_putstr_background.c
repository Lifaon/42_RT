/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:34:09 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/14 22:41:48 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_background(char *str, char *color)
{
	if (ft_strcmp(color, "black") == 0)
		ft_putstr("\033[40m");
	if (ft_strcmp(color, "red") == 0)
		ft_putstr("\033[41m");
	if (ft_strcmp(color, "green") == 0)
		ft_putstr("\033[42m");
	if (ft_strcmp(color, "yellow") == 0)
		ft_putstr("\033[43m");
	if (ft_strcmp(color, "blue") == 0)
		ft_putstr("\033[44m");
	if (ft_strcmp(color, "pink") == 0)
		ft_putstr("\033[45m");
	if (ft_strcmp(color, "cyan") == 0)
		ft_putstr("\033[46m");
	if (ft_strcmp(color, "grey") == 0)
		ft_putstr("\033[47m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}
