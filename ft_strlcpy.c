/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:01:23 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/02 21:01:25 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strlcpy: considered to be a safer analogue to strcpy & strncpy
** 1) always null-terminates the result of copying
** 2) unlike strncpy takes full size of the buffer (uncluding '\0')
** 3) src must be null-terminated
*/

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_size;
	size_t		src_size;

	dst_size = ft_strlen(dst) + 1;
	src_size = ft_strlen(src) + 1;
	i = 0;
	if (size == 0)
		return (dst_size - 1);
	else
	{
		while (i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size - 1);
}
