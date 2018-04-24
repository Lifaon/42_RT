/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:36:34 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 16:26:32 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define OPEN_MAX 10

char	*ft_join_free(char *t, char *buf, int rf)
{
	char		*tmp;

	buf[rf] = '\0';
	tmp = t;
	t = ft_strjoin(t, buf);
	ft_strdel(&tmp);
	return (t);
}

char	*ft_take_rest(char *t)
{
	char	*tmp;

	tmp = t;
	t = ft_strsub(ft_strchr(t, X), 1, ft_strlen(ft_strchr(t, X)) - 1);
	ft_strdel(&tmp);
	return (t);
}

char	*ft_dup_zero(char *t)
{
	char	*tmp;

	tmp = t;
	t = ft_strdup("\0");
	ft_strdel(&tmp);
	return (t);
}

int		take_line(char **line, char *buf, const int fd)
{
	static char	*stock[OPEN_MAX];
	int			rf;

	SS = (!SS) ? ft_strdup("\0") : SS;
	while ((rf = read(fd, buf, BUFF_SIZE)) && !(ft_strchr(buf, X)))
	{
		if (rf == -1)
			return (-1);
		SS = ft_join_free(SS, buf, rf);
	}
	SS = ft_join_free(SS, buf, rf);
	if (ft_strchr(SS, X))
	{
		*line = ft_strsub(SS, 0, ft_strlen(SS) - ft_strlen(ft_strchr(SS, X)));
		SS = ft_take_rest(SS);
		return (1);
	}
	if (SS[0] != '\0')
	{
		*line = ft_strjoin(SS, buf);
		SS = ft_dup_zero(SS);
		return (1);
	}
	ft_strdel(&SS);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret_val;

	if (fd < 0 || fd > OPEN_MAX || line == NULL)
		return (-1);
	ret_val = take_line(line, buf, fd);
	return (ret_val);
}
