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

BASE_FILES.O = ft_printf.o

LIB_FILES.O = ft_isddigit.o \
			ft_max.o \
			ft_nbr_len.o \
			ft_un_nbr_base_len.o \
			ft_putchar_n.o \
			ft_putnbr.o \
			ft_un_putnbr.o \
			ft_strlen.o \
			ft_atoii.o \

PARS_FILES.O = ft_flag_parser.o \
			 ft_parser.o \
			 ft_precision_parser.o \
			 ft_type_parser.o \
			 ft_width_parser.o

PROC_FILES.O = ft_processor.o \
			 ft_char_type.o \
			 ft_string_type.o \
			 ft_percent_type.o \
			 ft_int_type.o \
			 ft_un_int_type.o \
			 ft_pointer_type.o \
			 ft_un_x_type.o \
			 ft_un_o_type.o

ALL.O = $(BASE_FILES.O) $(LIB_FILES.O) $(PARS_FILES.O) $(PROC_FILES.O)

all: $(NAME)

$(NAME): all_o
	ar rc $(NAME) $(ALL.O)
	ranlib $(NAME)

all_o: $(BASE_FILES.O) $(LIB_FILES.O) $(PARS_FILES.O) $(PROC_FILES.O)

$(BASE_FILES.O): %.o: %.c includes/ft_printf.h
	gcc -I includes/ -Wall -Wextra -Werror -c $< -o $@

$(LIB_FILES.O): %.o: lib/%.c includes/ft_printf.h
	gcc -I includes/ -Wall -Wextra -Werror -c $< -o $@

$(PARS_FILES.O): %.o: parser/%.c includes/ft_printf.h
	gcc -I includes/ -Wall -Wextra -Werror -c $< -o $@

$(PROC_FILES.O): %.o: processor/%.c includes/ft_printf.h
	gcc -I includes/ -Wall -Wextra -Werror -c $< -o $@

bonus: all

clean:
	rm -rf $(PROC_FILES.O) $(PARS_FILES.O) $(LIB_FILES.O) $(BASE_FILES.O)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all all_o bonus fclean clean re
