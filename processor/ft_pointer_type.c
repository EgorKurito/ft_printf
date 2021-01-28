/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 07:59:57 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/21 07:59:58 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_space(t_format *data, int length)
{
	int	space_len;

	length = ft_max(length - 2, data->precision) + 2;
	space_len = data->width - length;
	ft_putchar_n(' ', space_len);
	if (space_len > 0)
		return (space_len);
	return (0);
}

static int		ft_zero(t_format *data, int length)
{
	int	zeroes_len;

	zeroes_len = data->precision - length + 2;
	ft_putchar_n('0', zeroes_len);
	if (zeroes_len > 0)
		return (zeroes_len);
	return (0);
}

int				ft_pointer_type(t_format *data, va_list *argptr)
{
	int		length;
	size_t	p_nbr;
	int		nbr_len;

	p_nbr = (size_t)va_arg(*argptr, void*);
	nbr_len = ft_un_nbr_base_len(p_nbr, 16) + 2;
	if (p_nbr == 0 && data->precision == 0)
		nbr_len = 2;
	length = nbr_len;
	if ((data->flags & MINUS) == 0)
		length += ft_space(data, nbr_len);
	write(1, "0x", 2);
	length += ft_zero(data, nbr_len);
	if (!(p_nbr == 0 && data->precision == 0))
		ft_un_putnbr(p_nbr, 16, 0);
	if (data->flags & MINUS)
		length += ft_space(data, nbr_len);
	return (length);
}
