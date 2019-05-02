#include "libft.h"

/*
** Description: The memccpy() function copies no more than n bytes from memory area src 
** to memory area dest, stopping when the character c is found. If the memory areas overlap,
** the results are undefined. The memccpy() function returns a pointer to the next character
** in dest after c or NULL if c was not found in the first n characters of src.
*/

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	size_t		i;
	char		*s;
	char		*d;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (s[i] != c && i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((s[i] == c) ? (d + 1) : (NULL));
}
