/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:38:49 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/17 21:22:38 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (d != s)
	{
		while (n--)
		{
			*d++ = *s;
			if (*(unsigned char *)s == (unsigned char)c)
				return ((void *)d);
			s++;
		}
	}
	return (NULL);
}
