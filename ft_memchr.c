#include "libft.h"

/*
** The memchr() function scans the initial n bytes of the
** memory area pointed to by s for the first instance of c.
** Both c and the bytes of the memory area pointed to by s
** are interpreted as unsigned char. The memchr() function
** return a pointer to the matching byte or NULL if the
** character does not occur in the given memory area.
*/

void	*ft_memchr(void const *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (str[i] != c)
	{
		if (i >= n)
			return (NULL);
		i++;
	}
	return (str + i);
}
