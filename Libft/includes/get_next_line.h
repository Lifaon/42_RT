/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:36:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 16:27:36 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 500
# define X '\n'
# define SS stock[fd]

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		get_next_line(const int fd, char **line);

#endif
