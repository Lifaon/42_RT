# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 17:43:26 by pmiceli           #+#    #+#              #
#    Updated: 2018/04/25 18:56:31 by pmiceli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

## color ##
RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
MAG = \033[35m
CYA = \033[36m
EOC = \033[37m

## sources ##
SRCDIR = ./srcs/
SRCNAMES  = \
			draw/draw_image.c \
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
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))

## Includes ##
INC = ./includes/
INCS = ./includes/rtv1.h
LIB_INCS = ./lib/libft/includes/get_next_line.h ./lib/libft/includes/libft.h\
		   ./lib/Mlx_macOS/includes/mlx.h

## OBJECTS ##
OBJS_DIR = ./objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCNAMES:.c=.o))

## LIB DIR ##
LIBFT_DIR = ./lib/libft/
MLX_DIR = ./lib/Mlx_macOS/

## FLAGS ##
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit
LFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLX_FLAGS)

PRINT = "make[1]: Nothing to be done for 'all'"

all: print_lib LIBFT print_mlx MLX print_name $(NAME) print_done

change_cflag:
	$(eval CFLAGS = -fsanitize=address)

MODE_DEBUG: change_cflag all

print_name:
	@echo "\033[033m➼	\033[033mCompiling $(NAME) ... with flags : \033[36m$(CFLAGS)\033[0m"
	@echo "\033[033m➼	\033[033mCreating $(NAME)'s objetcs\033[0m"

print_lib:
	@echo "\033[033m➼	\033[033mCompiling Libft ...\033[0m"

print_mlx:
	@echo "\033[033m➼	\033[033mCompiling Mlx_macOS ...\033[0m"

print_done:
	@echo $(PRINT)
	@echo "\n ========================================\n"

$(NAME): $(OBJS) LIBFT MLX
	@echo "\033[033m➼	\033[033mCreating $(NAME)'s executable\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)
	@$(eval PRINT ="\033[032m✓	\033[032mDONE !\033[0m")

$(OBJS): $(OBJS_DIR)%.o:$(SRCDIR)%.c $(INCS) $(LIB_INCS)
	@echo "\033[038;2;255;153;0m⧖	Creating 	$@\033[0m"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

LIBFT:
	@make -C $(LIBFT_DIR)

MLX:
	@make -C $(MLX_DIR)

rm_obj:
	@rm -rf $(OBJS_DIR)
	@echo "❌	\033[031mRemouve $(NAME)'s objects\033[0m"

clean: rm_obj
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: rm_obj
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) fclean
	@echo "❌	\033[031mRemouve $(NAME)'s executable\033[0m"

re: fclean all

re_MODE_DEBUG: fclean  MODE_DEBUG

ret : clean test

.PHONY: all fclean clean re MLX LIBFT print_name print_mlx print_done print_lib fclean MODE_DEBUG change_cflag rm_obj
