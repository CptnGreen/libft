/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:58:07 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/05 02:33:53 by ak               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strnew() allocates (with malloc(3)) and returns a "fresh" string
** ending with '\0'. Each character of the string is initialized at '\0'.
** If allocation fails function returns NULL.
*/

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * size);
	if (str)
	{
		i = 0;
		while (i < size)
			str[i++] = '\0';
		return (str);
	}
	else
		return (NULL);
}
