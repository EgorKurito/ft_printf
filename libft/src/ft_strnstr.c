/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:50:34 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/17 21:23:25 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t n;

	i = 0;
	n = 0;
	if (needle[n] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + n] && haystack[i + n] == needle[n] && (i + n) < len)
			n++;
		if (needle[n] == '\0')
			return ((char *)(haystack + i));
		else
		{
			n = 0;
		}
		i++;
	}
	return (NULL);
}
