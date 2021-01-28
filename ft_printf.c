/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:52:31 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/23 20:02:32 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(const char *format, int *len)
{
	int i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	write(1, format, i);
	*len += i;
	return (i);
}

static int	ft_va_end(va_list *argptr, int res)
{
	va_end(*argptr);
	return (res);
}

int			ft_printf(const char *format, ...)
{
	va_list		argptr;
	t_format	*data;
	int			len;
	int			res;

	len = 0;
	va_start(argptr, format);
	while (*format)
	{
		format += ft_print(format, &len);
		if ((data = ft_parser(format, &argptr)))
		{
			format += data->length;
			if ((res = ft_processor(data, &argptr)) < 0)
				return (ft_va_end(&argptr, res));
			len += res;
		}
		else if (*format)
			return (ft_va_end(&argptr, -1));
	}
	va_end(argptr);
	return (len);
}
