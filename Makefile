# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/20 18:32:21 by hanguy            #+#    #+#              #
#    Updated: 2020/07/20 18:32:22 by hanguy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = src
SRC_NAME = 	ft_printf.c				\
			ft_flag_parser.c		\
			ft_parser.c				\
			ft_precision_parser.c	\
			ft_type_parser.c		\
			ft_width_parser.c		\
			ft_processor.c			\
			ft_char_type.c			\
			ft_string_type.c		\
			ft_percent_type.c		\
			ft_int_type.c			\
			ft_un_int_type.c		\
			ft_pointer_type.c		\
			ft_un_x_type.c			\
			ft_un_o_type.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I include -I libft/includes
LDFLAGS = -L libft
LDLIBS = -lft

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all clean fclean re libft  clean_libft  fclean_libft  re_libft

all: libft $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c 
	@mkdir -pv $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< $(CFLAGS) -o $@

libft:
	@make -C libft

libft_bonus:
	@make -C libft bonus

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

clean_libft:
	@make -C libft clean

fclean_libft:
	@make -C libft fclean

fclean_ft_printf:
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)

fclean: fclean_ft_printf fclean_libft

re: fclean all

re_libft:
	@make -C libft re

bonus: all
