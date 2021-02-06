/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 07:12:17 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/17 21:23:00 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char		*dest;

	if (s1 && s2)
	{
		if (!(dest = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		ft_strcpy(dest, s1);
		ft_strcat(dest, s2);
		free(s1);
		return (dest);
	}
	else
		return (NULL);
}
