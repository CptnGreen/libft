#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;
	
	str = (char *)malloc(sizeof(char) * size);
	if(str)
	{
		i = 0;
		while (i < size)
			str[i++] = '\0';
		return (str);
	}
	else
		return (NULL);
}
