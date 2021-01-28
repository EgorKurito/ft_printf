/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 22:01:27 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/20 22:01:28 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_zero(t_format *data, int length)
{
	int	zeroes_len;

	zeroes_len = data->precision - length;
	ft_putchar_n('0', zeroes_len);
	if (zeroes_len > 0)
		return (zeroes_len);
	return (0);
}

static int		ft_space(t_format *data, int length)
{
	int	space_len;

	length = ft_max(length, data->precision);
	space_len = data->width - length;
	if (data->flags & ZERO)
		ft_putchar_n('0', space_len);
	else
		ft_putchar_n(' ', space_len);
	if (space_len > 0)
		return (space_len);
	return (0);
}

int				ft_un_int_type(t_format *data, va_list *argptr)
{
	int		nbr_len;
	size_t	nbr;
	int		length;

	nbr = va_arg(*argptr, unsigned int);
	nbr_len = ft_nbr_len(nbr);
	if (data->precision == 0 && nbr == 0)
		nbr_len = 0;
	length = nbr_len;
	if ((data->flags & MINUS) == 0)
		length += ft_space(data, nbr_len);
	length += ft_zero(data, nbr_len);
	if (!(data->precision == 0 && nbr == 0))
		ft_un_putnbr(nbr, 10, 0);
	if (data->flags & MINUS)
		length += ft_space(data, nbr_len);
	return (length);
}
