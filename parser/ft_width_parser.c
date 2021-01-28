/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:05:42 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/20 19:05:45 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width_parser(t_format *data, const char *s, va_list *argptr)
{
	const char	*start;
	int			width;

	if (*s == '*')
	{
		width = va_arg(*argptr, int);
		if (width < 0)
		{
			data->flags = data->flags | MINUS;
			width *= -1;
		}
		data->width = width;
		++data->length;
		return (1);
	}
	start = s;
	data->width = ft_atoii(s);
	while (ft_isddigit(*s))
		++s;
	data->length += s - start;
	return (s - start);
}
