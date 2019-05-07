/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:41:26 by slisandr          #+#    #+#             */
/*   Updated: 2019/05/07 21:06:04 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description: The memmove() function copies n bytes from memory area src to
** memory area dest. The memory areas may overlap: copying takes place
** as though the bytes in src are first copied into a temporary array that
** does not overlap src or dest, and the bytes are then copied from the
** temporary array to dest. The memmove() function returns a pointer to dest.
*/

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s != d)
	{
		if (s > d)
			ft_memcpy(d, s, n);
		else if (d > s)
		{
			while (n > 0)
			{
				d[n - 1] = s[n - 1];
				n--;
			}
		}
		return (d);
	}
	else
		return (NULL);
}
