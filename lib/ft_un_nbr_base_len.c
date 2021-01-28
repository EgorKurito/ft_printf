/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_nbr_base_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:28:40 by hanguy            #+#    #+#             */
/*   Updated: 2020/07/22 17:28:41 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_un_nbr_base_len(size_t nbr, int base)
{
	int	len;

	len = 1;
	while (nbr / base != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
