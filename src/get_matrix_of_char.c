/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_of_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:34:14 by slisandr          #+#    #+#             */
/*   Updated: 2020/11/02 08:39:15 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**get_matrix_of_char(unsigned int rows, unsigned int cols, char c)
{
	char				**matrix;
	unsigned int		i;
	unsigned int		j;

	if (rows == 0 || \
		!(matrix = (char **)malloc((rows + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = ft_strnew(cols);
		j = 0;
		while (j < cols)
		{
			matrix[i][j] = c;
			j++;
		}
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
