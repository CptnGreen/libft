#include "libft.h"

/*
** Description: ft_striter() applies the function f to each character 
** of the string passed as argument. Each character is passed by address 
** to f to be modified if necessary.
*/

#include <stdio.h>

void	ft_striter(char *s, void (*f)(char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		(*f)(s + i);
		i++;
	}
}
