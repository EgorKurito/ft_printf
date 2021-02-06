/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbkr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:14:53 by resther           #+#    #+#             */
/*   Updated: 2021/01/17 21:23:28 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MIN_INT -2147483648
#define MAX_INT 2147483647

int	ft_strpbkr(const char *s, const char *s2)
{
	char	*ptr;
	char	*ptr2;
	int		index_min;
	int		i;
	int		j;

	index_min = MAX_INT;
	if (!s || !s2)
		return (0);
	ptr = (char *)s;
	ptr2 = (char *)s2;
	i = -1;
	while (ptr2[++i])
	{
		j = -1;
		while (ptr[++j])
			if (ptr[j] == ptr2[i])
				if (j <= index_min)
					index_min = j;
	}
	if (index_min < MAX_INT)
		return (index_min);
	return (0);
}
