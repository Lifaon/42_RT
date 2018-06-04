/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_read_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:56:56 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/04 15:48:41 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*print_error(char *str, char *error)
{
	if (str)
		free(str);
	ft_putstr("Error : ");
	ft_putendl(error);
	return (NULL);
}

char		*get_full_read_file(char *file_name)
{
	char	buf[BUFF_SIZE + 1];
	char	*str;
	int		fd;
	int		ret;
	int		current_size;

	str = NULL;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (print_error(str, strerror(errno)));
	if (!(str = (char *)malloc(sizeof(char) * (FULL_STR_SIZE + 1))))
		return (print_error(str, strerror(errno)));
	current_size = 0;
	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		current_size += ret;
		if (current_size <= FULL_STR_SIZE)
			str = ft_strcat(str, buf);
		else
			return (print_error(str, "File too big."));
	}
	if (ret)
		return (print_error(str, strerror(errno)));
	close(fd);
	return (str);
}
