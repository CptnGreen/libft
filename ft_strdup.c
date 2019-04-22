/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:59:48 by slisandr          #+#    #+#             */
/*   Updated: 2019/04/14 19:25:18 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char	*dup;
	size_t	len;
	int		i;

	i = -1;
	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	dup[len] = '\0';
	while (s1[++i])
		dup[i] = s1[i];
	return (dup);
}
