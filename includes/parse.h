/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:29:27 by mlantonn          #+#    #+#             */
/*   Updated: 2018/06/04 15:24:31 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "structs.h"
# include "defines.h"
# include "errno.h"

# define BUFF_SIZE 4096
# define FULL_STR_SIZE 81920

char	*get_full_read_file(char *file_name);
/*
**	get_full_read_file() reads entirely the file given in parameter and returns
**	a malloced string of the file.
*/

int		read_quotes(char *str, char *word, int *index);
/*
**	read_quotes() takes a string and a word, and checks wether the word is
**	at the beginning of the string or not.
*/

void	check_error(t_data *data, char *str);
int		brackets(char *str);
/*
**	check_error() checks if the given scene file will crash the program.
**	brackets() checks if brackets in the given file are correctly formated.
*/

void	parse_cameras(t_data *data, char *str, int *index);
int		parse_lights(t_data *data, char *str, int *index);
int		parse_objects(t_data *data, char *str, int *index);
/*
**	parse_cameras(), parse_lights() and parse_objects() initialize the
**	corresponding array in *data with what is written in the string.
*/

void	init_cameras(t_data *data);
void	get_vp_up_left(t_camera *cam);
int		init_lights(t_data *data, int nb);
int		init_objects(t_data *data, int nb);
/*
**	Functions used to initialize the structures and all their variables
**	init_lights() and init_objects() return an int to check if malloc() failed.
*/

int		get_nb_lights(char *str);
int		get_nb_objects(char *str);
/*
**	Functions used to get the numbers of lights and objects in the scene to
**	allocate sufficient memory.
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

void	remove_white_spaces(char **str);
/*
**	remove_white_spaces() takes a pointer to a malloced string, and removes all
**	white spaces (' ', '\t', '\n') that are not in quotes. It is used to test
**	if the parser works with a file without white spaces.
*/

void	exit_all(t_data *data);
/*
**	Frees everything that has to be freed.
*/

t_vec	vec_normalize(t_vec u);

#endif
