# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 17:43:26 by pmiceli           #+#    #+#              #
#    Updated: 2018/04/26 16:08:59 by mlantonn         ###   ########.fr        #
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
SRCDIR = ./srcs/
SRCNAMES  = draw/draw_image.c \
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

## LIB DIR ##
LIB_DIR = ./lib
LIBFT_DIR = $(LIB_DIR)/libft/
MLX_DIR = $(LIB_DIR)/mlx_sierra/
LIBMYSDL_DIR = $(LIB_DIR)/libmysdl/
LIBPT_DIR = $(LIB_DIR)/libpt/

## Includes ##
INC = ./includes/
INCS = ./includes/rtv1.h
LIB_INCS = $(LIBFT_DIR)/includes/get_next_line.h $(LIBFT_DIR)/includes/libft.h\
		   $(MLX_DIR)/includes/mlx.h

## OBJECTS ##
OBJS_DIR = ./objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCNAMES:.c=.o))

## FLAGS ##
CC = gcc
#CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit
LFLAGS =	-L $(LIBFT_DIR) -lft \
			-L $(MLX_DIR) -lmlx $(MLX_FLAGS) \
			-L $(LIBPT_DIR) -lpt

PRINT = "make[1]: Nothing to be done for 'all'"

all: LIBFT MLX PT MYSDL $(NAME)

change_cflag:
	$(eval CFLAGS = -fsanitize=address)

MODE_DEBUG: change_cflag all

$(NAME): print_name $(OBJS)
	@echo "\033[033m➼\t\033[033mCreating $(DIR_NAME)'s executable\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo "\033[032m✓\t\033[032mDONE !\033[0m"
	@echo "\n ========================================\n"

$(OBJS): $(OBJS_DIR)%.o:$(SRCDIR)%.c $(INCS) $(LIB_INCS)
	@echo "\033[038;2;255;153;0m⧖\tCreating\t$@\033[0m"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

LIBFT: print_libft
	@make -C $(LIBFT_DIR)

MLX: print_mlx
	@make -C $(MLX_DIR)

PT: print_libpt
	@make -C$(LIBPT_DIR)

MYSDL: print_libmysdl
	@make -C $(LIBMYSDL_DIR)

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
	@make -C $(LIBPT_DIR) fclean
	@make -C $(MLX_DIR) fclean
	@make -C $(LIBMYSDL_DIR) fclean

re: fclean all

exe: rm_obj $(NAME)

re_MODE_DEBUG: fclean MODE_DEBUG

ret : clean test

print_name:
	@echo "\033[033m➼\t\033[033mCompiling $(DIR_NAME) ...\033[0m"

print_libft:
	@echo "\033[033m➼\t\033[033mCompiling Libft ...\033[0m"

print_libmysdl:
	@echo "\033[033m➼\t\033[033mCompiling Libmysdl ...\033[0m"

print_libpt:
	@echo "\033[033m➼\t\033[033mCompiling Libpt ...\033[0m"

print_mlx:
	@echo "\033[033m➼\t\033[033mCompiling Mlx_sierra ...\033[0m"

.PHONY: all clean fclean re rm_obj LIBFT MLX PT MYSDL \
		MODE_DEBUG re_MODE_DEBUG change_cflag print_name print_done \
		print_libft print_libmysdl print_libpt print_mlx
