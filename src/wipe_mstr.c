/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wipe_mstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@google.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:44:38 by slisandr          #+#    #+#             */
/*   Updated: 2020/03/03 23:00:22 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	wipe_mstr(char **m)
{
	int		i;

	i = 0;
	if (m)
	{
		while (m[i])
		{
			ft_strdel(m + i);
			i++;
		}
		free(m);
		m = NULL;
	}
}
