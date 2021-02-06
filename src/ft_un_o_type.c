/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_o_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 08:22:26 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/23 08:22:27 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_prepare(t_format *data, int nbr_len, t_bool not_zero)
{
	int		width;
	int		prec;
	t_bool	hash;

	hash = (data->flags & HASH && (not_zero || data->precision == 0));
	width = data->width - ft_max(nbr_len + hash, data->precision);
	if (width < 1 || (data->flags & MINUS))
		width = 0;
	else
		ft_putchar_n((data->flags & ZERO) ? '0' : ' ', width);
	prec = data->precision - nbr_len - hash;
	if (prec < 1)
		prec = 0;
	else
		ft_putchar_n('0', prec);
	if (hash)
		write(1, "0", 1);
	return (prec + width + hash);
}

int				ft_un_o_type(t_format *data, va_list *argptr)
{
	int		nbr_len;
	size_t	nbr;
	int		length;
	int		width;

	nbr = va_arg(*argptr, unsigned int);
	nbr_len = ft_un_nbr_base_len(nbr, 8);
	if (data->precision == 0 && nbr == 0)
		nbr_len = 0;
	length = ft_prepare(data, nbr_len, (nbr != 0));
	if (nbr_len)
		ft_un_putnbr(nbr, 8, 0);
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
