/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:25:46 by slisandr          #+#    #+#             */
/*   Updated: 2019/04/15 01:32:13 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*get_str_without_prefix(\
		char const *str, unsigned int *j, short *sign);

int					ft_atoi(char const *str)
{
	unsigned int	i;
	short			sign;
	int				res;

	res = 0;
	sign = 1;
	i = 0;
	if (ft_strlen(get_str_without_prefix(str, &i, &sign)) >= 20)
		return ((sign == -1) ? (0) : (-1));
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

static char const	*get_str_without_prefix(\
		char const *str, unsigned int *j, short *sign)
{
	while (str[*j] == '\t' || str[*j] == '\n' || str[*j] == ' ' || \
			str[*j] == '\r' || str[*j] == '\v' || str[*j] == '\f')
		(*j)++;
	if (str[*j] == '-')
	{
		*sign = -1;
		(*j)++;
	}
	else if (str[*j] == '+')
		(*j)++;
	return (str + *j);
}
