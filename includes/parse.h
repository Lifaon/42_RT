/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:29:27 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/03 23:54:52 by mlantonn         ###   ########.fr       */
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
void	parse_lights(t_data *data, char *str, int *index);
void	parse_objects(t_data *data, char *str, int *index);
void	get_vp_up_left(t_camera *cam);
void	get_dir(t_obj *obj);
/*
**	parse_cameras(), parse_lights() and parse_objects() initialize the
**	corresponding array in *data with what is written in the string.
**	get_vp_up_left() and get_dir() are to call after parsing a cam and an obj.
*/

void	init_cameras(t_data *data);
int		init_lights(t_data *data, int nb);
void	init_one_light(t_data *data, int index);
void	init_one_object(t_data *data, int index);
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
t_point	parse_point(char *str, int *index);
t_vec	parse_vec(char *str, int *index);
t_color	parse_color(char *str, int *index);
void	parse_texture(t_obj *obj, char *str, int *index);
int		check_img_file(char *path, t_obj *obj);
int		add_alpha(t_obj *obj);

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
t_vec	vec_substract(t_vec u, t_vec v);
t_vec	all_rotations(t_vec ray, t_vec angle);
t_color	substract_colors(t_color col1, t_color col2);

#endif
