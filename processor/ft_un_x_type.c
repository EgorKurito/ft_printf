/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_x_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:49:17 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/22 17:49:18 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_prepare(t_format *data, int nbr_len, t_bool not_zero)
{
	int		width;
	int		prec;
	int		hash;

	hash = 0;
	if ((data->flags & HASH) && (not_zero || data->precision == 0))
		hash = (nbr_len != 0) ? 2 : 0;
	if (hash && (data->flags & ZERO))
		write(1, (data->type == 'X') ? "0X" : "0x", 2);
	width = data->width - ft_max(nbr_len, data->precision) - hash;
	if (width < 1 || (data->flags & MINUS))
		width = 0;
	else
		ft_putchar_n((data->flags & ZERO) ? '0' : ' ', width);
	if (hash && (data->flags & ZERO) == 0)
		write(1, (data->type == 'X') ? "0X" : "0x", 2);
	prec = data->precision - nbr_len;
	if (prec < 1)
		prec = 0;
	else
		ft_putchar_n('0', prec);
	return (prec + width + hash);
}

int				ft_un_xx_type(t_format *data, va_list *argptr)
{
	int		nbr_len;
	size_t	nbr;
	int		length;
	int		width;

	nbr = va_arg(*argptr, unsigned int);
	nbr_len = ft_un_nbr_base_len(nbr, 16);
	if (data->precision == 0 && nbr == 0)
		nbr_len = 0;
	length = ft_prepare(data, nbr_len, (nbr != 0));
	if (nbr_len)
		ft_un_putnbr(nbr, 16, (data->type == 'X'));
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
