/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 19:59:48 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/17 21:22:12 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_len(long nbr)
{
	int				count;
	unsigned long	unbr;

	if (nbr == 0)
		return (1);
	count = 0;
	unbr = nbr;
	if (nbr < 0)
	{
		count++;
		unbr = -unbr;
	}
	while (unbr > 0)
	{
		unbr /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(long n)
{
	char			*str;
	int				len;
	int				is_negative;
	unsigned long	unbr;

	len = count_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	is_negative = 0;
	unbr = (unsigned long)n;
	if (n < 0)
	{
		is_negative = 1;
		str[0] = '-';
		unbr = -n;
	}
	len--;
	while (len >= is_negative)
	{
		str[len] = unbr % 10 + '0';
		unbr /= 10;
		len--;
	}
	return (str);
}
