/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:16:24 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/17 21:20:59 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LONG_MIN -2147483648
#define LONG_MAX 2147483647

static int	checker(const char **str)
{
	int is_negative;

	while (**str == ' ' || **str == '\t' || **str == '\n'
			|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
	is_negative = 0;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			is_negative = 1;
		(*str)++;
	}
	return (is_negative);
}

long		ft_atol(const char *str)
{
	unsigned long	nb;
	int				i;
	int				is_negative;

	is_negative = checker(&str);
	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!is_negative && nb > (unsigned long)LONG_MAX)
			return (1);
		else if (nb > (unsigned long)LONG_MIN)
			return (0);
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	if (is_negative)
		return (-nb);
	else
		return (nb);
}
