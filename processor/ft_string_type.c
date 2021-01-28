/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:10:03 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/20 21:10:04 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string_type(t_format *data, va_list *argptr)
{
	char	*str;
	int		len;

	str = va_arg(*argptr, char*);
	if (str == NULL)
		str = NULL_STR;
	len = ft_strlen(str);
	if (data->precision != -1 && len > data->precision)
		len = data->precision;
	if ((data->flags & MINUS) == 0)
	{
		if (data->flags & ZERO)
			ft_putchar_n('0', data->width - len);
		else
			ft_putchar_n(' ', data->width - len);
	}
	write(1, str, len);
	if (data->flags & MINUS)
		ft_putchar_n(' ', data->width - len);
	return (ft_max(len, data->width));
}
