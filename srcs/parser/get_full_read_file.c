/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_read_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:56:56 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/04 17:22:09 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*perror_and_return_null(void)
{
	perror("Error ");
	return (NULL);
}

static char *read_rest(char *str, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(tmp, buf)))
			return (NULL);
		free(tmp);
	}
	if (ret == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char		*get_full_read_file(char *file_name)
{
	char	buf[BUFF_SIZE + 1];
	char	*str;
	int		fd;
	int		ret;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (perror_and_return_null());
	if ((ret = read(fd, &buf, BUFF_SIZE)) >= 0)
	{
		buf[ret] = '\0';
		if (!(str = ft_strdup(buf)))
			return (perror_and_return_null());
	}
	else
		return (perror_and_return_null());
	if (!(str = read_rest(str, fd)))
		return (perror_and_return_null());
	close(fd);
	return (str);
}
