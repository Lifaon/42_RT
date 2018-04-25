# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 17:05:18 by fchevrey          #+#    #+#              #
#    Updated: 2018/04/25 18:03:13 by fchevrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmysdl.a

SRC_C = get_color.c texture_new.c free_tex.c pt_to_tex.c fill_tex_in_color.c \
		lst_tex_new.c free_all_tex.c add_new_tex.c lst_tex_srch.c \
		trace_line_tex.c put_tex_to_win.c win_new.c free_win.c

SRC_O = $(SRC_C:.c=.o)

USER = $(shell id -un)

INCLUDE = -I includes/ -I ../libpt/includes  -I ../libft/includes \
	-I /Users/$(USER)/.brew/Cellar/sdl2/2.0.8/include/SDL2
#INCLUDE = -I ../SDL2/SDL2-2.0.8/include/ -I ../includes/

CFLAGS = -Wall -Werror -Wextra $(INCLUDE)

CC = gcc

all: $(NAME)

$(NAME): $(SRC_O)
	ar rc $(NAME) $(SRC_O)
	ranlib $(NAME)

clean:
	rm -f $(SRC_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, all
