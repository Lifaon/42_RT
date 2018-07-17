# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchevrey <fchevrey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 17:05:18 by fchevrey          #+#    #+#              #
#    Updated: 2018/07/17 13:55:42 by fchevrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmygtk.a

DIR_NAME = Libmygtk

SRCS_DIR = ./srcs/

SRCS_NAME = put_widgets_in_new_win.c \
		get_label_of_radio_list.c \
		get_color_gtk.c \
		put_pixelbuf_to_widget.c \
		pixelbuf_new.c \
		pixelbuf_free.c \
		pt_to_pixelbuf.c \
		get_color_of_img.c \
		fill_img_in_color.c \
		scale_pxb.c \
		fill_pixelbuf_in_color.c

SRCS = $(addprefix $(SRC_DIR), $(SRCS_NAME))

## Objects ##
OBJS_DIR = ./objets/

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

## Includes ##
GTK_INC = `pkg-config --cflags gtk+-3.0`

INC =	$(GTK_INC)\
		-I ./includes/ \
		-I ../libft/includes/ \
		-I ../libpt/includes/

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all : $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
	@echo "\033[033m➼	\033[033mCreating $(DIR_NAME)'s objects with flag : \033[36m $(CFLAGS)\033[0m"

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@echo "\033[038;2;255;153;0m⧖	Creating	$@\033[0m"
	@$(CC) $(CFLAGS) $(INC)  -o $@ -c $<

$(NAME) : $(OBJS)
	@echo "\033[032m✓	\033[0m\033[032m$(DIR_NAME)'s objects created\033[0m"
	@ar rc $(NAME) $(OBJS) #`pkg-config --libs gtk+3.0`
	@ranlib $(NAME)
	@echo "\033[032m✓	\033[0m\033[032m$(NAME) created\033[0m"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "\033[36m❌	\033[0m\033[31m$(DIR_NAME)'s objets removed\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[036m❌	\033[0m\033[31m$(NAME) removed\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
