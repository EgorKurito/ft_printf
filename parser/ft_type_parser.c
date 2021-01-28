/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:05:32 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/20 19:05:33 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_parser(t_format *data, const char *s)
{
	char *types;

	types = "cspdiuxXo%";
	while (*types)
	{
		if (*types == *s)
		{
			data->type = *s;
			++data->length;
			return (1);
		}
		++types;
	}
	data->type = '\0';
	return (0);
}
