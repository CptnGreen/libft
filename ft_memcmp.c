#include "libft.h"

/*
** The memcmp() function compares the first n bytes
** (each interpreted as unsigned char) of the memory
** areas s1 and s2.
*/

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] == str2[i])
	{
		if (i >= n - 1)
			break ;
		i++;
	}
	return (str1[i] - str2[i]);
}
