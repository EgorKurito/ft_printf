/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:15:57 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/20 21:15:58 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent_type(t_format *data)
{
	if ((data->flags & MINUS) == 0)
	{
		if (data->flags & ZERO)
			ft_putchar_n('0', data->width - 1);
		else
			ft_putchar_n(' ', data->width - 1);
	}
	write(1, "%", 1);
	if ((data->flags & MINUS))
		ft_putchar_n(' ', data->width - 1);
	if (data->width > 1)
		return (data->width);
	return (1);
}
