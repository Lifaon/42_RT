# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 17:05:18 by fchevrey          #+#    #+#              #
#    Updated: 2018/05/09 14:11:40 by mlantonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmysdl.a
DIR_NAME = Libmysdl

## Sources ##
SRCS_DIR = ./srcs/
SRCS_NAME = get_color.c texture_new.c free_tex.c pt_to_tex.c fill_tex_in_color.c \
		lst_tex_new.c free_all_tex.c add_new_tex.c lst_tex_srch.c \
		trace_line_tex.c put_tex_to_win.c win_new.c free_win.c

SRCS = $(addprefix $(SRCDIR), $(SRCS_NAME))

SDL2_PATH = $(shell brew --prefix sdl2)/include

## Includes ##
INC = ./includes/ -I ../libft/includes/ -I ../libpt/includes/ \
	-I $(SDL2_PATH)/
#	-I /Users/$(USER)/.brew/Cellar/sdl2/2.0.8/include/

INCS = ./includes/libmysdl.h ../libpt/includes/libpt.h \
	../libft/includes/libft.h $(SDL2_PATH)/SDL2/SDL.h

## Objects ##
OBJS_DIR = ./objets/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

## Flags ##
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
	@echo "\033[033m➼	\033[033mCreating $(DIR_NAME)'s objects with flag : \033[36m $(CFLAGS)\033[0m"

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@echo "\033[038;2;255;153;0m⧖	Creating	$@\033[0m"
	@$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

$(NAME) : $(OBJS)
	@echo "\033[032m✓	\033[0m\033[032m$(DIR_NAME)'s objects created\033[0m"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[032m✓	\033[0m\033[032m$(NAME) created\033[0m"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "\033[36m❌	\033[0m\033[31m$(DIR_NAME)'s objets removed\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[036m❌	\033[0m\033[31m$(NAME) removed"

re : fclean all

.PHONY : all clean fclean re
