/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:34:06 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/20 20:34:07 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_processor(t_format *data, va_list *argptr)
{
	int		len;
	char	type;

	type = data->type;
	len = 0;
	if (type == 'c')
		len = ft_char_type(data, argptr);
	if (type == 's')
		len = ft_string_type(data, argptr);
	if (type == '%')
		len = ft_percent_type(data);
	if (type == 'd' || type == 'i')
		len = ft_int_type(data, argptr);
	if (type == 'u')
		len = ft_un_int_type(data, argptr);
	if (type == 'o')
		len = ft_un_o_type(data, argptr);
	if (type == 'x' || type == 'X')
		len = ft_un_xx_type(data, argptr);
	if (type == 'p')
		len = ft_pointer_type(data, argptr);
	free(data);
	return (len);
}
