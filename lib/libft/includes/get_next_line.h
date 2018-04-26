/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:58:13 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/25 17:35:04 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define GNL_EOL 1
# define GNL_EOF 0
# define GNL_ERR -1

# define BUFF_SIZE 40000

typedef struct		s_reader
{
	int				ret;
	int				eof;
	char			*bgn;
	char			*end;
	char			buf[BUFF_SIZE];
}					t_reader;

int					get_next_line(const int fd, char **line);

#endif
