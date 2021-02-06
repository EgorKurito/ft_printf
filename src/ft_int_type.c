/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:29:05 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/23 16:01:38 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_sign(t_format *data, t_bool is_neg)
{
	if (is_neg)
		write(1, "-", 1);
	else if (data->flags & PLUS)
		write(1, "+", 1);
	else if (data->flags & SPACCE)
		write(1, " ", 1);
}

static int		ft_prepare(t_format *data, int nbr_len, t_bool is_negative)
{
	int		width;
	int		prec;
	t_bool	spc_sgn;

	spc_sgn = (is_negative || data->flags & PLUS || data->flags & SPACCE);
	if (data->flags & ZERO)
		ft_sign(data, is_negative);
	width = data->width - ft_max(nbr_len, data->precision) - spc_sgn;
	if (width < 1 || (data->flags & MINUS))
		width = 0;
	else
	{
		if (data->flags & ZERO)
			ft_putchar_n('0', width);
		else
			ft_putchar_n(' ', width);
	}
	if ((data->flags & ZERO) == 0)
		ft_sign(data, is_negative);
	prec = data->precision - nbr_len;
	if (prec < 1)
		prec = 0;
	else
		ft_putchar_n('0', prec);
	return (prec + width + spc_sgn);
}

int				ft_int_type(t_format *data, va_list *argptr)
{
	int		nbr_len;
	ssize_t	nbr;
	int		length;
	int		width;

	nbr = va_arg(*argptr, int);
	nbr_len = ft_nbr_len(nbr);
	if (data->precision == 0 && nbr == 0)
		nbr_len = 0;
	length = ft_prepare(data, nbr_len, (nbr < 0));
	if (nbr_len)
		ft_putnbr(nbr);
	length += nbr_len;
	if (data->flags & MINUS)
	{
		width = data->width - length;
		if (width > 0)
		{
			ft_putchar_n(' ', width);
			length += width;
		}
	}
	return (length);
}
