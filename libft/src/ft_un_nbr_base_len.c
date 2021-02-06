/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_nbr_base_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:16:24 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/28 08:28:25 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


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
