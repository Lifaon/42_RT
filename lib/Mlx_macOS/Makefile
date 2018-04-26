# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 15:52:44 by mlantonn          #+#    #+#              #
#    Updated: 2018/04/25 18:55:30 by pmiceli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
MAG = \033[35m
CYA = \033[36m
EOC = \033[37m

NAME = libmlx.a
DIR_NAME = Mlx_macOS

CFLAGS = -O2

INC = -I $(INC_DIR)
INC_DIR = includes

OBJC = $(SRCSC:.c=.o)
OBJM = $(SRCSM:.m=.o)
OBJS = $(OBJC) $(OBJM)
OBJS_DIR = objs
OBJS_DIRC = $(OBJS_DIR)/c
OBJS_DIRM = $(OBJS_DIR)/m
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

SRCS_DIRC = srcs/c
SRCSC =	c/mlx_shaders.c \
		c/mlx_xpm.c \
		c/mlx_int_str_to_wordtab.c
SRCS_DIRM = srcs/m
SRCSM =	m/mlx_new_window.m \
		m/mlx_init_loop.m \
		m/mlx_new_image.m

.PHONY = all $(OBJS_DIR) $(NAME) clean del_exe del_objs fclean re

all: $(NAME)

$(OBJS_DIRC)/%.o: $(SRCS_DIRC)/%.c
	@echo "\033[038;2;255;153;0m⧖	Creating	$@\033[0m"
	@gcc $(CFLAGS) $(INC) -c $^ -o $@

$(OBJS_DIRM)/%.o: $(SRCS_DIRM)/%.m
	@echo "\033[038;2;255;153;0m⧖	Creating	$@\033[0m"
	@gcc $(CFLAGS) $(INC) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIRC)
	@mkdir -p $(OBJS_DIRM)
	@echo "\033[033m➼	\033[033mCreating Mlx_macOS's objects with flag : \033[36m $(CFLAGS)\033[0m"

$(NAME): $(OBJS_DIR) $(OBJS_DIRC) $(OBJS_DIRM) $(OBJS_PRE)
	@echo "\033[032m✓	\033[0m\033[032mMlx_macOS's objects created\033[0m"
	@ar rc $(NAME) $(OBJS_PRE)
	@ranlib $(NAME)
	@echo "\033[032m✓	\033[0m\033[032mMlx_macOS created\033[0m"

clean:
	@echo "\033[36m❌	\033[0m\033[31mMlx_macOS's objets removed\033[0m"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "\033[036m❌	\033[0m\033[31mMlx_macOS removed"
	@rm -rf $(NAME)

re: fclean all

exe: del_objs del_exe all
