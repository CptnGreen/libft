#include "libft.h"

/*
** Description: ft_strmapi() applies the function f to each character of the string
** passed as argument by giving its index as first argument to create a "fresh" new string
** (with malloc(3)) resulting from the successive applications of f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*str;
	unsigned int	i;

	str = ft_strdup(s);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
