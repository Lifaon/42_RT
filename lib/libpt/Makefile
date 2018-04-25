# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 17:05:18 by fchevrey          #+#    #+#              #
#    Updated: 2018/04/25 18:00:49 by fchevrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpt.a

SRC_C = pt_bc.c pt_op.c ft_putcrd.c pt_set.c pt_swap.c\
		pt_yplus.c pt_ypluseg.c vec_set.c vec_bc.c vec_op.c vec_swap.c  \
		ptfl_bc.c ptfl_op.c ptfl_set.c ptfl_swap.c ptfl_yplus.c ptfl_ypluseg.c \
		ptdb_set.c ptdb_bc.c ptdb_op.c  \

SRC_O = $(SRC_C:.c=.o)

.PHONY: all, clean, fclean, re

INCLUDES = -I includes/ -I ../libft/includes/

CFLAGS = -Wall -Werror -Wextra $(INCLUDES)

CC = gcc

all: $(NAME)

$(NAME): $(SRC_O)
	ar  rc $(NAME) $(SRC_O)
	ranlib $(NAME)

clean:
	rm -f $(SRC_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
