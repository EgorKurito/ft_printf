/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:05:26 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/20 19:05:27 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_precision_parser(t_format *data, const char *s, va_list *argptr)
{
	const char	*start;
	int			precision;

	start = s;
	if (*s++ != '.')
	{
		data->precision = -1;
		return (0);
	}
	if (*s == '*')
	{
		precision = va_arg(*argptr, int);
		if (precision < 0)
			data->precision = -1;
		else
			data->precision = precision;
		data->length += 2;
		return (2);
	}
	data->precision = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	data->length += s - start;
	return (s - start);
}
