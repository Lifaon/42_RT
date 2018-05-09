# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 17:43:26 by pmiceli           #+#    #+#              #
#    Updated: 2018/05/09 20:15:39 by mlantonn         ###   ########.fr        #
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

## Sources ##
SRCS_DIR = ./srcs
SRCS  = draw/draw_image.c \
		\
		events/ft_event.c \
		events/ft_keyboard.c \
		events/fill_funar_key_event.c \
		events/ft_mouse.c \
		events/ft_mouse_wheel.c \
		\
		init/data_init.c \
		\
		parser/get_full_read_file.c \
		parser/my_atof.c \
		parser/parse_cameras.c \
		parser/parse_lights.c \
		parser/parse_objects.c \
		parser/parse.c \
		parser/remove_white_spaces.c \
		parser/tools.c \
		\
		vec/get_normal.c \
		vec/intersect.c \
		vec/shadow_ray.c \
		vec/vec_operations.c \
		vec/vec_operations2.c \
		\
		exit_all.c \
		main.c

## Objects ##
OBJS = $(SRCS:.c=.o)
OBJS_DIR = ./objs
OBJS_SUB_DIRS = draw events init parser vec
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

## Lib dirs ##
LIB_DIR = ./lib
LIBFT_DIR = $(LIB_DIR)/libft
LIBMYSDL_DIR = $(LIB_DIR)/libmysdl
LIBPT_DIR = $(LIB_DIR)/libpt
SDL2_DIR = $(LIB_DIR)/sdl2

## Includes ##
INC = -I ./includes/

LIB_INCS =	-I $(LIBFT_DIR)/includes/ \
			-I $(LIBMYSDL_DIR)/includes/\
			-I $(LIBPT_DIR)/includes/\
			-I $(SDL2_DIR)/include

INCS = $(INC) $(LIB_INCS)

## FLAGS ##
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit
LFLAGS =	-L $(LIBFT_DIR) -lft \
			-L $(LIBPT_DIR) -lpt \
			-L $(LIBMYSDL_DIR) -lmysdl \
			-L $(SDL2_DIR)/lib -lSDL2

MESSAGE = "make[1]: Nothing to be done for 'all'"
DONE_MESSAGE = "\033[032m✓\t\033[032mDONE !\033[0m\
				\n ========================================\n"

SDL_VER = 2.0.8
MAIN_DIR_PATH = $(shell pwd)
SDL2_DIR = $(MAIN_DIR_PATH)/lib/sdl2
SDL2_STATUS = installed

all: LIBFT LIBPT MYSDL print_name $(NAME) print_end

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
	@make -C $(LIBMYSDL_DIR) clean

fclean: rm_obj
	@rm -rf $(NAME)
	@echo "❌\t\033[031m$(DIR_NAME)'s executable removed\033[0m"
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBPT_DIR) fclean
	@make -C $(LIBMYSDL_DIR) fclean

re: fclean all

exe: rm_obj all

MODE_DEBUG: change_cflag all

re_MODE_DEBUG: fclean MODE_DEBUG

change_cflag:
	@$(eval CFLAGS = -fsanitize=address)

SDL2_old:
ifeq ($(shell brew list | grep sdl2), sdl2)
	@$(eval SDL2_DIR = $(shell brew --prefix sdl2))
else
	@echo "\033[033m⚠\t\033[033mSDL2 is not installed !\033[0m"
	@echo "\033[033m➼\t\033[033mInstalling SDL2 ...\033[0m"
	@brew install sdl2
	@echo "\033[032m✓\t\033[032mSDL2 installed\033[0m"
	@$(eval SDL2_DIR = $(shell brew --prefix sdl2))
endif

SDL2 : check_sdl2 install_sdl2

check_sdl2:
	test -d lib/sdl2
	echo "salut"

install_sdl2:
ifeq ($(SDL2_STATUS), installed)
	@echo "sbleh"
else
	@echo "pas sbleh"
endif

LIBFT:
	@echo "\033[033m➼\t\033[033mCompiling Libft ...\033[0m"
	@make -C $(LIBFT_DIR)

LIBPT:
	@echo "\033[033m➼\t\033[033mCompiling Libpt ...\033[0m"
	@make -C$(LIBPT_DIR)

MYSDL:
	@echo "\033[033m➼\t\033[033mCompiling Libmysdl ...\033[0m"
	@make -C $(LIBMYSDL_DIR)

print_name:
	@echo "\033[033m➼\t\033[033mCompiling $(DIR_NAME) ...\033[0m"

print_end:
	@echo $(MESSAGE)

.PHONY: all clean fclean re rm_obj exe SDL2 LIBFT LIBPT MYSDL \
		MODE_DEBUG re_MODE_DEBUG change_cflag print_name print_end
