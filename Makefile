# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <pmiceli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 17:43:26 by pmiceli           #+#    #+#              #
#    Updated: 2018/07/23 07:19:16 by mlantonn         ###   ########.fr        #
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
		draw/caustic.c \
		draw/cel_shading.c \
		draw/checkerboard.c \
		draw/colors.c \
		draw/depth_of_field.c \
		draw/draw_image.c \
		draw/draw_pixelated_image.c \
		draw/filters.c \
		draw/get_px_color.c \
		draw/phong_shading.c \
		draw/put_gdk_image.c \
		draw/rainbow.c \
		draw/reflec_refract.c \
		draw/shadows.c \
		draw/perlin.c \
		draw/noise.c \
		draw/get_grad.c \
		draw/perlin_setup.c \
		draw/perlin_calcs.c \
		draw/stereoscopy.c \
		\
		events/ft_event.c \
		events/ft_keyboard.c \
		events/px_aa.c \
		events/get_things.c \
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
		parser/parse_texture.c \
		parser/parse.c \
		parser/read_quotes.c \
		parser/remove_white_spaces.c \
		parser/tools.c \
		\
		vec/compute_ray.c \
		vec/get_normal.c \
		vec/hit.c \
		vec/intersect.c \
		vec/limits.c \
		vec/limits2.c \
		vec/rotate_around_point.c \
		vec/uv_mapping.c \
		vec/vec_operations.c \
		vec/vec_operations2.c \
		\
		ui/json/size_int.c \
		ui/json/size_double.c \
		ui/json/size_vec.c \
		ui/json/size_color.c \
		ui/json/size_of_str_json.c \
		ui/json/fill_str_json.c \
		ui/json/color_toa.c \
		ui/json/my_strcopy.c \
		ui/json/strcpy_int.c \
		ui/json/strcpy_db.c \
		ui/json/strcpy_vec.c \
		ui/json/size_of_object_json.c \
		ui/json/fill_object_spe_json.c \
		ui/json/fill_object_common_json.c \
		ui/create_ui.c \
		ui/create_sub_notebook.c \
		ui/toolbar.c \
		ui/create_light_ui.c \
		ui/create_camera_ui.c \
		ui/create_object_ui.c \
		ui/create_object_ui2.c \
		ui/create_object_file_tex_ui.c \
		ui/create_limited_object_ui.c \
		ui/create_options_ui.c \
		ui/set_wid_data.c \
		ui/create_widgets.c \
		ui/create_widgets2.c \
		ui/modify_light.c\
		ui/modify_light2.c\
		ui/modify_light_caustic.c\
		ui/modify_obj.c\
		ui/modify_obj2.c\
		ui/modify_obj_reflec.c\
		ui/modify_obj_limited.c\
		ui/modify_obj_tex.c\
		ui/modify_obj_tex2.c\
		ui/modify_obj_tex_perlin.c\
		ui/modify_obj_tex_bump.c\
		ui/modify_obj_tex_preset.c\
		ui/modify_obj_type.c \
		ui/modify_options.c\
		ui/modify_options2.c\
		ui/modify_camera.c \
		ui/entry_change_scale.c \
		ui/click_open.c \
		ui/click_save.c \
		ui/click_export.c \
		ui/click_redraw.c \
		ui/join_int.c \
		ui/change_page.c \
		ui/make_two_widget.c \
		ui/wid_vec_new.c \
		ui/free_to_free.c \
		ui/add_vector_choose.c \
		ui/change_vec_from_scale.c \
		ui/check_ui_active.c \
		ui/combobox.c \
		ui/chose_color.c \
		ui/ui_event_tools.c \
		ui/get_double_from_entry.c \
		ui/create_object_texture_ui.c \
		\
		clustering/init_host.c \
		clustering/init_client.c \
		clustering/host_work.c \
		clustering/client_work.c \
		clustering/send_data.c \
		\
		data_init.c \
		exit_all.c \
		main.c

## Objects ##
OBJS = $(SRCS:.c=.o)
OBJS_DIR = ./objs
OBJS_SUB_DIRS = color draw events init parser vec ui ui/json clustering
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

## Lib dirs ##
LIB_DIR = ./lib
LIBFT_DIR = $(LIB_DIR)/libft
LIBMYGTK_DIR = $(LIB_DIR)/libmygtk
LIBPT_DIR = $(LIB_DIR)/libpt

## Macros for sdl2 installation ##
MAIN_DIR_PATH = $(shell pwd)

## Includes ##
INC = -I ./includes/
LIB_INCS =	-I $(LIBFT_DIR)/includes/ \
			-I $(LIBPT_DIR)/includes/ \
			-I $(LIBMYGTK_DIR)/includes/ `pkg-config --cflags gtk+-3.0`

INCS = $(INC) $(LIB_INCS)

## FLAGS ##
CC = gcc
SDL2_LFLAGS = $(shell sh ./lib/sdl2/bin/sdl2-config --libs)
LFLAGS =	-L $(LIBFT_DIR) -lft \
			-L $(LIBPT_DIR) -lpt \
			-L $(LIBMYGTK_DIR) -lmygtk `pkg-config --libs gtk+-3.0` \
			-lm \
			-lpthread \

CFLAGS = #-Wall -Wextra -Werror

MESSAGE = "make[1]: Nothing to be done for 'all'"
DONE_MESSAGE = "\033[032m✓\t\033[032mDONE !\033[0m\
				\n ========================================\n"

## RULES ##

all: LIBFT LIBPT MYGTK print_name $(NAME) print_end

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
	@make -C $(LIBMYGTK_DIR) clean

fclean: rm_obj
	@rm -rf $(NAME)
	@echo "❌\t\033[031m$(DIR_NAME)'s executable removed\033[0m"
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBPT_DIR) fclean
	@make -C $(LIBMYGTK_DIR) fclean

re: fclean all

exe: rm_obj all

MODE_DEBUG: change_cflag all

re_MODE_DEBUG: rm_obj MODE_DEBUG

change_cflag:
	@$(eval CFLAGS = -fsanitize=address)

LIBFT:
	@echo "\033[033m➼\t\033[033mCompiling Libft ...\033[0m"
	@make -C $(LIBFT_DIR)

LIBPT:
	@echo "\033[033m➼\t\033[033mCompiling Libpt ...\033[0m"
	@make -C $(LIBPT_DIR)

MYGTK:
	@echo "\033[033m➼\t\033[033mCompiling Libmygtk ...\033[0m"
	@make -C $(LIBMYGTK_DIR)

print_name:
	@echo "\033[033m➼\t\033[033mCompiling $(DIR_NAME) ...\033[0m"

print_end:
	@echo $(MESSAGE)

.PHONY: all clean fclean re rm_obj exe LIBFT LIBPT \
		MODE_DEBUG re_MODE_DEBUG change_cflag print_name print_end
