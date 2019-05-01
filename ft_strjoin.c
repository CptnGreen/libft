#include "libft.h"

/*
** Description: ft_strjoin() allocates (with malloc(3)) and returns a "fresh" string
** ending with '\0', result of concatenation of s1 and s2. If the allocation fails
** the function returns NULL.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = ft_strnew(len_s1 + len_s2 + 1);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, len_s1 + len_s2 + 1);
	return (str);
}
