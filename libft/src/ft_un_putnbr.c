/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:16:24 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/28 08:28:25 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
