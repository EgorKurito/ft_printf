/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:36:17 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/22 17:36:19 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_un_putnbr(size_t n, int base, t_bool is_upper)
{
	char	*str;

	if (is_upper)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (n / base != 0)
	{
		ft_un_putnbr(n / base, base, is_upper);
	}
	ft_putchar_n(str[n % base], 1);
}
