/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:29:27 by mlantonn          #+#    #+#             */
/*   Updated: 2018/05/04 15:34:13 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "structs.h"

# define BUFF_SIZE 4096

char	*get_full_read_file(char *file_name);
/*
**	get_full_read_file() reads entirely the file given in parameter and returns
**	a malloced string of the file.
*/

void	remove_white_spaces(char **str);
/*
**	remove_white_spaces() takes a pointer to a malloced string, and removes all
**	white spaces (' ', '\t', '\n') that are not in quotes.
*/

void	parse_cameras(t_data *data, char *str, int *index);
void	parse_lights(t_data *data, char *str, int *index);
/*
**	parse_cameras(), parse_lights() and parse_objects() initialize the
**	corresponding array in *data with what is written in the string.
*/

int		read_quotes(char *str, char *word, int *index);
/*
**	read_quotes() takes a string and a word, and checks wether the word is
**	at the beginning of the string or not.
*/

double	parse_nb(char *str, int *index);
t_vec	parse_vec(char *str, int *index);
t_color	parse_color(char *str, int *index);
/*
**	parse_nb(), parse_vec() and parse_color() take a string and return either
**	a double, a t_vec, or a t_color that matches what is written in the string.
*/

double	my_atof(const char *str);
/*
**	my_atof() is a reproduction of the atof() function which we are not allowed
**	to use in this school project. It is used to parse floating point numbers.
*/

#endif
