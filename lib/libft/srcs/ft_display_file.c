/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:28:28 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/23 16:15:13 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	ft_display_file(char *argv)
{
	int		fd;
	char	buff[25];

	fd = open(argv, O_RDONLY);
	while (read(fd, &buff, 1) != 0)
		write(1, buff, 1);
	close(fd);
}
