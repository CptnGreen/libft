/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 04:43:07 by slisandr          #+#    #+#             */
/*   Updated: 2019/04/16 00:11:22 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ARRAY_SIZE(Value, Length) ((Value < 0) ? (Length + 2) : (Length + 1))

char	*ft_itoa(int n)
{
	int		len;
	int		n_copy;
	char		*str;
	int		i;

	len = 0;
	if (n == 0)
		len = 1;
	else
	{
		n_copy = ABS(n);
		while (n_copy > 0)
		{
			n_copy /= 10;
			len += 1;
		}
	}
	str = (char *)malloc(sizeof(char) * ARRAY_SIZE(n, len));
	str[ARRAY_SIZE(n, len) - 1] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		if (n < 0)
			str[0] = '-';
		n_copy = ABS(n);
		i = ARRAY_SIZE(n, len) - 2;
		while (n_copy > 0)
		{
			str[i] = n_copy % 10 + '0';
			n_copy /= 10;
			i--;
		}
	}
	return (str);
}
