# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:44:01 by mlantonn          #+#    #+#              #
#    Updated: 2018/04/05 16:08:21 by mlantonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
MAG = \033[35m
CYA = \033[36m
EOC = \033[37m

NAME = libft.a
DIR_NAME = Libft

CFLAGS = -Wall -Wextra -Werror

INC = -I $(INC_DIR)
INC_DIR = includes

OBJS = $(SRCS:.c=.o)
OBJS_DIR = objs
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

SRCS_DIR = srcs
SRCS =	ft_abs.c \
		ft_arrdel.c \
		ft_atoi_base.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_pow.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putnbr_endl.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_read_fd.c \
		ft_realloc.c \
		ft_showarr.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c

.PHONY = all $(OBJS_DIR) $(NAME) clean del_exe del_objs fclean re

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "gcc $(CFLAGS) $(INC) -c $^ -o $(CYA)$@$(EOC)"
	@gcc $(CFLAGS) $(INC) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJS_PRE)
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
