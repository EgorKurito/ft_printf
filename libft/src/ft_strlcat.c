/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 09:04:27 by hanguy            #+#    #+#             */
/*   Updated: 2020/05/11 15:13:46 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*source;
	size_t		i;
	size_t		dlen;

	dest = dst;
	source = src;
	i = size;
	while (i-- != 0 && *dest)
		dest++;
	dlen = dest - dst;
	i = size - dlen;
	if (i == 0)
		return (dlen + ft_strlen(source));
	while (*source)
	{
		if (i != 1)
		{
			*dest++ = *source;
			i--;
		}
		source++;
	}
	*dest = '\0';
	return (dlen + (source - src));
}
