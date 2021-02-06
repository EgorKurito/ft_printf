/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_doublefree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 07:12:17 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/17 21:22:58 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_doublefree(char *s1, char *s2)
{
	char		*dest;

	if (!(dest = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	free(s2);
	return (dest);
	return (NULL);
}
