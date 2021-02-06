/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:57:34 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/20 18:57:35 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_parser(const char *s, va_list *argptr)
{
	t_format	*data;

	if (*s != '%')
		return (NULL);
	s++;
	if ((data = (t_format *)malloc(sizeof(t_format))))
	{
		data->length = 1;
		s += ft_flags_parser(data, s);
		s += ft_width_parser(data, s, argptr);
		if ((data->flags & ZERO) && (data->flags & MINUS))
			data->flags = data->flags & (~ZERO);
		s += ft_precision_parser(data, s, argptr);
		if (ft_type_parser(data, s) == 0)
		{
			free(data);
			return (NULL);
		}
		if (data->precision != -1)
			data->flags = data->flags & (~ZERO);
	}
	return (data);
}
