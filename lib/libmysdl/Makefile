# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 17:05:18 by fchevrey          #+#    #+#              #
#    Updated: 2018/04/26 16:47:11 by pmiceli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmysdl.a

## Sources ##
SRCS_DIR = ./srcs/
SRCS_NAME = get_color.c texture_new.c free_tex.c pt_to_tex.c fill_tex_in_color.c \
		lst_tex_new.c free_all_tex.c add_new_tex.c lst_tex_srch.c \
		trace_line_tex.c put_tex_to_win.c win_new.c free_win.c

SRCS = $(addprefix $(SRCDIR), $(SRCS_NAME))

## Includes ##
INC = ./includes/
INCS = ./includes/libmysdl.h 

## Objects ##
OBJS_DIR = ./objets/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

## Flags ##
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
	@echo "\033[033m➼	\033[033mCreating Libmysdl's objects with flag : \033[36m $(CFLAGS)\033[0m"

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c $(INCS)
	@echo "\033[038;2;255;153;0m⧖	Creating	$@\033[0m"
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(NAME) : $(OBJS)
	@echo "\033[032m✓	\033[0m\033[032mLibmysdl's objects created\033[0m"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[032m✓	\033[0m\033[032mLibmysdl created\033[0m"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "\033[36m❌	\033[0m\033[31mLibmysdl's objets removed\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[036m❌	\033[0m\033[31mLibmysdl removed"

re : fclean all

.PHONY : all clean fclean re
