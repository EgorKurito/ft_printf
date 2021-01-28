/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:05:15 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/20 19:05:19 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags_parser(t_format *data, const char *s)
{
	const char	*start;

	data->flags = NONE;
	start = s;
	while (*s)
	{
		if (*s == '-')
			data->flags = data->flags | MINUS;
		else if (*s == '+')
			data->flags = data->flags | PLUS;
		else if (*s == '0')
			data->flags = data->flags | ZERO;
		else if (*s == ' ')
			data->flags = data->flags | SPACCE;
		else if (*s == '#')
			data->flags = data->flags | HASH;
		else
			break ;
		s++;
	}
	data->length += s - start;
	return (s - start);
}
