# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:44:04 by pmiceli           #+#    #+#              #
#    Updated: 2018/04/25 17:29:33 by pmiceli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = ./srcs/
SRCS_NAME = $(shell ls $(SRCS_DIR) | grep -E ".c")
SRCS = $(addprefix $(SRCDIR), $(SRCS_NAME))
INC = ./includes/
INCS = ./includes/get_next_line.h ./includes/libft.h
OBJS_DIR = ./objets/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c $(INCS)
	@echo "$(CC) $(CFLAGS) -I$(INC) -o $@ -c \033[36m$<\033[37m"
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

del_exe :
	@rm -rf $(NAME)
	@echo "\033[31mrm -rf\033[037m $(NAME)"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "\033[31mrm -rf\033[037m objs from libft"

fclean : clean del_exe

re : fclean all

.PHONY : all clean fclean re
