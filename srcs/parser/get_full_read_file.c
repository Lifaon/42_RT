/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_read_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:56:56 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/02 14:34:57 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*perror_and_return_null(void)
{
	perror("Error ");
	return (NULL);
}

char		*get_full_read_file(char *file_name)
{
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;
	int		fd;
	int		ret;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (perror_and_return_null());
	if ((ret = read(fd, &buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(str = ft_strdup(buf)))
			return (perror_and_return_null());
	}
	while ((ret = read(fd, &buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(tmp, buf)))
			return (perror_and_return_null());
		free(tmp);
	}
	close(fd);
	return (str);
}
