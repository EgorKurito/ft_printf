/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:38:38 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/20 20:38:39 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_type(t_format *data, va_list *argptr)
{
	int c;

	c = va_arg(*argptr, int);
	if ((data->flags & MINUS) == 0)
		ft_putchar_n(' ', data->width - 1);
	write(1, &c, 1);
	if (data->flags & MINUS)
		ft_putchar_n(' ', data->width - 1);
	if (data->width == 0)
		return (1);
	return (data->width);
}
