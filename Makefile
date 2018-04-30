# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 17:43:26 by pmiceli           #+#    #+#              #
#    Updated: 2018/04/30 16:30:00 by mlantonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt
DIR_NAME = RT

## color ##
RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
MAG = \033[35m
CYA = \033[36m
EOC = \033[37m

## sources ##
SRCS_DIR = ./srcs/
SRCS  = draw/draw_image.c \
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

## LIB DIR ##
LIB_DIR = ./lib
LIBFT_DIR = $(LIB_DIR)/libft/
MLX_DIR = $(LIB_DIR)/mlx_sierra/
LIBMYSDL_DIR = $(LIB_DIR)/libmysdl/
LIBPT_DIR = $(LIB_DIR)/libpt/
SDL2_DIR = usr/bin/.brew/opt/sdl2

## Includes ##
INC = -I ./includes/
LIB_INCS =	-I $(LIBFT_DIR)/includes/ \
			-I $(MLX_DIR)/includes/ \
			-I $(SDL2_DIR)/includes/SDL2
INCS = $(INC) $(LIB_INCS)

## OBJECTS ##
OBJS = $(SRCS:.c=.o)
OBJS_DIR = objs
OBJS_SUB_DIRS = draw init vec
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

## FLAGS ##
CC = gcc
#CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit
LFLAGS =	-L $(LIBFT_DIR) -lft \
			-L $(MLX_DIR) -lmlx $(MLX_FLAGS) \
			-L $(LIBPT_DIR) -lpt \
			-L $(SDL2_DIR)/lib -lsdl2

MESSAGE = "make[1]: Nothing to be done for 'all'"
DONE_MESSAGE = "\033[032m✓\t\033[032mDONE !\033[0m\
				\n ========================================\n"

all: SDL2 LIBFT MLX PT MYSDL print_name $(NAME) print_end

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "\033[038;2;255;153;0m⧖	Creating	$@\033[0m"
	@gcc $(CFLAGS) $(INCS) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(addprefix $(OBJS_DIR)/, $(OBJS_SUB_DIRS))
	@echo "\033[033m➼	\033[033mCreating $(DIR_NAME)'s objects \
	with flag : \033[36m $(CFLAGS)\033[0m"

$(NAME): $(OBJS_DIR) $(OBJS_PRE)
	@echo "\033[033m➼\t\033[033mCreating $(DIR_NAME)'s executable\033[0m"
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS_PRE)
	@$(eval MESSAGE = $(DONE_MESSAGE))

rm_obj:
	@rm -rf $(OBJS_DIR)
	@echo "❌\t\033[031m$(DIR_NAME)'s objects removed\033[0m"

clean: rm_obj
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBPT_DIR) clean
	@make -C $(MLX_DIR) clean
	@make -C $(LIBMYSDL_DIR) clean

fclean: rm_obj
	@rm -rf $(NAME)
	@echo "❌\t\033[031m$(DIR_NAME)'s executable removed\033[0m"
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) fclean
	@make -C $(LIBPT_DIR) fclean
	@make -C $(LIBMYSDL_DIR) fclean

re: fclean all

exe: rm_obj all

change_cflag:
	@$(eval CFLAGS = -fsanitize=address)

MODE_DEBUG: change_cflag all

re_MODE_DEBUG: fclean MODE_DEBUG

ret : clean test

print_name:
	@echo "\033[033m➼\t\033[033mCompiling $(DIR_NAME) ...\033[0m"

print_end:
	@echo $(MESSAGE)

SDL2:
ifeq ($(shell brew list | grep sdl2), sdl2)
	@echo "\033[032m✓\t\033[032mSDL2 already installed\033[0m"
	@$(eval SDL2_DIR = $(shell brew --prefix sdl2))
else
	@echo "\033[033m➼\t\033[033mInstalling SDL2 ...\033[0m"
	@brew install sdl2
	@echo "\033[032m✓\t\033[032mSDL2 installed\033[0m"
	@$(eval SDL2_DIR = $(shell brew --prefix sdl2))
endif

LIBFT: print_libft
	@make -C $(LIBFT_DIR)

print_libft:
	@echo "\033[033m➼\t\033[033mCompiling Libft ...\033[0m"

MLX: print_mlx
	@make -C $(MLX_DIR)

print_mlx:
	@echo "\033[033m➼\t\033[033mCompiling Mlx_sierra ...\033[0m"

PT: print_libpt
	@make -C$(LIBPT_DIR)

print_libpt:
	@echo "\033[033m➼\t\033[033mCompiling Libpt ...\033[0m"

MYSDL: print_libmysdl
	@make -C $(LIBMYSDL_DIR)

print_libmysdl:
	@echo "\033[033m➼\t\033[033mCompiling Libmysdl ...\033[0m"

.PHONY: all clean fclean re rm_obj LIBFT MLX PT MYSDL \
		MODE_DEBUG re_MODE_DEBUG change_cflag print_name print_done \
		print_libft print_libmysdl print_libpt print_mlx
