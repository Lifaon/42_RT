# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 15:52:44 by mlantonn          #+#    #+#              #
#    Updated: 2018/04/05 17:34:29 by mlantonn         ###   ########.fr        #
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
	@echo "gcc $(CFLAGS) $(INC) -c $^ -o $(CYA)$@$(EOC)"
	@gcc $(CFLAGS) $(INC) -c $^ -o $@

$(OBJS_DIRM)/%.o: $(SRCS_DIRM)/%.m
	@echo "gcc $(CFLAGS) $(INC) -c $^ -o $(CYA)$@$(EOC)"
	@gcc $(CFLAGS) $(INC) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIRC)
	@mkdir -p $(OBJS_DIRM)

$(NAME): $(OBJS_DIR) $(OBJS_DIRC) $(OBJS_DIRM) $(OBJS_PRE)
	@echo "ar rc $(YEL)$(NAME)$(EOC) $(OBJS_PRE)"
	@ar rc $(NAME) $(OBJS_PRE)
	@echo "ranlib $(YEL)$(NAME)$(EOC)"
	@ranlib $(NAME)

del_objs:
	@echo "$(RED)rm -rf$(EOC) $(OBJS_DIR) from $(DIR_NAME)"
	@rm -rf $(OBJS_DIR)

del_exe:
	@echo "$(RED)rm -rf$(EOC) $(NAME)"
	@rm -rf $(NAME)

clean: del_objs

fclean: clean del_exe

re: fclean all

exe: del_objs del_exe all
