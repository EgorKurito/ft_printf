/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:13:56 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/17 21:22:44 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (d != s)
		while (n-- > 0)
			*d++ = *s++;
	return (dst);
}
