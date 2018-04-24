/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:57:55 by mlantonn          #+#    #+#             */
/*   Updated: 2017/11/27 15:45:46 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024

char	*ft_read_fd(int fd)
{
	char	*buf;
	ssize_t	ret;

	if (!(buf = ft_strnew(BUF_SIZE)))
		return (NULL);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	return (buf);
}
