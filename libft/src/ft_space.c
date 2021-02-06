/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resther <resther@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 07:12:17 by hanguy            #+#    #+#             */
/*   Updated: 2021/01/17 18:20:35 by resther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		check_space(int c)
{
	if (c == '\n' || c == '\t' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void			ft_space(char *line, int *i)
{
	while (check_space(line[*i]))
		(*i)++;
}

int				ft_isspace(int c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ')
	{
		return (1);
	}
	return (0);
}
