/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 07:12:17 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/17 21:21:10 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cub_atoi(char *line, int *i)
{
	unsigned long int	res;
	int					sign;

	res = 0;
	sign = 1;
	while (line && (line[*i] == ' ' || (line[*i] >= 9 && line[*i] <= 13)))
		(*i)++;
	if (line[*i] == '+' || line[*i] == '-')
	{
		if (line[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		if (res > 922337203685477580 && sign == 1)
			return (-1);
		else if (res > 922337203685477580 && sign == -1)
			return (0);
		res = res * 10 + (line[*i] - 48);
		(*i)++;
	}
	return ((int)sign * (int)res);
}
