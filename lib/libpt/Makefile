# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 21:12:58 by pmiceli           #+#    #+#              #
#    Updated: 2018/04/25 21:13:38 by pmiceli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpt.a

## Sources ##
SRCS_DIR = ./srcs/
SRCS_NAME = ft_putcrd.c\
			pt_bc.c\
			pt_op.c\
			pt_set.c\
			pt_swap.c\
			pt_yplus.c\
			pt_ypluseg.c\
			ptdb_bc.c\
			ptdb_op.c\
			ptdb_set.c\
			ptfl_bc.c\
			ptfl_op.c\
			ptfl_set.c\
			ptfl_swap.c\
			ptfl_yplus.c\
			ptfl_ypluseg.c\
			vec_bc.c\
			vec_op.c\
			vec_set.c\
			vec_swap.c

SRCS = $(addprefix $(SRCDIR), $(SRCS_NAME))

## Includes ##
INC = ./includes/
INCS = ./includes/libpt.h

## Objects ##
OBJS_DIR = ./objets/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

## Flags ##
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
	@echo "\033[033m➼	\033[033mCreating Libpt's objects with flag : \033[36m $(CFLAGS)\033[0m"

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c $(INCS)
	@echo "\033[038;2;255;153;0m⧖	Creating	$@\033[0m"
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(NAME) : $(OBJS)
	@echo "\033[032m✓	\033[0m\033[032mLibpt's objects created\033[0m"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[032m✓	\033[0m\033[032mLibpt created\033[0m"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "\033[36m❌	\033[0m\033[31mLibpt's objets removed\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[036m❌	\033[0m\033[31mLibpt removed"

re : fclean all

.PHONY : all clean fclean re
