# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 17:43:26 by pmiceli           #+#    #+#              #
#    Updated: 2018/06/14 22:55:08 by mlantonn         ###   ########.fr        #
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
SRCS  = draw/anti_aliasing.c \
		draw/blur.c \
		draw/colors.c \
		draw/draw_image.c \
		draw/draw_pixelated_image.c \
		draw/filters.c \
		draw/get_px_color.c \
		draw/phong_shading.c \
		\
		events/ft_event.c \
		events/ft_keyboard.c \
		events/px_aa.c \
		events/fill_funar_key_event.c \
		events/rotate.c \
		events/translations.c \
		events/translations2.c \
		\
		parser/brackets.c \
		parser/check_error.c \
		parser/get_full_read_file.c \
		parser/get_nb_of_structs.c \
		parser/init_structures.c \
		parser/my_atof.c \
		parser/parse_cameras.c \
		parser/parse_lights.c \
		parser/parse_objects.c \
		parser/parse.c \
		parser/remove_white_spaces.c \
		parser/tools.c \
		\
		vec/compute_ray.c \
		vec/get_normal.c \
		vec/hit.c \
		vec/intersect.c \
		vec/rotate_around_object.c \
		vec/vec_operations.c \
		vec/vec_operations2.c \
		\
		data_init.c \
		exit_all.c \
		main.c

## Objects ##
OBJS = $(SRCS:.c=.o)
OBJS_DIR = ./objs
OBJS_SUB_DIRS = draw events parser vec
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

## Lib dirs ##
LIB_DIR = ./lib
LIBFT_DIR = $(LIB_DIR)/libft
LIBMYSDL_DIR = $(LIB_DIR)/libmysdl
LIBPT_DIR = $(LIB_DIR)/libpt
SDL2_DIR = $(LIB_DIR)/sdl2

## Macros for sdl2 installation ##
MAIN_DIR_PATH = $(shell pwd)
SDL_PATH = $(addprefix $(MAIN_DIR_PATH), /lib/sdl2)
SDL_VER = 2.0.8

## Includes ##
INC = -I ./includes/
SDL2_INC = $(shell sh ./lib/sdl2/bin/sdl2-config --cflags)
LIB_INCS =	-I $(LIBFT_DIR)/includes/ \
			-I $(LIBMYSDL_DIR)/includes/ \
			-I $(LIBPT_DIR)/includes/ \
			$(SDL2_INC)

INCS = $(INC) $(LIB_INCS)

## FLAGS ##
CC = gcc
SDL2_LFLAGS = $(shell sh ./lib/sdl2/bin/sdl2-config --libs)
LFLAGS =	-L $(LIBFT_DIR) -lft \
			-L $(LIBPT_DIR) -lpt \
			-L $(LIBMYSDL_DIR) -lmysdl \
			$(SDL2_LFLAGS) \
			-lm
CFLAGS = #-Wall -Wextra -Werror

MESSAGE = "make[1]: Nothing to be done for 'all'"
DONE_MESSAGE = "\033[032m✓\t\033[032mDONE !\033[0m\
				\n ========================================\n"

## RULES ##

all: SDL2 LIBFT LIBPT MYSDL print_name $(NAME) print_end

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "\033[038;2;255;153;0m⧖	Creating	$@\033[0m"
	@gcc $(CFLAGS) $(INCS) -c $^ -o $@

$(OBJS_DIR):
	@echo "\033[033m➼	\033[033mCreating $(DIR_NAME)'s objects \
	with flag : \033[36m $(CFLAGS)\033[0m"
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(addprefix $(OBJS_DIR)/, $(OBJS_SUB_DIRS))

$(NAME): $(OBJS_DIR) $(OBJS_PRE)
	@echo "\033[033m➼\t\033[033mCreating $(DIR_NAME)'s executable\033[0m"
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJS_PRE) $(LFLAGS)
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

rm_SDL2:
	@rm -rf $(SDL2_DIR)
	@echo "❌\t\033[031mSDL2-$(SDL_VER) removed\033[0m"

re_SDL2: fclean rm_SDL2 all

MODE_DEBUG: change_cflag all

re_MODE_DEBUG: rm_obj MODE_DEBUG

change_cflag:
	@$(eval CFLAGS = -fsanitize=address)

SDL2 :
	@if [ ! -d "./lib/sdl2" ]; then \
		echo "\033[033m⚠\tSDL2 is not installed ! ...\033[0m"; \
		echo "\033[033m➼\tCompiling SDL2-$(SDL_VER) ...\033[0m"; \
		printf "\033[033m\tIn 3 ...\033[0m"; sleep 1; \
		printf "\r\033[033m\tIn 2 ...\033[0m"; sleep 1; \
		printf "\r\033[033m\tIn 1 ...\033[0m"; sleep 1; printf "\n"; \
		curl -OL http://www.libsdl.org/release/SDL2-$(SDL_VER).tar.gz && \
		tar -zxvf SDL2-$(SDL_VER).tar.gz && \
		rm SDL2-$(SDL_VER).tar.gz && \
		mkdir -p $(SDL_PATH) && \
		cd SDL2-$(SDL_VER) && \
			sh configure --prefix=$(SDL_PATH) && \
			make && \
			make install && \
		cd .. && \
		rm -rf SDL2-$(SDL_VER); \
		echo "\033[32m✓\tSDl2-$(SDL_VER) installed !\033[0m"; \
	else \
		echo "\033[032m✓\tSDl2-$(SDL_VER) already installed\033[0m"; \
	fi

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

.PHONY: all clean fclean re rm_obj exe SDL2 LIBFT LIBPT MYSDL rm_SDL2 re_SDL2 \
		MODE_DEBUG re_MODE_DEBUG change_cflag print_name print_end
