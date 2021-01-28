/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:31:51 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/20 19:31:52 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_atoii(const char *str)
{
	unsigned int	res;

	res = 0;
	while (ft_isddigit(*str))
	{
		res = res * 10 + (*str++ - '0');
	}
	return (res);
}
