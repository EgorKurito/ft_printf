/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:53:21 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/23 15:52:35 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define NULL_STR		"(null)"
# define NONE			0b00000000
# define MINUS			0b00000001
# define PLUS			0b00000010
# define SPACCE			0b00000100
# define HASH			0b00001000
# define ZERO			0b00010000

typedef char			t_bool;
typedef struct			s_format
{
	unsigned char		flags;
	unsigned int		width;
	int					precision;
	char				type;
	unsigned int		length;
}						t_format;

int						ft_printf(const char *format, ...);

t_bool					ft_isddigit(char c);
unsigned int			ft_atoii(const char *str);
size_t					ft_strlen(const char *s);
void					ft_putchar_n(int c, int n);
int						ft_max(int first, int second);
int						ft_nbr_len(ssize_t nbr);
int						ft_un_nbr_base_len(size_t nbr, int base);
void					ft_putnbr(ssize_t n);
void					ft_un_putnbr(size_t n, int base, t_bool is_upper);

t_format				*ft_parser(const char *s, va_list *argptr);
int						ft_flags_parser(t_format *data, const char *s);
int						ft_width_parser(t_format *data, const char *s,
										va_list *argptr);
int						ft_precision_parser(t_format *data, const char *s,
										va_list *argptr);
int						ft_type_parser(t_format *data, const char *s);

int						ft_processor(t_format *data, va_list *argptr);
int						ft_char_type(t_format *data, va_list *argptr);
int						ft_string_type(t_format *data, va_list *argptr);
int						ft_percent_type(t_format *data);
int						ft_int_type(t_format *data, va_list *argptr);
int						ft_un_int_type(t_format *data, va_list *argptr);
int						ft_pointer_type(t_format *data, va_list *argptr);
int						ft_un_xx_type(t_format *data, va_list *argptr);
int						ft_un_o_type(t_format *data, va_list *argptr);
int						ft_n_type(va_list *argptr, int global_length);

#endif
