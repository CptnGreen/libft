#include "libft.h"

/*
** Description: ft_strmap() applies the function f to each character of the string 
** given as argument to create a "fresh" new string (with malloc(3)) resulting from 
** the successive application of f
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	int	i;
	char	*str;

	str = ft_strdup(s);
	i = 0;
	while (str[i])
	{
		str[i] = f(s[i]);	
		i++;
	}
	return (str);
}
