/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:24:51 by pmiceli           #+#    #+#             */
/*   Updated: 2018/05/10 00:15:19 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char				*ft_strfjoin(char *str1, char *str2)
{
	char	*join;

	if (!str1 || !str2)
		return (NULL);
	if (!(join = ft_strnew(ft_strlen(str1) + ft_strlen(str2))))
		return (NULL);
	ft_strcpy(join, str1);
	ft_strcat(join, str2);
	free(str1);
	free(str2);
	return (join);
}

static t_reader			*init_reader(void)
{
	t_reader			*reader;

	if (!(reader = (t_reader *)malloc(sizeof(t_reader))))
		return (NULL);
	reader->bgn = reader->buf + BUFF_SIZE;
	reader->end = reader->bgn;
	reader->eof = -1;
	reader->ret = BUFF_SIZE;
	return (reader);
}

int						get_next_line(const int fd, char **line)
{
	static t_reader		*rd[FOPEN_MAX];

	if (fd < 0 || fd > FOPEN_MAX || (!(rd[fd]) && !(rd[fd] = init_reader()))
		|| !line || !(*line = (char *)ft_strnew(0)))
		return (GNL_ERR);
	while (1)
	{
		while (rd[fd]->end < rd[fd]->buf + rd[fd]->ret && *rd[fd]->end != '\n')
			rd[fd]->end++;
		if (!(*line = ft_strfjoin(*line,
				ft_strsub(rd[fd]->bgn, 0, (int)(rd[fd]->end - rd[fd]->bgn)))))
			return (GNL_ERR);
		rd[fd]->bgn = rd[fd]->end + 1;
		if (rd[fd]->end < rd[fd]->buf + rd[fd]->ret && *(rd[fd]->end++) == '\n')
			return (GNL_EOL);
		rd[fd]->end = rd[fd]->buf;
		rd[fd]->bgn = rd[fd]->end;
		if ((rd[fd]->ret = read(fd, rd[fd]->buf, BUFF_SIZE)) == 0)
			return ((rd[fd]->eof++ >= 0 || !ft_strlen(*line))
					? GNL_EOF : GNL_EOL);
		else if (rd[fd]->ret < 0)
			return (GNL_ERR);
	}
}
