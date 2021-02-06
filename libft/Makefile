# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: resther <resther@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 13:32:33 by hanguy            #+#    #+#              #
#    Updated: 2021/01/17 17:59:47 by resther          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = ../include/libft.h
FLAG = -Wall -Wextra -Werror
OPTION = -c

S_SRCS = ft_strlen \
	ft_memset \
	ft_bzero \
	ft_memcpy \
	ft_memccpy \
	ft_memmove \
	ft_memchr \
	ft_memcmp \
	ft_strlcpy \
	ft_strlcat \
	ft_strchr \
	ft_strrchr \
	ft_atoi \
	ft_atol \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_toupper \
	ft_tolower \
	ft_strnstr \
	ft_strncmp \
	ft_calloc \
	ft_strdup \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_split \
	ft_split_once \
	ft_itoa \
	ft_strmapi \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	get_next_line \
	ft_space \
	ft_num_len \
	ft_cub_atoi \
	ft_lstnew \
	ft_lstadd_front \
	ft_lstsize \
	ft_lstlast \
	ft_lstadd_back \
	ft_lstdelone \
	ft_lstclear \
	ft_lstiter \
	ft_lstmap \
	ft_strcpy_bonus \
	ft_strcat_bonus \
	ft_abs_bonus \
	ft_char_count \
	ft_strcmp \
	ft_strjoin_delimiter \
	ft_haschr \
	ft_strjoin_doublefree \
	ft_strjoin_free \
	ft_putstr \
	ft_putchar \
	ft_strnew \
	ft_strndup \
	ft_hasnchar \
	is_num		\
	ft_strpbkr  \
	ft_max		\
	ft_nbr_len	\
	ft_putchar_n \
	ft_putnbr \
	ft_un_nbr_base_len \
	ft_un_putnbr

SS_SRCS = $(addsuffix .c, $(S_SRCS))
SRCS = $(addprefix src/, $(SS_SRCS))

OBJS = $(SRCS:.c=.o)

BIN = $(addsuffix .o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c $(HEADER)
	@gcc -c -Wall -Werror -Wextra -I ../include/ $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
