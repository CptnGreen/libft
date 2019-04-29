#include "libft.h"

/*
** strlcpy: considered to be a safer analogue to strcpy & strncpy
** 1) always null-terminates the result of copying
** 2) unlike strncpy takes full size of the buffer (uncluding '\0')
** 3) src must be null-terminated
*/

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (i);
}
