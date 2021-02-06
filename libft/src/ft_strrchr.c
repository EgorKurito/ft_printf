/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:34:14 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/17 21:23:30 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	len;

	len = 0;
	str = (char *)s;
	len = (int)ft_strlen(s);
	if (c == '\0')
		return (str + len);
	while (len--)
		if (*(str + len) == (char)c)
			return (str + len);
	return (NULL);
}
