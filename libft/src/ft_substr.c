/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguy <hanguy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:57:08 by hanguy            #+#    #+#             */
/*   Updated: 2020/05/21 20:35:22 by hanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	size;
	size_t			i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) < start || len == 0)
		return (ft_strdup(""));
	size = ft_strlen((char *)s);
	if (start + len > size)
		len = size - start;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
