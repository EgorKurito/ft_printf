/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:26:31 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/17 21:20:36 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_abs(int i)
{
	return (i >= 0 ? i : -i);
}

long long	ft_llabs(long long ll)
{
	return (ll >= 0 ? ll : -ll);
}

double		ft_fabs(double d)
{
	return (d >= 0 ? d : -d);
}
