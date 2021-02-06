/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_delimiter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 07:12:17 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/17 21:22:56 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_delimiter(char *s1, char *s2, char del)
{
	char	*str;
	char	*to_free;
	int		total;
	int		i;

	i = 0;
	to_free = s1;
	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2) + 2;
	if (!(str = (char *)malloc(total * sizeof(char))))
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	str[i++] = del;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
