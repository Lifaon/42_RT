# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 20:02:57 by mlantonn          #+#    #+#              #
#    Updated: 2018/04/24 18:48:29 by mlantonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
MAG = \033[35m
CYA = \033[36m
EOC = \033[37m

NAME = rt
DIR_NAME = RT
LIBFT_DIR = Libft
MLX_DIR = Mlx_macOS

#CFLAGS = -Wall -Wextra -Werror
FMWKS = -framework OpenGL -framework AppKit

LIBS = $(LIBFT) $(LIBMLX)
LIBFT = -L $(LIBFT_DIR) -lft
LIBMLX = -L $(MLX_DIR) -lmlx

INCS = $(INC) $(INCMLX)
INC = -I includes -I $(LIBFT_DIR)/includes
INCMLX = -I $(MLX_DIR)/includes

OBJS = $(SRCS:.c=.o)
OBJS_DIR = objs
OBJS_SUB_DIRS = draw init vec
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

SRCS_DIR = srcs
SRCS =	draw/draw_image.c \
		\
		init/data_init.c \
		init/img_init.c \
		init/t_mlx_init.c \
		\
		vec/get_normal.c \
		vec/intersect.c \
		vec/shadow_ray.c \
		vec/vec_operations.c \
		vec/vec_operations2.c \
		\
		exit_all.c \
		main.c

.PHONY = all $(OBJS_DIR) $(NAME) clean del fclean re

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "gcc $(CFLAGS) $(INCS) -c $^ -o $(CYA)$@$(EOC)"
	@gcc $(CFLAGS) $(INCS) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(addprefix $(OBJS_DIR)/, $(OBJS_SUB_DIRS))

$(NAME): $(OBJS_DIR) $(OBJS_PRE)
	@make -sC $(LIBFT_DIR)
	@make -sC $(MLX_DIR)
	@echo "gcc $(CFLAGS) $(OBJS_PRE) $(LIBS) $(FMWKS) -o $(MAG)$(NAME)$(EOC)"
	@gcc $(CFLAGS) $(OBJS_PRE) $(LIBS) $(FMWKS) -o $(NAME)

del_objs:
	@echo "$(RED)rm -rf$(EOC) $(OBJS_DIR) from $(DIR_NAME)"
	@rm -rf $(OBJS_DIR)

del_exe:
	@echo "$(RED)rm -rf$(EOC) $(NAME)"
	@rm -rf $(NAME)

clean: del_objs
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean del_exe
	@make del_exe -C $(LIBFT_DIR)
	@make del_exe -C $(MLX_DIR)

re: fclean all

exe: del_objs del_exe all
